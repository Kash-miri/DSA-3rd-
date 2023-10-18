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
            for (int i = 0; i < middle; i++)
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
