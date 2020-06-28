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
	~LinkedList();

	// Methods
	void Push(T const data, const bool print = false);
	void Append(T const data, const bool print = false);
	void Insert(T const data, int const insertPosition = 0, const bool print = false);
	int Length(bool const print = false);
	void Print();
	void TailPrint();
	void Remove(int const elementPosition, const bool print = false);
	void Pop(T &data, const bool print = false);
	void Pop(const bool print = false);

};
