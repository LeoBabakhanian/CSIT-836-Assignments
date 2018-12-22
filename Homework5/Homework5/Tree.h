//Leo Babakhanian
//Data Structures- Fall Class
//Professor Agazaryan
//Assignment #5

#ifndef TREE_H
#define TREE_H
using namespace std;

//PersonRec struct like the previous assignment
struct PersonRec
{
	string studentName;	//student name
	int bribeAmount;	//bribe amount

	PersonRec* lChild;	//Pointer to left child or null
	PersonRec* rChild;  //Pointer to right child or null
	PersonRec(string, int, PersonRec*, PersonRec*);
	~PersonRec();
};

class CTree
{
private:
	PersonRec *root;

public:
	CTree();
	~CTree();
	void ViewList();
	void AddToList();
};

#endif