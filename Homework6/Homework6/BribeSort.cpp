//Leo Babakhanian
//Data Structures- Fall Class
//Professor Agazaryan
//Assignment #6

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//structure that stores our vars that we use later on in the program
struct PersonRec
{
	string name;
	double money;
	PersonRec *next;
};

void change(PersonRec *a, PersonRec *b)
{
	//PersonRec*temp;
	double change = a->money;
	//saving money
	a->money = b->money;
	//changing the amount
	b->money = change;
	string nam = a->name;
	//saving name
	a->name = b->name;
	//changing the name
	b->name = nam;
}

int divide(PersonRec arr[], int start, int end)
{
	double center = arr[end].money;
	//finding last array element money
	int i = (start - 1);

	for (int j = start; j <= end - 1; j++) //loop until end
	{
		if (arr[j].money <= center)
			//compairing money
		{
			i++;
			change(&arr[i], &arr[j]);
			//changing the array elements
		}
	}

	change(&arr[i + 1], &arr[end]);
	//changing the array elements
	return (i + 1);
	//returning the position
}

void QuickSort(PersonRec arr[], int start, int end)
{
	if (start < end) //base condition
	{
		int pi = divide(arr, start, end);
		//calling our divide function

		QuickSort(arr, start, pi - 1);
		//recursive call on left side of array
		QuickSort(arr, pi + 1, end);
		//recursive call on right side 
	}
}

void bubbleSort(PersonRec arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) //outer loop
	{
		for (int j = 0; j < arraySize - 1; j++) //inner loop
		{
			if (arr[j].money < arr[j + 1].money) //comparing money
				change(&arr[j], &arr[j + 1]); //changing elements of array 
		}
	}
}

int main()
{
	int size = 0;
	int count = 1;
	char opt;
	char inp;
	PersonRec arr[10];

	//For loop that acts as our menu
	for (size = 0; size < 10; size++)
	{
		cout << "Do you want to enter student (Y / N) ? ";
		cin >> inp;

		if (inp == 'Y' || inp == 'y')
			//If option is yes, we ask for inputs
		{
			cout << endl << "Enter the person's name: " << endl;
			cin >> arr[size].name;
			cout << "Enter the person's contribution: " << endl;
			cin >> arr[size].money;
		}
		if (inp == 'N' || inp == 'n')
			/*If option is no, the if statement breaks
			and the program continues with sorting*/
		{
			break;
		}
	}

	//Here is our sort input options
	cout << endl << "Menu" << endl;
	cout << "==============================" << endl << endl;
	cout << "1. Bubble Sort" << endl;
	cout << "2. Quick Sort" << endl;
	cout << "Please enter choice: " << endl;
	cin >> opt;


	if (opt == '1')
	{
		bubbleSort(arr, size);
		//calling bubble sort function
		if (size == 0)
		{
			cout << "List is empty" << endl;
		}
	}
	else if (opt == '2')
	{
		QuickSort(arr, 0, size - 1);
		//calling quick sort function	
		if (size == 0)
		{
			cout << "List is empty" << endl;
		}
	}

	if (size > 0)
	{
		cout << "# Name Contribution" << endl;
		cout << "===================" << endl;

		for (int i = 0; i < size; i++)
			//for loop until it matches the size of array
		{
			cout << count << " " << arr[i].name << " $" << arr[i].money << endl;
			count++;
		}
	}

	system("PAUSE");
	return 0;
}