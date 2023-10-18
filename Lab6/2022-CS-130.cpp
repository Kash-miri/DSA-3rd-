_____________________________________________________________
_____________________________________________________________

LINKED LIST (LAB 06)
_____________________________________________________________
_____________________________________________________________

QUESTION 01
_____________________________________________________________
_____________________________________________________________
#pragma once
#include <iostream>

template<typename T>
class Node {
public:

    // Members of the node
    T data;// data of any type
    Node<T>* next;// creates pointer

    // Constructor of the node class
    Node(T value)
    {
        data = value;// stores the value at the node
        next = nullptr;// points the nullptr
    }
};

template<typename T>
class LinkedList {
    // Members of the linked list
    Node<T>* head;
    Node<T>* tail;
public:
    //Constructor of the linked list
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Checks if the node is empty or not
    bool isEmpty()
    {
        bool flag = false;
        if (head == nullptr && tail == nullptr)
        {
            flag = true;
        }
        return flag;
    }

    // Inserts the new node at the front of the linked list
    void insertAtFront(T value)
    {
        //initilizes the new node
        Node<T>* new_node = new Node<T>(value);
        if (isEmpty())// checks whether the current head nad tail node is empty or not
        {
            head = new_node;// initilize the new node to head
            tail = new_node;// initilize the new node to tail
        }
        else
        {
            new_node->next = head;// initilizes the nullptr with the head
            head = new_node;// points the new node with the head
        }
    }

    // Inserts the new node at the tail of the linked list
    void insertAtEnd(T value)
    {
        //initilizes the new node
        Node<T>* new_node = new Node<T>(value);
        if (isEmpty())// checks whether the current head nad tail node is empty or not
        {
            head = new_node;// initilize the new node to head
            tail = new_node;// initilize the new node to tail
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void insertAtMid(T value)
    {
        Node<T>* new_node = new Node<T>(value);
        if (isEmpty())
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            int count = 0;
            Node<T>* temp = head;

            // Count the number of nodes in the list
            while (temp != nullptr)
            {
                count++;
                temp = temp->next;
            }

            // Reset temp to the head
            temp = head;

            // Find the middle position (integer division)
            int middle = count / 2;

            // Move temp to the node before the middle
            for (int i = 0; i < middle ; i++)
            {
                temp = temp->next;
            }

            // Insert the new_node in the middle
            new_node->next = temp->next;
            temp->next = new_node;

            // Update tail if the count was even
            if (count % 2 == 0)
            {
                tail = new_node;
            }
        }
    }

    void insertAtAfter(T value, T key)
    {
        Node<T>* new_node = new Node<T>(value);
        Node<T>* temp = head;
        if (isEmpty())
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            while (temp->data != key && temp != nullptr)
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void insertBefore(T value, T key)
    {
        Node<T>* new_node = new Node<T>(value);
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        if (isEmpty())
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            while (temp->data != key && temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = new_node;
            new_node->next = temp;
        }
    }

    T getFront()
    {
        if (!isEmpty())
        {
            return head->data;
        }
    }

    T getTail()
    {
        if (!isEmpty())
        {
            return tail->data;
        }
    }

    Node<T>* searchKey(T key)
    {
        Node<T>* temp = head->next;
        if (head->data == key)
        {
            return head;
        }
        else
        {
            while (temp->data != key)
            {
                temp = temp->next;
            }
            return temp;
        } 
    }

    void removeFromFront()
    {
        Node<T>* temp = head;
        if (head == tail)
        {
            delete head;
            delete tail;
           std :: cout << "Null";
        }
        head = head->next;
    }

    void removeFromTail()
    {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        if (head == tail)
        {
            delete head;
            delete tail;
            std::cout << "Null";
        }
        else
        {
            while (temp != tail)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
            tail = prev;
        }
    }

    void removeFromMiddle()
    {
        int count = 0;
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        if (head == tail)
        {
            delete head;
            delete tail;
            std::cout << "Null";
        }
        else
        {
            while (temp != nullptr)
            {
                count++;
                temp = temp->next;
            }
            temp = head;
            int middle = count / 2;
            for (int i = 0; i < middle; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
        }
        
    }

    void display()
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " -----> ";
            temp = temp->next;
        }
        std::cout << "Null" << std::endl;
    }

    
};
_____________________________________________________________
_____________________________________________________________

QUESTION 02
_____________________________________________________________
_____________________________________________________________

STACK

#pragma once
#include<iostream>

template <typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node(T value)
	{
		data = value;
		next = nullptr;
	}
};

