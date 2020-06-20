#include <iostream>
#include <string>
#include <stdio.h>

template <typename T> struct DataNode
{
	T data;
	DataNode<T>* next;
};

template <typename T> class LinkedList
{
private:
	DataNode<T>* head, * tail;
	DataNode<T>* newData = nullptr; 
	int lengthOfList = 0;

public:

	LinkedList()
	{
		head = tail = newData = nullptr;
	}

	// Methods
	void Add(T value)
	{
		newData = new DataNode<T>;

		newData->data = value;
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

	int length(bool print = false)
	{
		if (print)
			std::cout << "There are " << lengthOfList << " elements in the list." << std::endl; // 

		return lengthOfList;
	}

	void Print()
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

	void TailPrint()
	{
		if (tail != nullptr)
			std::cout << "Last value in the list is: " << tail->data << std::endl;
		else
			std::cout << "ERROR: The list is empty" << std::endl;
	}

	void Remove(int elementPosition) // 1 -> ... lengthOfList.
	{
		if (head == nullptr)
		{
			std::cout << "ERROR: The list has no data to delete" << lengthOfList << std::endl;
			return;
		}

		else if ( (elementPosition > lengthOfList) || (elementPosition < 1) )
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

	void Pop()
	{

	}

};





int main()
{

	LinkedList<std::string> myList;
	
	std::string text = "hello";

	myList.Add("testing");
	myList.Add("1");
	myList.Add("2");

	myList.Print();
	myList.length(true);

	myList.Remove(3);
	myList.Print();
	myList.length(true);

	myList.TailPrint();


	myList.Remove(2);
	myList.TailPrint();
	myList.Remove(1);
	myList.TailPrint();
	myList.Print();
	myList.length(true);


	int freeze = 0;
	std::cin >> freeze;

	return 0;
}