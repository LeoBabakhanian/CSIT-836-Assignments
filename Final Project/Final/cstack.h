#ifndef CSTACK_H
#define CSTACK_H
#include <iostream>

class CStack
{
private:
	struct Node
	{
		char item;
		Node* next;
	};
	Node *head;

public:
	CStack();
	bool isEmpty();
	void push(char c);
	char pop();
	char top();
	void makeEmpty();

};


#endif