#pragma once

template <typename T> struct DataNode
{
	T data;
	DataNode<T>* next;
};


template <typename T> class LinkedList
{
private:
	DataNode<T>* head, * tail;
	int lengthOfList = 0;

public:

	LinkedList() { head = tail = nullptr; }

	// Methods
	void Add(T const data);
	int Length(bool const print = false);
	void Print();
	void TailPrint();
	void Remove(int const elementPosition);
	T Pop();

};
