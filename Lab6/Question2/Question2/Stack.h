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



