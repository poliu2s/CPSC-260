
// Author: Po Liu, 13623079, x2f7
// Date: 28 July 2010


#ifndef DATA_H
#define DATA_H


#include <iostream>
#include <string>
#include <sstream>
#include "MyLinkedList.h"


using namespace std;



// Class invariant:
// The data class takes input from an external file, places it into a MyLinkedList element,
// and processes it into a character array. This array can then be searched through by the
// findword() method
class data {
	
	MyLinkedList inputStorage;
	char wordsearch[10][10];

	int sizeX;
	int sizeY;


public:

	// Constructor that sets the size arbitrarily to 10x10 (can be altered)
	// pre: none
	// post: sets the size of the array to be 10x10 (although other modifications are needed)
	data();
	

	// Inputs new lines from a file
	// pre: given a string that matches the size of the array dimensions
	// post: inserts string into inputStorage linked list
	void update(string newData);


	// Executed after all the input strings have been processed (reached end of file)
	// pre: done entering information into the object
	// post: processes all chars into a wordsearch[][] array for later searching use
	void inputCompleted();


	// Returns the desired character
	// pre: given int coordinates must be within the bounds of the array (no error checking)
	// post: returns a character at those coordinates
	char getDesiredChar(int x, int y);


	// Sets the size of the array
	// pre: given ints must be greater than 0
	// post: none
	void setArraySize(int rows, int cols);


	// findword looks for a string given and returns either the location in a int pointer or the not found int
	// pre: must take a string that is the word the user is looking for
	// post: returns the location of the word in a int pointer array (x coordinate, y coordinate, direction)
	int* findword(string interestedWord);

	// Checks if a given letter is at a certain location
	// pre: given char, and 2 positive ints
	// post: returns true if found
	bool isLetterHere(char letter, int a, int b);

	// Converts a number to a string type
	// pre: given int
	// post: converted string returned
	string stringConverter(int num);

	
};
#endif
