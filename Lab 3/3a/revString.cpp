// File:     revString.cpp
//
// Author:   Po Liu     *** Your name ALWAYS goes here
//           13623079          *** Your ID number ALWAYS goes here
//           x2f7           *** Your userID ALWAYS goes here
//           L2A               *** Your lab section ALWAYS goes here
//
// Modified: 29 June 2010
//			 2008 January 24   *** Add a new date if you modify the file!
//           2007 September 30
//
// This is an inlab exercise and is incomplete.
//
// The program currently prints a list of words in the order they
// apppear on the input lines.
//
// Students will adapt the program to print all of the words on the
// input lines in REVERSE.

#include <iostream>
#include <string>
#include <sstream>    // for string streams (see NOTE below)
#include <stack>

using namespace std;

int main()
{
    string line;	// string variable to hold one line of input characters
    string word;	// string variable to hold one word of characters

    cout << "enter a line: ";	// prompt for input (no CR at end)
    getline( cin, line );	// read one full line of characters

    // Open a stream bound to the string variable "line" (which was declared
    // above) by declaring a new variable "input" whose type is "istringstream"
    // and which is initialized by its constructor to get its input from the
    // variable "line".
    istringstream input( line.c_str() );


	stack<string> allwords;




    // At this point the variable "input" acts like an input file.
    // All of the characters read into line can now be re-read from input.

    // Because the variable "word" is a string, we can get each block
    // of non-blank characters one at a time using the >> operator
    // and then write these out one per line for output
    while ( input >> word )
    {
        allwords.push(word);

	}

	while (!allwords.empty()) {
		cout << allwords.top() << " ";
		allwords.pop();
	}

	cout << endl;

    return 0;

/* NOTE:
*
*  If our program had instead been simply the following, which does not
*  first read the input line into a string and then use the string as
*  if it were a file, we would read multiple lines from the input, not
*  just a single line.
*
*   while ( cin >> word )
*   {
*       cout << word << endl;
*   }
*
*   There is nothing wrong with this approach, except that we only want
*   to process a SINGLE line at a time in this lab exercise.
*/

}
