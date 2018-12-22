//Leo Babakhanian
//Data Structures Online- Fall Class
//Assignment #3

#include <iostream>
#include "CQueue.h"
using namespace std;

CQueue::CQueue()
{
	front = MAX - 1;
	rear = MAX - 1;

	//for loop using MAX array
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			passengers[i].name[j] = ' ';
		}
	}

}

bool CQueue::IsEmpty(void) //Use to check if empty using bool var.
{
	bool empty;

	if (front == rear)
		empty = true;

	else
		empty = false;

	return empty; //bool var
}

bool CQueue::IsFull(void) //Use to check if full using bool var.
{
	bool full;

	if ((rear + 1) % MAX == front)
		full = true;

	else
		full = false;

	return full; //bool var
}

void CQueue::Enqueue(Passenger p) //Queues a passenger in
{
	rear = (rear + 1) % MAX;
	passengers[rear] = p;

	//no return
}

Passenger CQueue::Front(void)
{
	Passenger frontP = passengers[(front + 1) % MAX];

	return frontP;
}

void CQueue::Dequeue(void) //Removes a passenger
{
	front = (front + 1) % MAX;

	//no return
}