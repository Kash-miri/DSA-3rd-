#include<iostream>
#include"Stack.h"
#include"Queueh.h"

using namespace std;

int main()
{
    /*Stack<int> S;
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);
    cout << S.pop();
    cout << S.pop();
    cout << S.pop();
    cout << S.pop();
    cout << S.isEmpty() << endl;*/
    Queue<int> Q;
    Q.Enqueue(5);
    Q.Enqueue(6);
    Q.Enqueue(7);
    Q.Enqueue(8);
    cout << Q.Dequeue();
    cout << Q.Dequeue();
    cout << Q.Dequeue();
    cout << Q.Dequeue();
    cout << Q.isEmpty();
}


