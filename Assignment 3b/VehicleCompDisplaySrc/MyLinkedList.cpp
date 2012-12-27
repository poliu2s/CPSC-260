//customed linked list, all based on lecture notes
#include <iostream>
#include "MyLinkedList.h"
using namespace std;

MyLinkedList::MyLinkedList (int slots)
{
	counter = 0;
	MAX_SLOTS = slots;
	head = new Node;
	head->next = head;
	head->prev = head;

}

MyLinkedList::MyLinkedList (void)
{
	counter = 0;
	MAX_SLOTS = 60;
	head = new Node;
	head->next = head;
	head->prev = head;

}

//helper function
//modified based on lecture notes
void MyLinkedList::insertFirst(const int& item ){
	Node* newNode = new Node;
    newNode->data = item;
    newNode->next = head->next;
    newNode->prev = head;
    
    head->next = newNode;
	//newNode->next->prev = newNode; 
	

	if (counter < MAX_SLOTS)
		counter++;

	if (counter == 1) 
		head->prev = newNode;
}

//helper function
//modified based on lecture notes
void MyLinkedList::deleteLast(){
	Node* newNode;
	newNode = head->prev;
	head->prev = newNode->prev;
    newNode->prev->next = head;
	delete newNode;
	newNode=NULL;
}

//pre: none
//post: inserts a new data at the beginning of the list
//		if counter > MAX_SLOTS, delete the last(oldest) data	
void MyLinkedList::insert(int a){
	if (counter == MAX_SLOTS)
		deleteLast();
	
	insertFirst(a);
	
}

//returns data in spot number b
//pre: b < counter
//post: returns data in spot number b
int MyLinkedList::getInt( int b){
	Node* cursor = head->next;
	for (int i = 0; i < b; i++)
		cursor = cursor->next;
    
	return cursor->data;


}

//pre: none
//post: returns the total number of datas in the list
int MyLinkedList::getTotal (){
	return counter;
}

MyLinkedList::~MyLinkedList(void){
	Node* cursor = head->next;
	for (int i = 0; i < counter; i++){
		delete cursor->prev;
		cursor = cursor->next;
	}
	delete cursor;
	cursor = NULL;
}



