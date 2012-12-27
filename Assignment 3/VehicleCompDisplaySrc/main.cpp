

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 22th, 2010





#include "Simple_window.h"
#include "std_lib_facilities.h"
#include "Graph.h"
#include <iostream>
#include <string>

#include "DisplaySleep.h"

// !!!!!! - User defined classes for this assignment (one of each used) - !!!!!!!!!
#include "data.h"		
#include "inputFormatter.h"	
#include "UpperGraph.h"
#include "MyList.h"
#include "LowerGraph.h"


using namespace std;


int main() {
	

	// Asks the user to enter the directory and file name
	cout << "Please enter the file name and directory of the vehicle data: " << endl;
	cout << "Note: the program will exit immediately if directory or file name does not exist" << endl;
	cout << "(Example: \"truck1.txt\" to use the file in this folder)" << endl << endl;
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

	// Prompt the user for millisecond input
	int numMilliseconds = 1;
	cout << "Please enter the pause interval in milliseconds: " << endl;
	cin >> numMilliseconds;
	


	// To store and process data of each time interval
	data intervalData;
	string tempLine;

	// Create new instances of UpperGraph and LowerGraph and declare a window for use
	UpperGraph graph1(60);
	LowerGraph graph2(60, 60);
	Window win1(Point(100, 100), 500, 700, "Vehicle Guage Data");
	
	
		
	// The main loop, executes for every line in the file
	while (getline(ifs, tempLine)) {
		cout << "Reading Line : " << tempLine << endl;

		// If file starts with '41' then process the info into intervalData
		if (tempLine.size() > 2 && tempLine[0] == '4' && tempLine[1] == '1') {		
			intervalData.update(tempLine);
		}

		
		// If hit a time, display the graphs for numMilliseconds interval
		if (tempLine.size() > 2 && tempLine[0] == 'T') { 
			
			cout << intervalData.getThrottlePosition();
			graph1.update(intervalData.getThrottlePosition());
			graph2.update(intervalData.getEngineRPM(), intervalData.getVehicleSpeed());
			
						
			graph1.display(win1);
			graph2.display(win1);
			
			DisplaySleep(numMilliseconds);
			graph1.detach(win1);
			graph2.detach(win1);

						
		}
	}
	
	cout << "\nReached the end of the file." << endl;

	
	return 0;
}