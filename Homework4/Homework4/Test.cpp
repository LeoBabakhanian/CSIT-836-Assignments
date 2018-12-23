//Leo Babakhanian
//Data Structures- Fall Class
//Professor Agazaryan
//Assignment #4

#include <iostream>
using namespace std;

#include "PersonList.h"

int displayMenu();
void processChoice(int, PersonList&);

int main()
{
	int num;
	PersonList myList;

	do
	{
		num = displayMenu(); 
		//Display menu in do while loop

		if (num != 3) 
			processChoice(num, myList);
		//Process choice

	} while (num != 3); 
	//If user enters 3 the loop exits

	//system("PAUSE");
	return 0;
}

int displayMenu() //Menu function
{
	int choice;
	//Print menu and ask for user input

	cout << "Menu" << endl;
	cout << "==============================" << endl << endl;
	cout << "1. Add student to waiting list" << endl;
	cout << "2. View waiting list" << endl;
	cout << "3. Exit program" << endl << endl;
	cout << "Please enter choice: ";
	cin >> choice;

	//return user input option
	return choice;
}

void processChoice(int choice, PersonList& pList)
{
	switch (choice)
	{
	case 1: 
		pList.AddToList(); 
		//If user enters 1, add student and bribe to list

		break;

	case 2: 
		pList.ViewList(); 
		//If user enters 2, view list of students and bribe amount

		break;
	}
}
