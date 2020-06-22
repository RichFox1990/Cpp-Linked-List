#include "LinkedList.h"
#include <iostream>
#include <string>

template <class T>
void LinkedList<T>::Add (const T data)
{
	DataNode<T>* newData = new DataNode<T>;

	newData->data = data;
	newData->next = nullptr;

	if (head == nullptr)
	{
		head = newData;
		tail = newData;
		lengthOfList++;
		return;
	}

	else
	{
		tail->next = newData;
		tail = tail->next;
		lengthOfList++;
	}
}

template <class T>
int LinkedList<T>::Length(bool const print)
{
	if (print)
		std::cout << "There are " << lengthOfList << " elements in the list." << std::endl; // 

	return lengthOfList;
}

template <class T>
void LinkedList<T>::Print()
{
	if (head == nullptr) // if list is empty
	{
		std::cout << "ERROR: There is no data in the list to print." << std::endl;
		return;
	}
	else
	{
		DataNode<T>* tempHead = head;

		while (tempHead->next != nullptr)
		{
			std::cout << tempHead->data << ", ";
			tempHead = tempHead->next;
		}
		std::cout << tempHead->data << std::endl;
	}
}

template <class T>
void LinkedList<T>::TailPrint()
{
	if (tail != nullptr)
		std::cout << "Last value in the list is: " << tail->data << std::endl;
	else
		std::cout << "ERROR: The list is empty.. Cannot print the last element" << std::endl;
}

template <class T>
void LinkedList<T>::Remove(int const elementPosition) // 1 -> ... lengthOfList.
{
	if (head == nullptr)
	{
		std::cout << "ERROR: The list has no data to delete" << lengthOfList << std::endl;
		return;
	}

	else if ((elementPosition > lengthOfList) || (elementPosition < 1))
	{
		std::cout << "ERROR: You requested an number outside the range of the list. The size of the list is: " << lengthOfList << std::endl;
		return;
	}

	else if (elementPosition == 1)
	{
		if (lengthOfList > 1)
		{
			DataNode<T>* toDelete = head;
			head = head->next;

			delete toDelete;
			std::cout << "Removed the 1st element from the list" << std::endl;
			lengthOfList--;
			return;
		}
		else
		{
			delete head;
			std::cout << "Removed the 1st element from the list. The list is now empty" << std::endl;
			head = tail = nullptr;
			lengthOfList--;
		}
	}

	else
	{

		int currentElement = 2;

		DataNode<T>* previous = head;

		while (currentElement != elementPosition)
		{
			previous = previous->next;
			currentElement++;
		}

		DataNode<T>* toDelete = previous->next;

		previous->next = toDelete->next;

		if (previous->next == nullptr) // if we are deleting the last Datanode - set tail to the previous node)
		{
			tail = previous;
		}

		delete toDelete;
		std::cout << "Removed the element in position " << currentElement << " from the list." << std::endl;
		lengthOfList--;

	}
}

template <class T>
T LinkedList<T>::Pop()
{
	T poppedData = tail->data;

	if (head->next != nullptr)
	{
		int currentElement = 2;

		DataNode<T>* previous = head;

		while (currentElement != lengthOfList)
		{
			previous = previous->next;
			currentElement++;
		}

		delete tail;
		lengthOfList--;
		tail = previous;
		tail->next = nullptr;
	}
	else if (lengthOfList == 1)
	{
		delete tail;
		head = tail = nullptr;
		lengthOfList--;
	}
	else
	{
		std::cout << "ERROR: The list has no data to delete - Pop Failed" << lengthOfList << std::endl;
	}

	return poppedData;
}