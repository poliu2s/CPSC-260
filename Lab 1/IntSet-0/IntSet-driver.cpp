// File:     IntSet-driver.cpp
//
// Author:   Kellogg Booth     *** Your name ALWAYS goes here
//           12345678          *** Your ID number ALWAYS goes here
//           ksbooth           *** Your userID ALWAYS goes here
//           L20               *** Your lab section ALWAYS goes here
//
// Modified: 2008 January 11   *** Add a new date if you modify the file!
//           2007 January 15
//
// Test driver source for Version 0 of IntSet, a set of integers
 
#include <iostream>    // cout and cin
#include "IntSet.h"

using namespace std;

int main( int argc, char* argv[] )
{
    // Initialize the bug testing (if we are doing it)
    getBug( true );

    // Initialize the IntSet
    init();

    int choice;   // command number
    int entry;    // integer to be inserted or erased from an IntSet

    while( true )
    {
        cout << "\n"
        << "==================================================\n"
        << "\n"
        << "1. Attempt to insert a number to the IntSet\n"
        << "2. Attempt to erase a number from the IntSet\n"
        << "5. Determine the size of the IntSet\n"
        << "6. Get element i of the IntSet\n"
        << "7. Find element i in the IntSet\n"
        << "0. Exit\n"
        << "\n"
        << "Please input your choice: ";
        cin  >> choice;

        if ( choice == 0 )
        {
            break;
        }

        if ( choice < 1  ||  choice > 7 || (choice > 2) && (choice < 5) )
        {
            cout << "*** Choice is not valid. Please try again.\n";
            continue;
        }

        if ( choice != 5 )
        {
           cout << "Please input the number: ";
           cin  >> entry;
        }

        switch( choice )
        {
        case 1:
            insert( entry );
            break;
        case 2:
            erase( entry );
            break;
        case 5:
            cout << "\nSize of " << size();
            break;
        case 6:
            cout << "\nEntry " << entry << " is " << get( entry );
            break;
        case 7:
            cout << "\nElement " << entry << " is";
            if (!find( entry ))
               cout << " not";
            cout << " in the IntSet";
            break;
        }

        cout << "\n";
        cout << "The properties and content of the IntSet are:" << endl;
        print();
    }

    return 0;    // normal exit code
}
