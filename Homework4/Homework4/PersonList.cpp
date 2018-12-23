//Leo Babakhanian
//Data Structures- Fall Class
//Professor Agazaryan
//Assignment #4

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "PersonList.h"

PersonList::PersonList() //Constructor
{
	head = NULL;
	//Set head to 0
}

PersonList::~PersonList() //Destructor, when program ends
{
	PersonRec *currPtr = head, *tmp;
	//Declare pointer to currPtr and tmp

	while (currPtr != NULL)
	{
		tmp = currPtr->link;
		delete currPtr;
		currPtr = tmp;
		//delete currPtr and set it equal to 0
	}
}

void PersonList::AddToList() //Add function
{
	string name;
	int bribe;

	//Prompt for user to enter name and contribution
	cout << "Enter the person's name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter the person's contribution: ";
	cin >> bribe;

	PersonRec *node, *currPtr = head;
	node = new PersonRec;

	//assign values accordingly
	node->student = name;
	node->money = bribe;
	node->link = NULL;


	//If else statement
	//Check to see if input of bribe amount is greater or equal to 0
	if (head == NULL || head->money < bribe)
	{
		node->link = head;
		head = node;
		//Set assigned to 0
		return;
	}
	else
	{
		//while statement, if not equal to 0
		while (currPtr->link != NULL && currPtr->link->money >= bribe)
		{

			currPtr = currPtr->link;
		}
		//assign new values to pointers
		node->link = currPtr->link;
		currPtr->link = node;
	}
	//Sorts the list to then be used by viewlist
}

void PersonList::ViewList() //View list function
{
	PersonRec *currPtr = head;
	int count;

	if (currPtr == NULL)
	{
		cout << "List is empty" << endl;
		//If currPtr is 0, say list is empty
		return;
	}

	//Display Student/Bribe amount
	////////////////////////////////////////////////////////
	//No formatting needed - Test case works for this menu//
	////////////////////////////////////////////////////////
	cout << "# Name Contribution" << endl;
	cout << "=======================================" << endl;

	//Set count to 1
	count = 1;

	//While statement, currPtr is not equal to 0
	//Display student and money amount
	while (currPtr != NULL)
	{
		cout << count << " " << currPtr->student << " $" << currPtr->money << endl;
		//Display student and bribe amount if currPtr is not equal to 0
		currPtr = currPtr->link;
		count++;
	}
}