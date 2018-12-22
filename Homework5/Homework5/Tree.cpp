//Leo Babakhanian
//Data Structures- Fall Class
//Professor Agazaryan
//Assignment #5

#include <iostream>
#include <string>
using namespace std;

#include "Tree.h"

PersonRec::PersonRec(string studName, int bribeAm, PersonRec* lChildSet, PersonRec* rChildSet)
{
	studentName = studName;
	bribeAmount = bribeAm;
	lChild = lChildSet;
	rChild = rChildSet;
}

PersonRec::~PersonRec()
{
	//NULL list, set to 0 if not already 0
	if (lChild != NULL)
		lChild = NULL;
	//NULL list, set to 0 if not already 0
	if (rChild != NULL)
		rChild = NULL;
}

CTree::CTree() //Constructor func
{
	//set root to 0
	root = NULL;
}

CTree::~CTree() //Destructor func
{
	if (root != NULL)
	{
		bool deleteR = false;

		PersonRec** Del = &root;

		do
		{
			if ((*Del)->rChild == NULL)
			{
				delete (*Del);
				(*Del) = NULL;

				if (Del == &root)
				{
					deleteR = true;
				}
				else
				{
					Del = &root;
				}
			}
			else
			{
				Del = &(*Del)->rChild;
			}

		} while (deleteR == false);
	}
}

void CTree::AddToList() //**add to list func
{
	string student;
	int bribe;

	cout << endl << "Enter the person's name: " << endl;
	cin.ignore();
	getline(cin, student);
	cout << "Enter the person's contribution: ";
	cin >> bribe;

	if (root == NULL)
	{
		root = new PersonRec(student, bribe, NULL, NULL);
	}
	else
	{
		//test to see if student is added to the list
		bool added = false;
		//test variable if the bribe was already accepted
		bool duplicateBribe = false;

		PersonRec** order = &root;
		PersonRec** last = &(*order)->lChild;

		do
		{
			if ((*order) == NULL)
			{
				PersonRec* temp = new PersonRec(student, bribe, (*last), NULL);
				(*order) = temp;

				added = true;
			}
			else
			{
				if ((*order)->bribeAmount < bribe)
				{
					PersonRec* temp = new PersonRec(student, bribe, (*order)->lChild, (*order));

					(*order)->lChild = temp;
					(*order) = temp;

					added = true;
				}
				else if ((*order)->bribeAmount == bribe) //Make sure to add test case message here
				{
					duplicateBribe = true;
					//If bribe bool is set to true we print this message
					cout << endl << "This bribe amount has already been paid." << endl;
				}
				else
				{
					last = &(*order)->lChild;

					order = &(*order)->rChild;
				}
			}
		} while (added == false && duplicateBribe == false);
	}
}

void CTree::ViewList() //view list func
{
	//if root is equal to 0, print list is empty
	//else, we print the list as the user selects the view list function
	if (root == NULL)
	{
		cout << endl << "List is empty" << endl;
	}
	else
	{
		int count;

		PersonRec* viewList = root;

		cout << endl << "# Name Contribution" << endl;
		cout << "=======================================" << endl;

		count = 1;
		//Set count to 1, shows the students position when printing the list

		//Print loop
		do
		{
			cout << count << " " << viewList->studentName << " $" << viewList->bribeAmount << endl;
			count++;

			viewList = viewList->rChild;
			//add to count every time loop is executed
			//This will order the students from 1 to however many valid inputs there are

		} while (viewList != NULL);
	}
}