
// Author: Po Liu, 13623079, x2f7
// Date: 28 July 2010

// Class invariant:
// Creates a linked list with each node containing a separate line from an external file
// Some elements of this class mimic those in lecture notes but there are significant changes

#include <iostream>
#include <string>
#include <sstream>
#include "MyLinkedList.h"



// Constructor
// pre: none
// post: sets up the list to be used
MyLinkedList::MyLinkedList() {
	
	counter = 0;
	head = NULL;
}

// Destructor
// pre: none
// post: none
MyLinkedList::~MyLinkedList() { }


// Inserts a string input as a node in the linked list
// pre: none
// post: makes a new node and adds one to the counter
void MyLinkedList::insert(string input) {

	insertLast(input);

	counter++;

}


// inserts a Node at the end of the linked list
// Pre: given a string
// post: linked list is lengthened by one
void MyLinkedList::insertLast(const string& item) {

	Node* newNode = new Node;
	newNode->lineData = item;
	newNode->identify = counter;
	newNode->next = NULL;


	// Find last node and make it point to the newNode (from lecture slides)
	if (head == NULL) {
		head = newNode;

	} else {

		Node* cursor = head;
		while( cursor->next != NULL ) 
			cursor = cursor->next;

		cursor->next = newNode;

	}
}


// Gets a particular line specified by the caller
// pre: lineNum is greater than 0
// post: returns string with the counter of that line equal to lineNum
string MyLinkedList::getLine(int lineNum) {

	Node* cursor = head;
	Node* previousNode = NULL;
	while( cursor != NULL && cursor->identify != lineNum ) {
		previousNode = cursor;
		cursor = cursor->next;
	}

	return cursor->lineData;

}