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

	/*void recursiveFunctionToDisplay(Node<T>* temp)
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
	}*/
	/*bool circular(Node<T>* temp)
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
	}*/
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
};

