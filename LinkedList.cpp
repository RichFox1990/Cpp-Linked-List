#include "LinkedList.h"
#include <iostream>
#include <string>

template <class T>
void LinkedList<T>::Insert (T const data, int const insertPosition, const bool print)
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
		if (print)
			std::cout << "Added '" << data << "' to the list at position " << insertPosition << std::endl;
	}
}

template <class T>
void LinkedList<T>::Push(T const data, const bool print)
{
	Insert(data, 0, print);
}

template <class T>
void LinkedList<T>::Append(T const data, const bool print)
{
	Insert(data, lengthOfList, print);
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
	if (lengthOfList < 1) // if list is empty
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
		std::cout << "ERROR: The list is empty." << std::endl;
}

template <class T>
void LinkedList<T>::Remove(int const elementPosition, const bool print) // 1 -> ... lengthOfList.
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
			if (print)
				std::cout << "Removed the 1st element from the list" << std::endl;
			lengthOfList--;
		}
		else
		{
			delete head;
			if (print)
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
		if (print)
			std::cout << "Removed the element in position " << currentElement << " from the list." << std::endl;
		lengthOfList--;

	}
}

template <class T>
void LinkedList<T>::Pop(const bool print)
{
	Remove(lengthOfList - 1);

	if (print)
		std::cout << "The last element in the list was deleted" << std::endl;
}

template <class T>
void LinkedList<T>::Pop(T &data, const bool print)
{
	if (lengthOfList < 1)
	{
		std::cout << "ERROR: The list has no data to delete - Pop Failed" << std::endl;
		return;
	}

	else
	{
		data = tail->data;
		Remove(lengthOfList - 1);
		if (print)
			std::cout << "i grabbed the data '" << data << "' from the end of the list, stored it in the variable provided and then deleted it from the list.\n" << std::endl;
	}
}


template <class T>
LinkedList<T>::~LinkedList()
{
	std::cout << "Destroying all elements in the list..." << std::endl;

	if (head == NULL)
	{
		std::cout << "There was no nodes to remove... All data is removed" << std::endl;
	}
	else
	{
		std::cout << "The length of the list is: " << lengthOfList << std::endl;

		int counter = 0;
		while (lengthOfList != 0)
		{
			Remove(0);
			counter++;
		}
		
		std::cout << counter << " nodes were deleted from the heap. \n\nAll nodes removed." << std::endl;
	}
}