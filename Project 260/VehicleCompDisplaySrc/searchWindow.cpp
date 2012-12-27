
// Author: Po Liu, 13623079, x2f7
// Date: 28 July 2010

#include <iostream>
#include <string>
#include <sstream>

#include "searchWindow.h"
#include "Simple_window.h"
#include "data.h"		
#include "inputFormatter.h"	
#include "MyLinkedList.h"

using namespace std;


// Class invariant:
// A user defined window class that displays the main GUI functionality by visually displaying
// the char matrix and allows the user to input words to find

// Use of INHERITANCE here !!!!
// Constructor that takes in a pointer to the wordsearch matrix
// pre: none
// post: sets up the window and draws everything
searchWindow::searchWindow(Point xy, int w, int h, const string& title, data* passedMatrix )
	:Window(xy, w, h, title),
	find_button(Point(x_max()-150,0),70,20,"Find Word", cb_find),
	quit_button(Point(x_max()-70,0), 70,20,"Quit", cb_quit),
	next_x(Point(x_max()-310,0), 140,20, "Word to search for: ")
{

	attach(find_button);
	attach(quit_button);
	attach(next_x);

	wordSearch = passedMatrix;
	string displayChar;

	for (int i = 0 ; i < 10; i++) {
		for (int j = 0; j <10; j++) {

			// Convert char to string
			stringstream ss;
			ss << wordSearch->getDesiredChar(j,i);		// not sure why it is switched
			ss >> displayChar;

			// Initialize the text pointers and attach them to window
			displayMatrix[i][j] = new Text(Point(50+i*20, 50+j*20), displayChar);
			attach(*displayMatrix[i][j]);

		}
	}


	// Attach labels for sample words
	sampleWord1 = new Text(Point(300, 100), "List of (sample) words to search for:");
	sampleWord1->set_color(Color::dark_magenta);
	sampleWord2 = new Text(Point(300, 100 + 20*1), "DOG");
	sampleWord3 = new Text(Point(300, 100 + 20*2), "SAPPHIRE");
	sampleWord4 = new Text(Point(300, 100 + 20*3), "CPSC260");
	sampleWord5 = new Text(Point(300, 100 + 20*4), "SEPTEMBER");
	sampleWord6 = new Text(Point(300, 100 + 20*5), "RAIN");


	attach(*sampleWord1);
	attach(*sampleWord2);
	attach(*sampleWord3);
	attach(*sampleWord4);
	attach(*sampleWord5);
	attach(*sampleWord6);
}

// Callback function for quit
// pre: none
// post: executes the quit()
void searchWindow::cb_quit(Address, Address pw)
{
	reference_to<searchWindow>(pw).quit();
}

// Quits out of the program if quit button is pressed
// pre: quit button click
// post: program exists
void searchWindow::quit()
{
	hide();
}

// Callback function for find
// pre: none
// post: executes the find()
void searchWindow::cb_find(Address, Address pw) {
	reference_to<searchWindow>(pw).find();
}


// When the find key is pressed, take the word in the inbox and look for it
// If it is found, then change the color of the word in the GUI
// pre: find key is clicked
// post: Highlights a word in the matrix, if not found then does nothing
void searchWindow::find()
{
	string searchWord = next_x.get_string();
	cout << "\nSearch for word: " << searchWord << endl;

	int* result = wordSearch->findword(searchWord);
	int isFound = result[0];
	cout << "The location and direction of the word is : " << result[0] << result[1] << result[2];

	// Check if word is not found
	if (isFound >= 0 ) {
		//cout << "\nEntering if...\n";
		
		// Turn color of the word that was found
		displayMatrix[result[1]][result[0]]->set_color(Color::red);
		for(int i =1; i < searchWord.size(); i++) {

			switch(result[2]) {
			// Paint text up
			case 1:
				displayMatrix[result[1]][result[0]-i]->set_color(Color::blue);
				break;

			// Paint chars down
			case 6:
				displayMatrix[result[1]][result[0]+i]->set_color(Color::blue);
				break;

			// Paint chars left
			case 3:
				displayMatrix[result[1]-i][result[0]]->set_color(Color::blue);
				break;
		

			// Paint chars right
			case 4:
				displayMatrix[result[1]+i][result[0]]->set_color(Color::blue);
				break;

			// Paint chars UL
			case 0:
				displayMatrix[result[1]-i][result[0]-i]->set_color(Color::blue);
				break;

			// Paint chars UR
			case 2:
				displayMatrix[result[1]+i][result[0]-i]->set_color(Color::blue);
				break;

			// Paint chars DL
			case 5:
				displayMatrix[result[1]-i][result[0]+i]->set_color(Color::blue);
				break;

			// Paint chars DR
			case 7:
				displayMatrix[result[1]+i][result[0]+i]->set_color(Color::blue);
				break;
			}
		}
	}

	redraw();
}

