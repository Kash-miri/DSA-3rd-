#include <iostream>
#include<stack>
#include"Header.h"
#include<string>

using namespace std;

int main() {
    Stack stack;
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;
    std::string postfixExpression = stack.postfix(infixExpression);
    std::string prefixExpression = stack.prefix(infixExpression);
    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;
    std::cout << "Prefix Expression: " << prefixExpression << std::endl;
}


