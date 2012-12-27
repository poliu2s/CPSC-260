
// Author: Po Liu, 13623079, x2f7
// Date: 28 July 2010

// Class invariant:
// The data class takes input from an external file, places it into a MyLinkedList element,
// and processes it into a character array. This array can then be searched through by the
// findword() method

#include "data.h"
#include "MyLinkedList.h"

#include <iostream>
#include <string>
#include <sstream>



using namespace std;


// Constructor that sets the size arbitrarily to 10x10 (can be altered)
// pre: none
// post: sets the size of the array to be 10x10 (although other modifications are needed)
data::data(){
	
	// Temporary allocation, should be set again later on
	sizeX = 10;
	sizeY = 10;

}

// Inputs new lines from a file
// pre: given a string that matches the size of the array dimensions
// post: inserts string into inputStorage linked list
void data::update(string newData){
	
	inputStorage.insert(newData);
}


// Executed after all the input strings have been processed (reached end of file)
// pre: done entering information into the object
// post: processes all chars into a wordsearch[][] array for later searching use
void data::inputCompleted() {

	string temp;

	for (int i = 0; i < sizeY; i++) {

		temp = inputStorage.getLine(i);

		for (int j = 0; j < sizeX; j++) {
			wordsearch[i][j] = temp[j];
		}
	}
}

// Returns the desired character
// pre: given int coordinates must be within the bounds of the array (no error checking)
// post: returns a character at those coordinates
char data::getDesiredChar(int x, int y) {

	return wordsearch[x][y];
}


// findword looks for a string given and returns either the location in a int pointer or the not found int
// pre: must take a string that is the word the user is looking for
// post: returns the location of the word in a int pointer array (x coordinate, y coordinate, direction)
int* data::findword(string interestedWord) {


	// For placeholder pointer,
	// the first number denotes the row that the word starts
	// the second number denotes the column that the word starts
	// the third number denotes the direction that the word appears in (0-7 inclusive)
	/*
			UpLeft = 0
			Up = 1
			UpRight = 2
			Left = 3
			Right = 4
			DownLeft = 5
			Down = 6
			DownRight = 7
	*/


	int *placeholder = new int[3];
	int wordSize = interestedWord.size();
	


	// First two loops go over the entire block of text looking for a character match
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			
			
			// If first letter of word of interest mataches a char, then execute search around algorithm
			if (wordsearch[i][j] == interestedWord[0] ) {

				//cout << "\nSearching around position: " << i << j << "\n\n";
				int direction = -1;

				// These variables become true if the word is found in the direction indicated
				bool upResults = false;
				bool downResults = false;
				bool leftResults = false;
				bool rightResults = false;
				bool diagULResults = false;
				bool diagURResults = false;
				bool diagDLResults = false;
				bool diagDRResults = false;


				bool continueLoopU = true;
				bool continueLoopD = true;
				bool continueLoopL = true;
				bool continueLoopR = true;
				bool continueLoopUL = true;
				bool continueLoopUR = true;
				bool continueLoopDL = true;
				bool continueLoopDR = true;
				int u = 1;
				

				// Main loop that looks around a matched first character and returns a true boolean if word is found
				do {
					upResults = false;
					downResults = false;
					leftResults = false;
					rightResults = false;
					diagULResults = false;
					diagURResults = false;
					diagDLResults = false;
					diagDRResults = false;
					
					// Looking up
					if (i-u >= 0 && continueLoopU == true) {
						if (wordsearch[i-u][j] == interestedWord[u] ) {

							upResults = true;
							//cout << "UP" << endl;

						}else {
							continueLoopU = false;
							upResults = false;
						}
					}

					//Looking down
					if (i+u < sizeY && continueLoopD == true) {

						if (wordsearch[i+u][j] == interestedWord[u]) {

							downResults = true;
							//cout << "DOWN" << endl;

						}else {
							continueLoopD = false;
							downResults = false;
						}
					}


					// Looking left
					if (j-u >= 0 && continueLoopL == true) {

						if (wordsearch[i][j-u] == interestedWord[u]) {
							leftResults = true;
						
							//cout << "LEFT" << endl;
						}else {
							continueLoopL = false;
							leftResults = false;
						}
					}

					// Looking Right
					if (j+u < sizeX && continueLoopR == true) {

						if (wordsearch[i][j+u] == interestedWord[u]) {
							rightResults = true;

							//cout << "RIGHT" << endl;
						} else {
							continueLoopR = false;
							rightResults = false;
						}
					}

					// Looking UpLeft
					if (i-u >= 0 && j-u >= 0 && continueLoopUL == true) {


						if (wordsearch[i-u][j-u] == interestedWord[u]) {
							diagULResults = true;
						
							//cout << "UP LEFT" << endl;
						}else {
							continueLoopUL = false;
							diagULResults = false;
						}
					}

					// Looking UP Right
					if (i-u >= 0  && j+u < sizeX && continueLoopUR == true) {


						if (wordsearch[i-u][j+u] == interestedWord[u]) {
							diagURResults = true;
						
							//cout << "UP RIGHT" << endl;
						}else {
							continueLoopUR = false;
							diagURResults = false;
						}

					}
					
					// Looking Down Left
					if (i-u >= 0 && j-u >= 0  && continueLoopDL == true) {


						if (wordsearch[i-u][j-u] == interestedWord[u]) {
							diagULResults = true;
						
							//cout << "UP LEFT" << endl;
						}else {
							continueLoopDL = false;
							diagULResults = false;
						}

					}

					// Looking Down Right
					if (i+u < sizeY  && j+u < sizeX && continueLoopDR == true) {

						if (wordsearch[i+u][j+u] == interestedWord[u]) {
							diagDRResults = true;
						
							//cout << "DOWN RIGHT" << endl;
						}else {
							continueLoopDR = false;
							diagDRResults = false;
						}

					}

					// Increment the u to move through the length of the word of interst
					u++;
				}while (u < wordSize);

				// Set the direction of the found word in the pointer to be passed back
				if (upResults) direction = 1;
				if (downResults) direction = 6;
				if (leftResults) direction = 3;
				if (rightResults) direction = 4;
				if (diagULResults) direction = 0;
				if (diagURResults) direction = 2;
				if (diagDLResults) direction = 5;
				if (diagDRResults) direction = 7;


				// If the word was found (no order specified), then pass the location back to the caller
				if (upResults == true || downResults==true || leftResults==true || rightResults==true ||
					diagULResults==true || diagDLResults==true || diagURResults==true || diagDRResults==true) {

					*(placeholder+0) = i;
					*(placeholder+1) = j;
					*(placeholder+2) = direction;
					return placeholder;
				}
			}
		}
	}

	// If word wasn't found, send back error pointer int (-1, -1. -1)
	int notFound[3];
	notFound[0] = -1;
	notFound[1] = -1;
	notFound[2] = -1;
	int *didNotFind = notFound;

	cout << "\n--------------------------------------------------------"
		<< "\nThe word you searched was not found!!!"
		<< "\n--------------------------------------------------------\n";

	return didNotFind;

}


// Checks if a given letter is at a certain location
// pre: given char, and 2 positive ints
// post: returns true if found
bool data::isLetterHere(char letter, int a, int b) {
	
	if (wordsearch[a][b] == letter) {
		return true;
	}
	return false;
}


// Sets the size of the array
// pre: given ints must be greater than 0
// post: none
void data::setArraySize(int rows, int cols) {
	sizeX = rows;
	sizeY = cols;

}


// Converts a number to a string type
// pre: given int
// post: converted string returned
string data::stringConverter(int num){
	stringstream is;
	is << num;
	string temp = is.str();
	return temp;
}
