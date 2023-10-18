//_________________________________________________________
LEETCODE 01
//_________________________________________________________

class Solution {
public:
    bool isValid(string s) {
        stack<char> emptyStack; // create an empty stack to store the opening brackets
        if(s[0] == ')' || s[0] == '}' || s[0] == ']') // check if the string starts from the closing bracket
        {
            return false;
        }
        for(char c : s) // loop through each character in the string
        {
            if(c == '(' || c == '{' || c == '[') // if the character is the opening bracket
            {
                emptyStack.push(c);// push it onto the empty stack
            }
            else // if the character is the closing bracket
            {
                if (emptyStack.empty() || // if the stack is empty or
                (c == ')' && emptyStack.top() != '(') || // the closing bracket doesn't match the opening bracket at the top of the stack
                (c == '}' && emptyStack.top() != '{') || 
                (c == ']' && emptyStack.top() != '['))
                {
                    return false; // the string is not valid, so return false
                }
                else
                {
                    emptyStack.pop(); // otherwise remove the opening bracket from the stack
                }
            }
        }
        return emptyStack.empty(); // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
                           // so the string is valid, otherwise, there are unmatched opening brackets, so return false
    }
};

//_________________________________________________________
LEETCODE 02
//_________________________________________________________

class MinStack {
public:
    stack<int> minStack; // create an empty stack to store the values
    MinStack() {
        int val;// initialize the values
    }
    
    void push(int val) {
        minStack.push(val); // push the values in the stack
    }
    
    void pop() {
        minStack.pop(); // remove the top value from the stack
    }
    
    int top() {
        return minStack.top(); // returns the top value of the stack
    }
    
    int getMin() {
        int minvalue = 10000; // initializes a variable to get 1st minimum value by comparing with it and stores the minimum value
        int value; // variable that stores the top value of the stack
        for(int i =0; i<=minStack.size(); i++) // loop through each element of the stack
        {
            value = top(); // value stores the top value of the stack
            if(value < minvalue) // checks if value is smaller
            {
                minvalue=value; // if top value is smaller than minvalue stores it
                pop(); // removes the top value from the stack
            }
        }
        return minvalue; // returns the minimumvalue;
    }
};

//_________________________________________________________
LEETCODE 03
//_________________________________________________________

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // initilize the variable with the size of the height vector
        vector<int> left(n), right(n); // create two vectors to store the the maximum left and right height

        left[0] = height[0]; // initially stroes the height of the 0 index bar
        right[n-1] = height[n-1]; // initially stores the height of the most right index bar

        for(int i=1; i<n; i++) // loop moves towards right
        {
            left[i] = max(height[i], left[i-1]); // get the maximum height bar of the left
        }

        for(int i=n-2; i>=0; i--)// loop moves towards left
        {
            right[i] = max(height[i], right[i+1]); // get the maximum height bar of the right
        }
        int trappedWater = 0; // variable that stores the value of the trapped water 
        for(int i=0; i<n; i++) // loop through the size of the height vector
        {
            trappedWater = trappedWater + min(left[i],right[i]) - height[i]; //here the minimum of the maximum heights to the left and right bar subtracts the height of the current bar and adds the trapped water
        }
        return trappedWater; // returns the value of the trapped water
    }
};

//_________________________________________________________
LEETCODE 04
//_________________________________________________________

class Solution {
public:
    string decodeString(string s) 
    {
        stack<string> chars; // create a stack to store the characters
        stack<int> nums; // create a stack to store the numbers
        string res; // variable that stores the characters to repeat
        int num = 0; // the variable that stores character as integer
        for (char c : s) // loop through the each character of the string
        {
            if (isdigit(c)) // checks the character is digit or not
            {
                num =+ (c - '0'); // subtracts the ASCII code of zero from the charater to change it into integer
            } 
            else if (c == '[') // checks is the character is opening bracket
            {
                chars.push(res); // pushes the characters store in the res after the opening bracket into the character stack
                nums.push(num); // pushes the number into the number stack
                res = ""; // again initilize the string null
                num = 0; // again initilize the number to zero
            } 
            else if (c == ']') // checks is the character is closing bracket
            {
                string tmp = res; // new variable stores the characters in the res variable
                res = chars.top(); // res gets the top character of the character stack
                chars.pop(); // removes the top character of the character stack
                for (int i = nums.top(); i > 0; i--) // loop through the number of times to print the character
                {
                    res += tmp; // adds the characters
                }
                nums.pop(); // removes the number from the number stack
            }
            else 
            {
                res += c; // adds the characters to res variable
            }
        }
    return res; // return the characters in the res variable
    }
};

//_________________________________________________________
LEETCODE 06
//_________________________________________________________

class MyStack {
public:
    queue<int>q1,q2;
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        while(q1.size()>0)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.size()>0)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() 
    {
        int x=q1.front();
        q1.pop();
        return x;   
    }
    
    int top() 
    {
       return q1.front();
    }
    
    bool empty() 
    {
       return q1.size()==0; 
    }
};

//_________________________________________________________
LEETCODE 07
//_________________________________________________________

class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) 
    {
        int i=0,cnt=0,j=0,n=stu.size();
        queue<int>dq;
        for(int it:stu)
        {
            dq.push(it);
        }
        while(!dq.empty() && j<n*n)
        {
            if(dq.front()==sand[i])
            {
                i++;
                dq.pop();
            }
            else
            {
                int t=dq.front();
                dq.pop();
                dq.push(t);
            }
            j++;
        }        
        if(dq.empty())
        {
            return 0;
        }
        else 
        {
            return dq.size();
        }
    }
};


