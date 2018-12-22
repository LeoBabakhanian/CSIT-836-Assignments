#ifndef CQUEUE_H
#define CQUEUE_H
#include <iostream>

class CQueue
{
private:
	struct Node
	{
		char item;
		Node* next;
	};
	Node *head;

public:
	CQueue();
	bool isEmpty();
	void enqueue(char c);
	char dequeue();
	char front();
	char rear();
	void makeEmpty();
};
#endif