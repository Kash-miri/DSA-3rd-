__________________________________________________________________
__________________________________________________________________

RECURSIVE FUNCTIONS
__________________________________________________________________
__________________________________________________________________


Question 01 part 01
_________________________________________________________
int recursiveFunction(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num + recursiveFunction(num - 1);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 01 part 02
_________________________________________________________
int recursiveFunction(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num + recursiveFunction(num - 2);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 01 part 03
_________________________________________________________
int recursiveFunction(int num)
{
    if (num == 0)
    {
        return 1;
    }
    return 2 * recursiveFunction(num - 1);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 01 part 04
_________________________________________________________
int recursiveFunction(int num)
{
    if (num == 0)
    {
        return 1;
    }
    return 3 * recursiveFunction(num - 1);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 01 part 05
_________________________________________________________
int recursiveFunction(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num + recursiveFunction(num / 3);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 01 part 06
_________________________________________________________
int recursiveFunction(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num + recursiveFunction(num / 2);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 02 part 01
_________________________________________________________
int recursiveFunction(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return (recursiveFunction(num / 2) * 10) + (num % 2);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 02 part 02
_________________________________________________________
string recursiveFunction(int num)
{
    if (num == 1)
    {
        return "1";
    }
    return recursiveFunction(num / 2) + to_string(num % 2);
}

main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    string sum = recursiveFunction(num);
    cout << sum;
}
_________________________________________________________
_________________________________________________________

Question 02 part 03
_________________________________________________________
int recursiveFunction(int num, int num2)
{
    if (num2 == 0)
    {
        return num;
    }
    return recursiveFunction(num2, num % num2);
}

main()
{
    int num, num2;
    cout << "Enter any two numbers: ";
    cin >> num;
    cin >> num2;
    int GCD = recursiveFunction(num, num2);
    cout << GCD;
}
_________________________________________________________
_________________________________________________________

Question 03 part 01
_________________________________________________________
int recursiveFunction(int array[], int num, int index)
{
    if (array[index] != num)
    {
        return recursiveFunction(array, num, index+1);
    }
    return array[index];
}

main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter number: ";
        cin >> array[i];
    }
    int num;
    cout << "Enter the number to search in the array: ";
    cin >> num;
    int index = 0;
    int foundNumber = recursiveFunction(array, num, index);
    cout << foundNumber;
}
_________________________________________________________
_________________________________________________________

Question 03 part 02
_________________________________________________________
int recursiveFunction(int array[], int num, int size)
{
    if (array[size] != num)
    {
        return recursiveFunction(array, num, size-1);
    }
    return array[size];
}

main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter number: ";
        cin >> array[i];
    }
    int num;
    cout << "Enter the number to search in the array: ";
    cin >> num;
    int foundNumber = recursiveFunction(array, num, size);
    cout << foundNumber;
}
_________________________________________________________
_________________________________________________________

Question 03 part 03
_________________________________________________________
int recursiveFunction(int array[], int num, int start, int end)
{
    int mid = (start + end) / 2;
    if (array[mid] == num)
    {
        return mid;
    }
    else if (num < array[mid])
    {
        return recursiveFunction(array, num, start, mid - 1);
    }
    else
    {
        return recursiveFunction(array, num, mid + 1, end);
    }
}

main()
{
    int end;
    int start = 0;
    cout << "Enter the size of the array: ";
    cin >> end;
    int array[end];
    for (int i = 0; i < end; i++)
    {
        cout << "Enter number: ";
        cin >> array[i];
    }
    int num;
    cout << "Enter the number to search in the array: ";
    cin >> num;
    int index = recursiveFunction(array, num, start, end);
    cout << index;
}
_________________________________________________________
_________________________________________________________

Question 04 part 01
_________________________________________________________
int recursiveFunction(int X, int Y)
{
    if (Y == 0)
    {
        return 1;
    }
    return X * recursiveFunction(X, Y - 1);
}

main()
{
    int X, Y, M;
    cout << "Enter power: ";
    cin >> Y;
    cout << "Enter base: ";
    cin >> X;
    cout << "Enter module: ";
    cin >> M;
    int power = recursiveFunction(X, Y);
    int mode = power % M;
    cout << mode;
}
_________________________________________________________
_________________________________________________________

Question 04 part 02
_________________________________________________________
int recursiveFunction(int X, int Y, int M)
{
    if (Y == 0)
    {
        return 1;
    }

    int temp = recursiveFunction(X, Y / 2, M);
    int result = (temp * temp) % M;

    if (Y % 2 == 1)
    {
        result = (result * X) % M;
    }

    return result;
}

main()
{
    int X, Y, M;
    cout << "Enter base (X): ";
    cin >> X;
    cout << "Enter exponent (Y): ";
    cin >> Y;
    cout << "Enter modulus (M): ";
    cin >> M;

    int result = recursiveFunction(X, Y, M);
    cout << "Result: " << result << endl;
}
_________________________________________________________
_________________________________________________________

Question 05 part 01
_________________________________________________________
int addFunction(int num1, int num2)
{
    return num1 + num1;
}

int multiplyFunction(int num1, int num2)
{
    int count = 0;
    if (num2 == 0 || num1 == 0)
    {
        return 0;
    }
    if (num2 == 1)
    {
        return num1;
    }
    if (num1 == 1)
    {
        return num2;
    }
    if (num1 == 1 && num2 == 1)
    {
        return 1;
    }
    if(count <= num2)
    {
        count++;
        return addFunction(num1, num2);
    }
}

main()
{
    int num1, num2;
    cout << "Enter number: ";
    cin >> num1;
    cout << "Enter number: ";
    cin >> num2;
    int multiple = multiplyFunction(num1, num2);
    cout << "A*B: " << multiple;
}
_________________________________________________________
_________________________________________________________

Question 06 part 01
_________________________________________________________
int recursiveFunctionDivision(int num1, int num2)
{
    if (num1 < num2)
    {
        return 0;
    }
    return 1 + recursiveFunctionDivision(num1 - num2, num2);
}
int recursiveFunctionMode(int num1, int num2)
{
    if (num1 < num2)
    {
        return num1;
    }
    else
    {
        return recursiveFunctionMode(num1 - num2, num2);
    }
}

main()
{
    int num1, num2;
    cout << "Enter number: ";
    cin >> num1;
    cout << "Enter number: ";
    cin >> num2;
    int division = recursiveFunctionDivision(num1, num2);
    cout << "A/B: " << division << endl;
    int mode = recursiveFunctionMode(num1, num2);
    cout << "A%B: " << mode;
}
_________________________________________________________
_________________________________________________________

Question 07 part 01
_________________________________________________________
int recursion(int size)
{
    if (size <=1)
    {
        return size;
    }
    return recursion(size - 1) + recursion(size - 2);
}

int loop(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        array[i + 2] = array[i] + array[i + 1];
    }
    return array[size];
}

main()
{
    int array[] = {0, 1};
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int sum1 = loop(array, size);
    cout << "Sum of the series by loop: " << sum1 << endl;
    int sum2 = recursion(size);
    cout << "Sum of the series by recursion: " << sum2;
}
ANALYSES:
Recursive implementation of fibonacci series takes O(2^N) time complexity on the other hand iterative implementation takes O(N) time complexity for the same code. That's why, for fibonacci series iterative approach is better.
_________________________________________________________
_________________________________________________________

Question 07 part 02
_________________________________________________________
vector<int> fib;

int memoization(int size)
{
    if (size <= 1)
    {
        return size;
    }
    if (fib[size] != -1)
    {
        return fib[size];
    }
    fib[size] = memoization(size - 1) + memoization(size - 2);
    return fib[size];
}

main()
{
    int size;
    cout << "Enter the size if the vector: ";
    cin >> size;
    fib.resize(size + 1, -1);
    int sum = memoization(size);
    cout << "Sum of the series: " << sum;
}
_________________________________________________________
_________________________________________________________

Question 07 part 03
_________________________________________________________
int iterative(int array[], int size)
{
    for(int i = 0; i<size; i++)
    {
        array[i+2]= array[i] + array[i+1];
    }
    return array[size];
}

main()
{
    int array[] = {0, 1};
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int sum = iterative(array,size);
    cout << "Sum of the series by tabulation: " << sum;
}
_________________________________________________________
_________________________________________________________

Question 08 part 01
_________________________________________________________
We need to add the 1st 3 terms to generate the next term and so on...
n4 = n1 + n2 + n3;
n5 = n4 + n3 + n2;
so on...
_________________________________________________________
_________________________________________________________

Question 08 part 02
_________________________________________________________
int recursion(int size)
{
    if (size <= 3)
    {
        return size;
    }
    return recursion(size - 1) + recursion(size - 2) + recursion(size - 3);
}

main()
{
    int array[] = {1, 2, 3};
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int sum = recursion(size);
    cout << "Sum of the series by recursion: " << sum;
}
_________________________________________________________
_________________________________________________________

Question 08 part 03
_________________________________________________________
The time complexity for this kind of series is O(3^N).
_________________________________________________________
_________________________________________________________

Question 08 part 04
_________________________________________________________
vector<int> fib;

int memoization(int size)
{
    if (size <= 3)
    {
        return size;
    }
    if (fib[size] != -1)
    {
        return fib[size];
    }
    fib[size] = memoization(size - 1) + memoization(size - 2) + memoization(size - 3);
    return fib[size];
}

main()
{
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    fib.resize(size + 1, -1);
    int sum = memoization(size);
    cout << "Sum of the series by memoization: " << sum;
}
_________________________________________________________
_________________________________________________________

Question 08 part 05
_________________________________________________________
int iterative(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i + 3] = array[i] + array[i + 1] + array[i + 2];
    }
    return array[size];
}

main()
{
    int array[] = {1, 2, 3};
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int sum = iterative(array, size);
    cout << "Sum of the series by tabulation: " << sum;
}
