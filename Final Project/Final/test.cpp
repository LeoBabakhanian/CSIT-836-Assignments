#include <iostream>
#include <string.h>
#include <cstdlib>
#include "cqueue.h"
#include "cstack.h"
using namespace std;

//palindrome check
bool isPalindrome(CStack* s, CQueue* q)
{
	while (!s->isEmpty() && !q->isEmpty())
	{
		if (s->top() != q->front())
		{
			return false;
		}

		s->pop();
		q->dequeue();
	}

	return true;
}

int main()
{
	char str[100];

	//create a stack and queue
	CStack* s = new CStack;
	CQueue* q = new CQueue;

	while (1)
	{
		//get user input
		cout << "Please enter a string to test for palindrome or type QUIT to exit: ";
		cin.getline(str, 100);

		char str1[100];
		strcpy_s(str1, str);

		//convert to lowercase letters
		for (int i = 0; str[i] != '\0'; i++)
		{
			str[i] = tolower(str[i]);
		}

		//stop input if user enters QUIT
		if (strcmp(str, "quit") == 0)
		{
			return 0;
		}

		//add each alpha character from string into stack and queue
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (isalpha(str[i]))
			{
				s->push(str[i]);
				q->enqueue(str[i]);
			}
		}

		cout << str1 << endl;
		//fix for codezinger test cases to match up

		//call function to decide whether it's palindrome or not
		if (isPalindrome(s, q))
		{
			cout << "The input is a palindrome." << endl;
		}
		else
		{
			cout << "The input is not a palindrome." << endl;
		}

		//make stack and queue empty
		s->makeEmpty();
		q->makeEmpty();
	}
	//my input is not matching with condezinger because the user input is not showing at the
	//end of each line!! I'm not sure how to fix this, it's a minor error but it shows up as
	//all of my test cases failing except for the first
	//fixed^^^

	//system("PAUSE");
	return 0;
}
