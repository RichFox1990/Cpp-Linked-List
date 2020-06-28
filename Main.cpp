#include <iostream>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"


int main()
{
	// example uses

	//Memory leak check:
	/*std::string name;
	while (std::cin >> name)
	{
		LinkedList<std::string> name;
		for(int i = 0; i < 20; i++)
			name.Push("testing");
	}*/

	LinkedList<std::string> myList;
	std::string text = "";
	myList.Pop(text);
	myList.Push("1st", true);
	myList.Append("3rd", true);
	myList.Insert("2nd", 1, true);
	myList.Print();
	myList.TailPrint();

	myList.Remove(3, true);
	myList.Remove(0, true);
	myList.Push("1st", true);
	myList.Print();
	myList.Remove(2, true);
	myList.Print();
	myList.Pop(true);
	myList.Append("4th", true);
	myList.Insert("3rd", 2, true);
	myList.Print();
	myList.Insert("new", 0, true);
	myList.Print();
	
	myList.Pop(text, true);
	std::cout << "The data stored in my variable 'test' is: " << text << std::endl;
	
	myList.Print();

	/*LinkedList<int> numberList;
	numberList.Push(100);
	numberList.Insert(200, 3);
	numberList.Print();
	numberList.TailPrint();*/


	std::cin.get();

	return 0;
}