

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 22th, 2010

#include "MyList.h"



//invarient: totalSlots(maximum number of ints being stored at a time)
//a type that can keep adding new integers and dumping the oldest ones while the 
//total amount of integers being stored at a time conserves

MyList::MyList(void)
{
	slots = 60;
	counter=0;
	list = new int[60];
	reused = false;
	total = 0;
}

//pre: non
//post: an int being inserted
//	if total<slots, the new int will be stored in a new slot
//  else, the latest inserted int will be replaced by the new int
void MyList::insert(int a){
	list[counter] = a;
	counter++;
	total++;
	if (counter == slots){
		counter = 0;
		reused = true;
	}
}

//pre: 0 <= b < numbers being inserted into the object (in case total < slots)
//pre: 0 <= b < slots (for total > slots)
//b = 0 as the the earliest int being inserted 
//post: return the int corresponding to possition b
int MyList::getInt ( int b){
	if (!reused)
		return list[b];
	else{
		if (counter+b+1>=slots)
			return list[counter+b+1-slots];
		else
			return list[counter+b+1];
	}
}

//pre: none
//post: return reused;
bool MyList::isReused(){
	return reused;
}

//pre:none
//post: return the total number being stored in the list
int MyList::getTotal (){
	if (!reused) return total;
	else return slots;
}

MyList::~MyList(void)
{
}
