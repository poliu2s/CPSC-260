

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 14th, 2010


// The user-defined class data collects vechicle gauage data from truck1.txt or truck2.txt
// and places it into its instance variables

#ifndef DATA_H
#define DATA_H


#include <iostream>
#include <string>
#include <sstream>

using namespace std;


// Class invariant: given input line through update() with OBD-II conventions,
//					the instance variables will correlate to pre-determined vehicle values

class data {
	int throttlePosition, engineRPM, vehicleSpeed, airIntakeTemp, engineLoad, massAirFlow, enginCoolantTemp;

	//the following four methods are helper functions
public:
	//convert int to string
	string stringConverter(int num);

	//translate a single digit hex number into a decimal number
	int hexTranslator(char num);
	

	//convert a 2 digits hex number into a decimal number
	int hexConverter(char left, char right);

	
	data();

	//for the following 7 methods:
	//pre: none
	//post: return the corresponding instance variable
	string getThrottlePosition();

	string getEngineRPM();

	string getVehicleSpeed();

	string getAirIntakeTemp();

	string getEngineLoad();

	string getMassAirFlow();

	string getEnginCoolantTemp();

	//pre: none
	//post: an instance variable will be updated depending on the type and the corresponding formula the parameter indicates 
	void update(string newData);


};



#endif
