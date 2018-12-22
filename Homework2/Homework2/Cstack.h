//Leo Babakhanian
//Data Structures
//Homework #2

#ifndef CSTACK_H
#define CSTACK_H

class Cstack
{
	//Private Member Variables
private:
	char expr[21]; //not sure if needed
				   //string temp;

				   //Public Member Functions
public:
	Cstack();
	bool IsValidExpression(char[]); //Checks for validity of expression
	bool IsEqual(char, char); //Compares left and right chars of matching symbol types
};

#endif
