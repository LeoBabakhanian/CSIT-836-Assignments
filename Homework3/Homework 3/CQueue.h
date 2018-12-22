//Leo Babakhanian
//Data Structures Online- Fall Class
//Assignment #3

#ifndef CQUEUE_H
#define CQUEUE_H

const int MAX = 4; //4 is the appropriate number for this array 

//Passenger struct to store info in array
struct Passenger
{
	char name[80];
};

class CQueue
{

	//private member variables including array
private:
	int front;
	int rear;

	Passenger passengers[MAX];

	//public member functions
public:
	CQueue();
	bool IsEmpty(void);
	bool IsFull(void);
	Passenger Front(void);
	void Enqueue(Passenger);
	void Dequeue(void);
};

#endif