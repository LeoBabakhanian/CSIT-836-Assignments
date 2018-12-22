//Leo Babakhanian
//Data Structures
//Homework #2

#include <iostream>
#include <stack>
#include "Cstack.h"
using namespace std;

Cstack::Cstack()
{

}

//Compares left and right characters to each other
//Returns if they match or not through false or true cases
bool Cstack::IsEqual(char left, char right)
{
	if (left == '(' && right == ')')
		return true;
	else if (left == '{' && right == '}')
		return true;
	else if (left == '[' && right == ']')
		return true;
	else
		return false;
}

//Function we pass the array to in order to check for validity
bool Cstack::IsValidExpression(char exp[])
{
	//We use a stack
	//Using push, pop, and top we can check each character
	stack<char> Stack;
	int i = 0;

	while (exp[i])
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			Stack.push(exp[i]);
		}
		if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (Stack.empty() || !IsEqual(Stack.top(), exp[i]))
			{
				return false;
			}
			else
			{
				Stack.pop();
			}
		}
		i++;
	}

	return Stack.empty();

}
