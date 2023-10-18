#include <iostream>
#include"Header.h"

using namespace std;


int main()
{
    LinkedList<int> L;
    /*bool flag = L.isEmpty();
    cout << flag<<endl;*/
    L.insertAtEnd(15);
    L.insertAtEnd(25);
    L.insertAtEnd(35);
    L.insertAtEnd(45);
    L.insertAtEnd(55);
    /*L.insertAtFront(15);
    L.insertAtMid(25);
    L.insertAtEnd(35);*/
    /*L.insertAtFront(15);
    L.insertAtEnd(55);
    L.insertAtAfter(65, 55);*/
    /*int front = L.getFront();
    cout << front << endl;*/
    /*int tail = L.getTail();
    cout << tail << endl;*/
    /*Node<int>* search = L.searchKey(45);
    cout << search->data << endl;*/
    /*L.removeFromFront();*/
    /*L.removeFromTail();*/
    /*L.insertAtFront(15);
    L.insertAtEnd(55);
    L.insertBefore(45, 55);
    L.removeFromMiddle();*/
    L.display();
    L.checkList();
}

