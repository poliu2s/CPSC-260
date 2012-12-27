

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 14th, 2010





#include "Simple_window.h"
#include "std_lib_facilities.h"
#include "Graph.h"
#include <iostream>
#include <string>

#include "DisplaySleep.h"

// !!!!!! - User defined classes for this assignment (one of each used) - !!!!!!!!!
#include "data.h"		
#include "inputFormatter.h"		


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
	// Used an instance of a user defined type!!!-----------------------------------------------
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
	int numMilliseconds;
	cout << "Please enter the pause interval in milliseconds: " << endl;
	cin >> numMilliseconds;
	

	// Draw the window
	Window win1(Point(100, 100), 600, 400, "Vehicle Guage Data");

	//Timer maintenance variables
	double i = 0.0;
	int textX = 100;
	int numX = 350;
	bool isDecimal = false;
	
	// A variable used to temporary store each line of the read file
	string tempLine;

	// Collect all values into this object for display when reading
	// Used an instance of a user defined type!!! -----------------------------------------
	data object1;
		

	// Main input loop -- reads line by line-------------------------------------------------------------------
	while (getline(ifs, tempLine)) {
		cout << "Reading Line : " << tempLine << endl;

		// Updates the instance variables if the line starts with 41
		if (tempLine.size() > 2 && tempLine[0] == '4' && tempLine[1] == '1') {		

			object1.update(tempLine);
		}
		
		// If it hits a line that has 'Time' then update the object instance variables and display them
		if (tempLine.size() > 2 && tempLine[0] == 'T') { 
	
			// To display timer
			ostringstream oss;
			oss << i;
			string timerText = "[Run Time] ";
			timerText += oss.str();
			
			
			// Check if need to add ".0" decimal to ints
			if (isDecimal == false) {
				timerText += ".0";
				isDecimal = true;
			}
			else { 
				isDecimal = false;
			}
			timerText += " seconds";
			

			// Set up the timer display
			Text timer(Point(70, 50), timerText);
			timer.set_font(Font::times_bold);
			timer.set_font_size(40);
			

			// Strings to be displayed on gauge
			string TP =   "Throttle Position: ";
			string ERPM = "Engine RPM: ";
			string VS =   "Vehicle Speed:  ";
			string AIT =  "Air Intake Temperature:   ";
			string EL =   "Engine Load:  ";
			string MAF =  "Mass Air Flow: ";
			string ECT =  "Engine Coolant Temperature:   ";


			string nTP = object1.getThrottlePosition();
			string nERPM = object1.getEngineRPM();
			string nVS = object1.getVehicleSpeed();
			string nAIT = object1.getAirIntakeTemp();
			string nEL = object1.getEngineLoad();
			string nMAF = object1.getMassAirFlow();
			string nECT = object1.getEnginCoolantTemp();
		
			nTP += " %";
			nERPM += " rpm";
			nVS += " km/h";
			nAIT += " deg C";
			nEL += " %";
			nMAF += " g/s";
			nECT += " deg C";

			

			// Vechicle Gauge Display Texts
			Text t_throttlePosition(Point(textX, 100), TP);
			Text t_engineRPM(Point(textX, 120), ERPM);
			Text t_vehicleSpeed(Point(textX, 140), VS);
			Text t_airIntakeTemperature(Point(textX, 160), AIT);
			Text t_engineLoad(Point(textX, 180), EL);
			Text t_massAirFlow(Point(textX, 200), MAF);
			Text t_engineCoolantTemperature(Point(textX, 220), ECT);

			Text n_throttlePosition(Point(numX, 100), nTP);
			Text n_engineRPM(Point(numX, 120), nERPM);
			Text n_vehicleSpeed(Point(numX, 140), nVS);
			Text n_airIntakeTemperature(Point(numX, 160), nAIT);
			Text n_engineLoad(Point(numX, 180), nEL);
			Text n_massAirFlow(Point(numX, 200), nMAF);
			Text n_engineCoolantTemperature(Point(numX, 220), nECT);


			// Update Colors
			timer.set_color(Color::black);
			
			t_throttlePosition.set_color(Color::black);
			t_engineRPM.set_color(Color::black);
			t_vehicleSpeed.set_color(Color::black);
			t_airIntakeTemperature.set_color(Color::black);
			t_engineLoad.set_color(Color::black);
			t_massAirFlow.set_color(Color::black);
			t_engineCoolantTemperature.set_color(Color::black);

			n_throttlePosition.set_color(Color::black);
			n_engineRPM.set_color(Color::black);
			n_vehicleSpeed.set_color(Color::black);
			n_airIntakeTemperature.set_color(Color::black);
			n_engineLoad.set_color(Color::black);
			n_massAirFlow.set_color(Color::black);
			n_engineCoolantTemperature.set_color(Color::black);
			

			//Attach everything to window
			win1.attach(timer);
			
			win1.attach(t_throttlePosition);
			win1.attach(t_engineRPM);
			win1.attach(t_vehicleSpeed);
			win1.attach(t_airIntakeTemperature);
			win1.attach(t_engineLoad);
			win1.attach(t_massAirFlow);
			win1.attach(t_engineCoolantTemperature);

			win1.attach(n_throttlePosition);
			win1.attach(n_engineRPM);
			win1.attach(n_vehicleSpeed);
			win1.attach(n_airIntakeTemperature);
			win1.attach(n_engineLoad);
			win1.attach(n_massAirFlow);
			win1.attach(n_engineCoolantTemperature);
			
			// Redraw the window after attaching components
			win1.redraw();
			Fl::check();
			DisplaySleep(numMilliseconds);

			// Detach everything - prevents memory leaks
			win1.detach(timer);
			
			win1.detach(t_throttlePosition);
			win1.detach(t_engineRPM);
			win1.detach(t_vehicleSpeed);
			win1.detach(t_airIntakeTemperature);
			win1.detach(t_engineLoad);
			win1.detach(t_massAirFlow);
			win1.detach(t_engineCoolantTemperature);

			win1.detach(n_throttlePosition);
			win1.detach(n_engineRPM);
			win1.detach(n_vehicleSpeed);
			win1.detach(n_airIntakeTemperature);
			win1.detach(n_engineLoad);
			win1.detach(n_massAirFlow);
			win1.detach(n_engineCoolantTemperature);
			
		
			// Update the timer i integer
			i += 0.5;
		}
		
	}
	
	cout << "\nReached the end of the file." << endl;

	
	return 0;
}