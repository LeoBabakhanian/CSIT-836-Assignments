//Leo Babakhanian
//Co Sci 836- Fall Class
//Homework 1

#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}

bool Date::setDate(int m, int d, int y)
{
	//CHECK DATE
	month = m;
	day = d;
	year = y;

	bool test;

		if (month > 12 || month < 1 && day > 31 || day < 1 && year > 2018 || year < 1900)
		{
			month = 9;
			day = 1;
			year = 2018;
			test = false;
		}
		else
		{
			test = true;
		}
		return test;
}

void Date::printDate()
{
	//PRINT
	cout << month << "/" << day << "/" << year << endl;
}

