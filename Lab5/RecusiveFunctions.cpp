#include <iostream>
#include <vector>
using namespace std;

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
