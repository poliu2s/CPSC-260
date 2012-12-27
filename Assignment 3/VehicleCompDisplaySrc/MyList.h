

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 22th, 2010

#pragma once
#include <iostream>
#include <string>

//invarient: totalSlots(maximum number of ints being stored at a time)
//a type that can keep adding new integers and dumping the oldest ones while the 
//total amount of integers being stored at a time conserves
class MyList
{
	int counter; 
	int slots;//total slots available
	int total;//total number of int has been inserted
	bool reused;//once total>slots, new inserted ints will be stored from the beginning of the list (the list is being reused)
	int* list; 
public:
	MyList(void);

	//pre: non
	//post: an int being inserted
	//	if total<slots, the new int will be stored in a new slot
	//  else, the latest inserted int will be replaced by the new int
	void insert(int a);

	//pre: 0 <= b < numbers being inserted into the object (in case total < slots)
	//pre: 0 <= b < slots (for total > slots)
	//b = 0 as the the earliest int being inserted 
	//post: return the int corresponding to possition b
	int getInt ( int b);

	//pre: none
	//post: return reused;
	bool isReused();


	int getTotal ();

	~MyList(void);
};