template <typename T>
class LinkedList {
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty()
	{
		bool flag = false;
		if (head == nullptr && tail == nullptr)
		{
			flag = true;
		}
		return flag;
	}

	void insertAtEnd(T value)
	{
		Node<T>* new_node = new Node<T>(value);
		if (isEmpty())
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;;
		}
	}

	T removeFromTail()
	{
		Node<T>* temp = head;
		Node<T>* prev = nullptr;
		if (isEmpty())
		{
			return 0;
		}
		else if (head == tail)
		{
			T value = head->data;
			delete head;
			head = nullptr;
			tail = nullptr;
			return value;
		}
		else
		{
			while (temp != tail)
			{
				prev = temp;
				temp = temp->next;
			};
			prev->next = nullptr;
			tail = prev;
			T value = temp->data;
			return value;
		}
	}
};

template <typename T>
class Stack {
	LinkedList<T> S;
public:
	Stack() {
	};

	void push(T value)
	{
		S.insertAtEnd(value);
	}

	T pop()
	{
		return S.removeFromTail();
	}

	bool isEmpty()
	{
		return S.isEmpty();
	}
};

QUEUE

#pragma once
#include<iostream>


template <typename T>
class Node {
public: 
	T data;
	Node<T>* next;
	Node(T value)
	{
		data = value;
		next = nullptr;
	}
};

template <typename T>
class LinkedList {
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty()
	{
		bool flag = false;
		if (head == nullptr && tail == nullptr)
		{
			flag = true;
		}
		return flag;
	}

	void insertAtEnd(T value)
	{
		Node<T>* new_node = new Node<T>(value);
		if (isEmpty())
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
	}

	T removeFromFront()
	{
		if (isEmpty())
		{
			return 0;
		}
		else if (head == tail)
		{
			T value = head->data;
			delete head;
			return value;
		}
		else
		{
			T value = head->data;
			head = head->next;
			return value;
		}
	}
};

template <typename T>
class Queue {
	LinkedList<T> Q;
public:
	Queue(){

	}
	void Enqueue(T value)
	{
		Q.insertAtEnd(value);
	}
	T Dequeue()
	{
		return Q.removeFromFront();
	}
	bool isEmpty()
	{
		return Q.isEmpty();
	}
};
_____________________________________________________________
_____________________________________________________________

QUESTION 03
_____________________________________________________________
_____________________________________________________________
#pragma once
#include<iostream>

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(T value)
	{
		data = value;
		next = nullptr;
	}
};

template <typename T>
class LinkedList {
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void recursiveFunctionToDisplay(Node<T>* temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		std::cout << temp->data << "----->";
		return recursiveFunction(temp->next);
	}
	void display()
	{
		recursiveFunction(head);
		std::cout << "NULL";
	}
	int recursiveCount(Node<T>* temp, int count)
	{
		if (temp == nullptr)
		{
			return count;
		}
		return recursiveCount(temp->next, count + 1);
	}
	Node<T>* recursiveFindMiddle(Node<T>* temp, int start, int middle)
	{
		if (start == middle)
		{
			return temp;
		}
		return recursiveFindMiddle(temp->next, start + 1, middle);
	}
	void findMiddleElement()
	{
		int count = 0;
		int i = recursiveCount(head, count);
		int middle = i / 2;
		int start = 1;
		Node<T>* node = recursiveFindMiddle(head, start, middle);
		std::cout << node->data;
	}
	bool circular(Node<T>* temp)
	{
		bool flag = false;
		if (temp == tail)
		{
			flag = true;
		}
		else
		{
			circular(temp->next);
		}
		return flag;
	}
	void checkList()
	{
		bool flag = circular(head);
		std::cout << flag;
	}
	void circularList(T value)
	{
		Node<T>* new_node = new Node<T>(value);
		if (head == nullptr && tail == nullptr)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = head;
		}
	}
	Node<T>* reverseLinkedList(Node<T>* head)
	{
		Node<T>* current = head;
		Node<T>* prev = nullptr;
		Node<T>* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		return prev;
	}
	void iterative()
	{
		std::cout<<reverseLinkedList(head);
	}

	Node<T>* recursiveReversed(Node<T>* head)
	{
		if (head == nullptr && head->next == nullptr)
		{
			return head;
		}
		Node<T>* newHead = recursiveReversed(head->next);
		Node<T>* headNext = head->next;
		head->next = nullptr;
		return newHead;
	}
};

