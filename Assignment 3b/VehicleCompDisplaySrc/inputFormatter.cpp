

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 14th, 2010

// The user-defined class inputFormatter takes a string with file directories and 
// converts it into a format that c++ compiler can read

#include "inputFormatter.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


// empty constructor
inputFormatter::inputFormatter() {
		};


// Converts '/' in entered file names to "\\"
//pre: none
//post: string returned with '/' replaced with '\\' character
string inputFormatter::formatDirectory(string convertee) {
	string searchString = "/";
	string replaceString = "\\";
	

	string::size_type pos = 0;
    while ( (pos = convertee.find(searchString, pos)) != string::npos ) {
        convertee.replace( pos, 1, replaceString );
		convertee.insert( pos, replaceString );
        pos++;
    }

	return convertee;
	
	
}
	


