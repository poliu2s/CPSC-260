
//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 14th, 2010

// The user-defined class data collects vechicle gauage data from truck1.txt or truck2.txt
// and places it into its instance variables

#include "data.h"
#include <iostream>
#include <string>
#include <sstream>


// Class invariant: given input line through update() with OBD-II conventions,
//					the instance variables will correlate to pre-determined vehicle values


using namespace std;

	
//the following four methods are helper functions
	
//convert int to string
string data::stringConverter(int num){
	stringstream is;
	is << num;
	string temp = is.str();
	return temp;
}

//translate a single digit hex number into a decimal number
int data::hexTranslator(char num){
	
	switch (num) {
	case 'A':
		return 10;
	case 'B':
		return 11;

	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		cout << "Error did not find a number!!!";

	}
}

//convert a 2 digits hex number into a decimal number
	
int data::hexConverter(char left, char right){
	return hexTranslator(left)*16 + hexTranslator(right);
}
	
	

data::data(){
	throttlePosition=engineRPM=vehicleSpeed=airIntakeTemp=engineLoad=massAirFlow=enginCoolantTemp=0;
}

//for the following 7 methods:
//pre: none
//post: return the corresponding instance variable
	
string data::getThrottlePosition() {return stringConverter(throttlePosition);}

string data::getEngineRPM() {return stringConverter(engineRPM);}

string data::getVehicleSpeed() {return stringConverter(vehicleSpeed);}

string data::getAirIntakeTemp() {return stringConverter(airIntakeTemp);}

string data::getEngineLoad() {return stringConverter(engineLoad);}

string data::getMassAirFlow() {return stringConverter(massAirFlow);}

string data::getEnginCoolantTemp() {return stringConverter(enginCoolantTemp);}
	

//pre: none
//post: an instance variable will be updated depending on the type and the corresponding formula the parameter indicates 
void data::update(string newData){
	string type = "";
	type = newData[2];
	type += newData[3];	
		
	if (type == "11"){
		int a = hexConverter( newData[4],  newData[5]);
		throttlePosition = a*100/255;
		
	}

	else if(type == "0D")
		vehicleSpeed = hexConverter( newData[4],  newData[5]);

	else if(type == "10"){
		int a = hexConverter( newData[4],  newData[5]);
		int b = hexConverter( newData[6],  newData[7]);
		massAirFlow = ((256*a)+b)/100;
	}

	else if(type == "04"){
		int a = hexConverter( newData[4],  newData[5]);
		engineLoad = a*100/255;
	}

	else if(type == "0F"){
		int a = hexConverter( newData[4],  newData[5]);
		airIntakeTemp = a-40;
	}

	else if(type == "0C"){
		int a = hexConverter( newData[4],  newData[5]);
		int b = hexConverter( newData[6],  newData[7]);
		engineRPM = ((a*256)+b)/4;
	}

	else{  //05
		int a = hexConverter( newData[4],  newData[5]);
		enginCoolantTemp = a - 40;
	}



}

