#include <iostream>
#include "cstack.h"
using namespace std;

CStack::CStack()
{
	head = NULL;
}

bool CStack::isEmpty()
{
	return head == NULL;
}

void CStack::push(char c)
{
	Node *node = new Node;
	node->item = c;
	node->next = head;
	head = node;
}

char CStack::pop()
{
	if (isEmpty())
	{
		return '\0'; //NULL was causing a warning error, '\0' fixed this
	}
	else
	{
		Node* temp = head;
		char item = head->item;
		head = head->next;

		delete temp;
		return item;
	}
}

char CStack::top()
{
	if (isEmpty())
	{
		return '\0'; //NULL was causing a warning error, '\0' fixed this
	}
	else
	{
		return head->item;
	}
}

void CStack::makeEmpty()
{
	while (!isEmpty())
	{
		pop();
	}
}