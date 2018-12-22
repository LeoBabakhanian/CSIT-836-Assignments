//Leo Babakhanian
//Co Sci 836- Fall Class
//Homework 1

#ifndef DATE_H
#define DATE_H

class Date
{
private:
	//Variables
	int month;
	int day;
	int year;
public:
	//Functions
	Date();
	bool setDate(int, int, int);
	void printDate();
};

#endif