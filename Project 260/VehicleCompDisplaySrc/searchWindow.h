#pragma once

// Author: Po Liu, 13623079, x2f7
// Date: 28 July 2010

// Class invariant:
// A user defined window class that displays the main GUI functionality by visually displaying
// the char matrix and allows the user to input words to find

#include <iostream>
#include <string>
#include <sstream>
#include "Simple_window.h"
#include "data.h"
#include "inputFormatter.h"	
#include "MyLinkedList.h"

#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H


struct searchWindow:Window
{
	
	// Constructor that takes in a pointer to the wordsearch matrix
	// pre: none
	// post: sets up the window and draws everything
	searchWindow(Point xy, int w, int h, const string& title, data* rawMatrix );


	// Use of virtual method in destructor -------> one of the project requirements
	virtual ~searchWindow() { }
	

	// For displaying and holding the char array
	data* wordSearch;
	Text* displayMatrix[10][10];

	Text* sampleWord1;
	Text* sampleWord2;
	Text* sampleWord3;
	Text* sampleWord4;
	Text* sampleWord5;
	Text* sampleWord6;


private:
	Button find_button;
	Button quit_button;
	In_box next_x;

	// Callback function for find
	// pre: none
	// post: executes the find()
	static void cb_find(Address, Address);
	
	// When the find key is pressed, take the word in the inbox and look for it
	// If it is found, then change the color of the word in the GUI
	// pre: find key is clicked
	// post: Highlights a word in the matrix, if not found then does nothing
	void find();

	// Callback function for quit
	// pre: none
	// post: executes the quit()
	static void cb_quit(Address, Address);

	// Quits out of the program if quit button is pressed
	// pre: quit button click
	// post: program exists
	void quit();


};



#endif