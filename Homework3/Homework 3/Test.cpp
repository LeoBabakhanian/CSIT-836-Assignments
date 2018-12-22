//Leo Babakhanian
//Data Structures Online- Fall Class
//Assignment #3

#include <iostream>
#include "CQueue.h"
using namespace std;

enum choice { BOOKED, WAITING };
const int LINES = 2;
int showMenu(void);
void addPassenger(CQueue*);
void deletePassenger(CQueue*);
void showPassengers(CQueue*);

int main(void)
{
	CQueue qPassengers[LINES];
	int x;

	do
	{
		x = showMenu();

		switch (x)
		{
		case 1:
			addPassenger(qPassengers);
			break;

		case 2:
			deletePassenger(qPassengers);
			break;

		case 3:
			showPassengers(qPassengers);
			break;
		}
	} while (x != 4);

	//system("PAUSE");
	return 0;
}

int showMenu(void) //menu function
{
	int select;

	cout << "Menu\n";
	cout << "========\n";
	cout << "1. Add Passenger\n";
	cout << "2. Delete Passenger\n";
	cout << "3. Show Passengers\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	cin >> select;

	if (select < 1 || select > 4) //validity check of select input
	{
		cout << "Invalid entry" << endl;
	}

	return select;
}

void addPassenger(CQueue* queue) //Passenger adding function
{
	Passenger passenger;

	//Adds passenger to plane if not full
	if (!queue[BOOKED].IsFull())
	{
		cout << "Enter name: ";
		cin >> passenger.name;

		queue[BOOKED].Enqueue(passenger);
	}

	//Adds passenger to wait list if plane full
	else if (queue[BOOKED].IsFull() && !queue[WAITING].IsFull())
	{
		cout << "Enter name: ";
		cin >> passenger.name;
		cout << "Sorry. Plane fully booked. Adding " << passenger.name << " to waiting list\n";

		queue[WAITING].Enqueue(passenger);
	}

	//Checks if both plane and waiting list is full
	else if (queue[BOOKED].IsFull() && queue[WAITING].IsFull())
	{
		cout << "Sorry. Plane and waiting list fully booked. Try later\n";
	}
}

void deletePassenger(CQueue* queue) //Remove passenger function
{
	if (queue[BOOKED].IsEmpty()) //If empty
	{
		cout << "No passengers to delete\n";
	}

	else if (!queue[BOOKED].IsEmpty() && queue[WAITING].IsEmpty())
	{
		//cout << "Removing " << queue[BOOKED].Front().name << " from booked passengers\n";
		//Not needed in test case ^^
		queue[BOOKED].Dequeue(); //Removes a passenger from booked
	}

	else if (queue[BOOKED].IsFull() && !queue[WAITING].IsEmpty())
	{
		//cout << "Removing " << queue[BOOKED].Front().name << " from booked passengers\n";
		//Not needed in test case ^^
		queue[BOOKED].Dequeue();
		cout << "Adding " << queue[WAITING].Front().name << " from waiting list\n";

		queue[BOOKED].Enqueue(queue[WAITING].Front());
		queue[WAITING].Dequeue(); //Removes from waiting list
	}
}

void showPassengers(CQueue* queue) //Shows BOOKED and WAITING lists
{
	if (queue[BOOKED].IsEmpty())
	{
		cout << "No passengers\n";
	}

	else if (!queue[BOOKED].IsEmpty() && queue[WAITING].IsEmpty())
	{
		cout << "Booked Passengers\n" << "=================\n";
		string firstName = queue[BOOKED].Front().name;

		do
		{
			cout << queue[BOOKED].Front().name << endl;
			Passenger placeholder = queue[BOOKED].Front();

			queue[BOOKED].Dequeue();
			queue[BOOKED].Enqueue(placeholder);
		} while (queue[BOOKED].Front().name != firstName);

		cout << "No passengers on waiting list\n";
	}

	else if (!queue[BOOKED].IsEmpty() && !queue[WAITING].IsEmpty())
	{
		cout << "Booked Passengers\n" << "=================\n";
		string firstName = queue[BOOKED].Front().name;

		do
		{
			cout << queue[BOOKED].Front().name << endl;
			Passenger placeholder = queue[BOOKED].Front();

			queue[BOOKED].Dequeue();
			queue[BOOKED].Enqueue(placeholder);
		} while (queue[BOOKED].Front().name != firstName);

		cout << "Waiting list\n" << "=================\n";
		firstName = queue[WAITING].Front().name;

		do
		{
			cout << queue[WAITING].Front().name << endl;
			Passenger placeholder = queue[WAITING].Front();

			queue[WAITING].Dequeue();
			queue[WAITING].Enqueue(placeholder);
		} while (queue[WAITING].Front().name != firstName);
	}
}