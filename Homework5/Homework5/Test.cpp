//Leo Babakhanian
//Data Structures- Fall Class
//Professor Agazaryan
//Assignment #5

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Tree.h"

int displayMenu(void);
void processChoice(int, CTree&);


int main(void)
{
	int num;
	CTree tree1;

	do
	{
		num = displayMenu();

		if (num != 3)
			processChoice(num, tree1);
	} while (num != 3);

	//system("PAUSE");
	return 0;
}

int displayMenu(void)
{
	int choice;

	cout << "Menu" << endl;
	cout << "==============================" << endl << endl;
	cout << "1. Add student to waiting list" << endl;
	cout << "2. View waiting list" << endl;
	cout << "3. Exit program" << endl << endl;
	cout << "Please enter choice: ";
	cin >> choice;

	return choice;
}

void processChoice(int choice, CTree& myTree)
{
	switch (choice)
	{
	case 1:
		myTree.AddToList();
		break;
	case 2:
		myTree.ViewList();
		break;
	}
}