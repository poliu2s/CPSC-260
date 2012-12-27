#pragma once

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};


class MyLinkedList{
	int MAX_SLOTS;
	Node* head;
	int counter;

	//helper function
	//modified based on lecture notes
	void insertFirst( const int& item );

	//helper function
	//modified based on lecture notes
	void deleteLast();

public:
	MyLinkedList(int slots);
	MyLinkedList(void);
	~MyLinkedList(void);


	//pre: none
	//post: inserts a new data at the beginning of the list
	//		if counter > MAX_SLOTS, delete the last(oldest) data
	void insert(int a);

	//returns data in spot number b
	//pre: b < counter
	//post: returns data in spot number b
	int getInt(int b);

	//pre: none
	//post: returns the total number of datas in the list
	int getTotal ();
};

