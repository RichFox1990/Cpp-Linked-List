#include <iostream>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"


int main()
{
	// example uses

	LinkedList<std::string> myList;
	std::string text;

	myList.Add("1st");
	myList.Add("2nd");

	myList.TailPrint();

	myList.Remove(1);

	text = myList.Pop();
	std::cout << "i grabbed the data :" << text << " : from the end of my list then deleted it from the list.\n" << std::endl;

	LinkedList<int> numberList;
	numberList.Add(100);
	numberList.Add(200);
	numberList.TailPrint();

	int last = numberList.Pop();
	std::cout << "I removed and stored the last value in my number list : " << last << std::endl;


	int freeze = 0;
	std::cin >> freeze;

	return 0;
}