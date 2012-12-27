

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 14th, 2010

// The user-defined class inputFormatter takes a string with file directories and 
// converts it into a format that c++ compiler can read

#ifndef INPUTFORMATTER
#define INPUTFORMATTER


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// class invariant: 

class inputFormatter {

public:
	inputFormatter();

	static string formatDirectory(string convertee);


};




#endif