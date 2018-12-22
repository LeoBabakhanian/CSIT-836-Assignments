//Leo Babakhanian
//Co Sci 836- Fall Class
//Homework 1

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date d1;
	
	int m;
	int d;
	int y;

	cout << "Enter month, day, and year seperated by spaces: " << endl;
	cin >> m >> d >> y;

	d1.setDate(m,d,y);
	d1.printDate();

	system("PAUSE");
	return 0;
}
