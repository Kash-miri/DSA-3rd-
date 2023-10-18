#pragma once
#include <iostream>
#include <string>
#include <stack>

class Stack {
private:
    std::stack<char> S;
    std::string str;

public:
    Stack() {
        str = "";
    }

    int getPrecedence(char val) {
        if (val == '+' || val == '-') {
            return 1;
        }
        else if (val == '*' || val == '/') {
            return 2;
        }
        return 0;
    }

    std::string postfix(std::string express) {
        for (int i = 0; i < express.size(); i++) {
            if (express[i] == '(') {
                S.push(express[i]);
            }
            else if (isdigit(express[i])) {
                str += express[i];
            }
            else if (express[i] == '+' || express[i] == '-' || express[i] == '*' || express[i] == '/') {
                while (!S.empty() && getPrecedence(S.top()) >= getPrecedence(express[i])) {
                    str += S.top();
                    S.pop();
                }
                S.push(express[i]);
            }
            else if (express[i] == ')') {
                while (!S.empty() && S.top() != '(') {
                    str += S.top();
                    S.pop();
                }
                if (!S.empty() && S.top() == '(') {
                    S.pop();
                }
            }
        }
        while (!S.empty()) {
            str += S.top();
            S.pop();
        }
        return str;
    }
    std::string prefix(const std::string& infix) {
        std::string reversedInfix = "";
        for (int i = infix.length() - 1; i >= 0; i--) {
            reversedInfix += infix[i];
        }

        for (char& c : reversedInfix) {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }

        std::string reversedPostfix = postfix(reversedInfix);

        std::string prefix = "";
        for (int i = reversedPostfix.length() - 1; i >= 0; i--) {
            prefix += reversedPostfix[i];
        }

        return prefix;
    }

    bool isDigit(char c)
    {
        return (c >= '0' && c <= '9');
    }

    int evaluation(std::string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (isdigit(str[i]))
            {
                S.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                int num1 = S.top();
                S.pop();
                int num2 = S.top();
                S.pop();
                if (str[i] == '+')
                {
                    num1 = num1 + num2;
                }
                else if (str[i] == '-')
                {
                    if (num1 > num2)
                    {
                        num1 = num1 - num2;
                    }
                    num1 = num2 - num1;
                }
                else if (str[i] == '*')
                {
                    if (num1 > num2)
                    {
                        num1 = num1 * num2;
                    }
                    num1 = num2 * num1;
                }
                else if (str[i] == '/')
                {
                    if (num1 > num2)
                    {
                        num1 = num1 / num2;
                    }
                    num1 = num2 / num1;
                }
                S.push(num1);
            }
        }
        return S.top();
    }
};

