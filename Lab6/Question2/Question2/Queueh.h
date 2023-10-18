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