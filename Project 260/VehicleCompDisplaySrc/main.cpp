
// Author: Po Liu, 13623079, x2f7
// Date: 28 July 2010

// Project: Word Search Helper
// This program takes an external file containing a block of strings that represent a word search puzzle
// and desplays it into a GUI format. It allows the user to quickly find words that they are interested in.

#include "Simple_window.h"
#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include <iostream>
#include <string>

#include "DisplaySleep.h"

// !!!!!! - User defined classes for this assignment - !!!!!!!!!
#include "data.h"		
#include "inputFormatter.h"	
#include "MyLinkedList.h"		// contains a dynamic structure containing pointers
#include "searchWindow.h"		// contains a inherited class with virtual method declaraction


using namespace std;


int main() {
	
	cout << "\nWord Search Helper Program" << endl << "------------------------------------------" << endl;

	// Asks the user to enter the directory and file name
	cout << "Please enter name and extension of the word search: " << endl;
	cout << "Note: the program will exit immediately if directory or file name does not exist" << endl;
	cout << "(Example: \"search1.txt\" to use the file in this folder)" << endl << endl;
	string file_name;
    cin >> file_name;
	cout << endl << endl;

	// Convert file_name into an accessible format - convert '/' to '\\' in string
	inputFormatter object2;
	file_name = object2.formatDirectory(file_name);
	

	// Open the file from the given directory with error checking
	ifstream ifs;
	ifs.open(file_name);
	if (!ifs) {
		cout << "The file name is invalid." << endl;
		ifs.close();
		exit(0);
	}

	// -----------------------------------------------------------------

	// Object that will contain the main characters in the word search file
	data block_of_text;
	string tempLine;

	// Can change the dimensions of the incoming char matrix
	int rowCounter = 0;
	int colCounter = 0;


	// Main loop that gets line by line from another txt file
	while (getline(ifs, tempLine)) {
		
		cout << "Reading Line : " << tempLine << endl;
		block_of_text.update(tempLine);
		
		colCounter = tempLine.size();
		rowCounter++;
	}
	cout << "\nReached the end of the file." << endl;


	// Tell block_of_text that we are done adding new input
	block_of_text.inputCompleted();
	block_of_text.setArraySize(rowCounter, colCounter);

	
	// Prints out the char matrix to ensure that it was stored correctly in block_of_text
	cout << "\n\nThe file you entered has the following format";
	for (int i = 0; i <10; i++) {
		for (int j = 0; j<10; j++) {

			cout << block_of_text.getDesiredChar(i, j);
		}

		cout << endl;
	}
	

	// Create new window and pass reference to matrix on
	searchWindow win(Point(400,100),600,300,"Word Search Helper", &block_of_text);
	return gui_main();


	return 0;
}