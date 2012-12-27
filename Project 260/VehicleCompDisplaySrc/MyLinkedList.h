
#pragma once

// Author: Po Liu, 13623079, x2f7
// Date: 28 July 2010

// Class invariant:
// Creates a linked list with each node containing a separate line from an external file
// Some elements of this class mimic those in lecture notes but there are significant changes

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//The node class
struct Node {
	
	string lineData;
	int identify;
	Node* next;
	
};


class MyLinkedList{

	// Private class variables
	Node* head;
	int counter;

	// inserts a Node at the end of the linked list
	// Pre: given a string
	// post: linked list is lengthened by one
	void insertLast( const string& item );


public:

	// Constructor
	// pre: none
	// post: sets up the list to be used
	MyLinkedList(void);

	// Declared virtual method ---- requirement for appropriate usage in project
	// Destructor
	// pre: none
	// post: none
	virtual ~MyLinkedList(void);

	// Inserts a string input as a node in the linked list
	// pre: none
	// post: makes a new node and adds one to the counter
	void insert(string input);
	
	// Gets a particular line specified by the caller
	// pre: lineNum is greater than 0
	// post: returns string with the counter of that line equal to lineNum
	string getLine(int lineNum);

};
