//Leo Babakhanian
//Data Structures
//Homework #2

#include <iostream>
#include <string>
#include <stack>
#include "Cstack.h"
using namespace std;

int main()
{
	Cstack stack1;
	char expression[21];
	string menuChoice;

	while (menuChoice != "quit")
	{
		cout << "Enter an expression: ";
		//User enters expression
		cin >> expression;
		menuChoice = expression;
		//cin.getline(expression, 21);

		bool IsBalanced = stack1.IsValidExpression(expression);

		//Checks for validity and tells you if it's valid or not
		if (IsBalanced)
		{
			cout << "It's a valid expression" << endl;
		}
		else
		{
			cout << "It's NOT a valid expression" << endl;
		}

		cout << "Enter an expression: " << endl;
		cin >> menuChoice, expression;
	}

	//system("PAUSE");
	return 0;
}