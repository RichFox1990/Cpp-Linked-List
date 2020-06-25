#include "LinkedList.h"
#include <iostream>
#include <string>

template <class T>
void LinkedList<T>::Insert (T const data, int const insertPosition)
{
	if ((insertPosition > lengthOfList) || (insertPosition < 0))
	{
		std::cout << " ERROR: You entered a position larger than the size of your list + 1. The current length of the list is: " << lengthOfList << std::endl;
		return;
	}

	else
	{
		DataNode<T>* newData = new DataNode<T>;

		newData->data = data;
		newData->next = nullptr;

		if (insertPosition == 0) // change the Head node
		{
			if (head == NULL)
			{
				head = newData;
				tail = newData;
				lengthOfList++;
			}

			else
			{
				newData->next = head;
				head = newData;
				lengthOfList++;
			}
		}

		else if (insertPosition == lengthOfList)
		{
			tail->next = newData;
			tail = newData;
			lengthOfList++;
		}

		else
		{
			DataNode<T>* previous = head;
			DataNode<T>* current = head->next;

			for (int i = 1; i < insertPosition; i++)
			{
				previous = previous->next;
				current = current->next;
			}

			previous->next = newData;
			newData->next = current;
			lengthOfList++;
		}
		std::cout << "Added '" << data << "' to the list at position " << insertPosition << std::endl;
	}
}

template <class T>
void LinkedList<T>::Push(T const data)
{
	Insert(data, 0);
}

template <class T>
void LinkedList<T>::Append(T const data)
{
	Insert(data, lengthOfList);
}

template <class T>
int LinkedList<T>::Length(bool const print)
{
	if (print)
		std::cout << "There are " << lengthOfList << " elements in the list." << std::endl;

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

	else if ((elementPosition > lengthOfList - 1) || (elementPosition < 0))
	{
		std::cout << "ERROR: Element passed is outside the range of the list. Reference starts at '0' : The number of elements in the list: " << lengthOfList << std::endl;
		return;
	}

	else if (elementPosition == 0)
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

		int currentElement = 1;

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
void LinkedList<T>::Pop(T &data)
{
	data = tail->data;
	if (head->next != nullptr)
	{
		
		int currentElement = 1;

		DataNode<T>* previous = head;

		while (currentElement != lengthOfList - 1)
		{
			previous = previous->next;
			currentElement++;
		}

		delete tail;
		lengthOfList--;
		tail = previous;
		tail->next = nullptr;
		std::cout << "i popped the data '" << data << "' from the end of the list.\n" << std::endl;
	}
	else if (lengthOfList == 1)
	{
		delete tail;
		head = tail = nullptr;
		lengthOfList--;
		std::cout << "i grabbed the data :" << data << " : from the end of my list then deleted it from the list.\n" << std::endl;
	}
	else
	{
		std::cout << "ERROR: The list has no data to delete - Pop Failed" << lengthOfList << std::endl;
	}
}