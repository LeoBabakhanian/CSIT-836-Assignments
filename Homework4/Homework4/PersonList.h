//Leo Babakhanian
//Data Structures- Fall Class
//Professor Agazaryan
//Assignment #4

#ifndef PERSON_H
#define PERSON_H

//PersonRec struct, store vars
struct PersonRec
{
	PersonRec *link;
	//pointer, name, bribe vars
	string student;
	int money;
};

class PersonList
{
	//Private pointer
private:
	//Point to head/test
	PersonRec* head;

	//Public member functions
public:
	PersonList(); //constructor
	~PersonList(); //destructor
	void AddToList(); //add
	void ViewList(); //view
					 //Don't need any other functions
};

#endif