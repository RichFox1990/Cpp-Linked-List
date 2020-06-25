#include <iostream>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"


int main()
{
	// example uses
	LinkedList<std::string> myList;
	

	myList.Push("1st");
	myList.Append("3rd");
	myList.Insert("2nd", 1);
	myList.Print();
	myList.TailPrint();

	myList.Remove(3);
	myList.Remove(0);
	myList.Push("1st");
	myList.Print();
	myList.Remove(2);
	myList.Print();
	myList.Append("4th");
	myList.Insert("3rd", 2);
	myList.Print();
	myList.Insert("new", 0);
	myList.Print();
	std::string text;
	myList.Pop(text);

	std::cout << text << std::endl;
	
	myList.Print();

	/*LinkedList<int> numberList;
	numberList.Push(100);
	numberList.Insert(200, 3);
	numberList.Print();
	numberList.TailPrint();*/


	std::cin.get();

	return 0;
}