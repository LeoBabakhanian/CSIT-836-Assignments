#include <iostream>
#include "cqueue.h"
using namespace std;

CQueue::CQueue()
{
	head = NULL;
}

bool CQueue::isEmpty()
{
	return head == NULL;
}

void CQueue::enqueue(char c)
{
	Node *node = new Node;
	node->item = c;
	node->next = NULL;

	if (isEmpty())
	{
		head = node;
	}
	else
	{
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = node;
	}
}

char CQueue::dequeue()
{
	if (isEmpty())
	{
		return '\0'; //NULL was causing a warning error, '\0' fixed this
	}
	else
	{
		Node *temp = head;
		char item = head->item;
		head = head->next;
		delete temp;

		return item;
	}
}

char CQueue::front()
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

char CQueue::rear()
{
	if (isEmpty())
	{
		return '\0'; //NULL was causing a warning error, '\0' fixed this
	}
	else
	{
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		return temp->item;
	}
}

void CQueue::makeEmpty()
{
	while (!isEmpty())
	{
		dequeue();
	}
}