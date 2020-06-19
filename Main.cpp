#include <iostream>

struct DataNode
{
	int data;
	DataNode* next;
};

class LinkedList
{
private:
	DataNode* head;
public:

	LinkedList()
	{
		head = nullptr;
	}

	// Methods
	void Add(int value)
	{
		DataNode* newData = new DataNode;

		newData->data = value;
		newData->next = nullptr;

		if (head == nullptr)
		{
			head = newData;
			return;
		}

		else
		{
			DataNode* tempHead = head;

			while (tempHead->next != nullptr)
				tempHead = tempHead->next;

			tempHead->next = newData;
		}
	}

	void Print()
	{
		DataNode* tempHead = head;
		
		if (tempHead != nullptr)
		{
			std::cout << tempHead->data << std::endl;

			while (tempHead->next != nullptr)
			{
				tempHead = tempHead->next;
				std::cout << tempHead->data << std::endl;
			}
		}
	}

	void Remove()
	{

	}


};





int main()
{

	LinkedList myList;
	
	myList.Add(1);
	myList.Add(2);
	myList.Add(3);
	myList.Add(4);
	myList.Add(5);

	myList.Print();

	int freeze = 0;
	std::cin >> freeze;

	return 0;
}