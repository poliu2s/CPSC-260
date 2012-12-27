// File:     IntSet-driver.cpp
//
// Author:   Kellogg Booth     *** Your name ALWAYS goes here
//           12345678          *** Your ID number ALWAYS goes here
//           ksbooth           *** Your userID ALWAYS goes here
//           L2X               *** Your lab section ALWAYS goes here
//
// Modified: 2008 Feb 01       *** Add a new date if you modify the file!
//           2007 Oct 05
//
// Driver source file for dynamic array version of IntSet

// Set AT_HOME to "true" to indicate you are working at home, otherwise
// leave it "false" so the userID will be automatically set.

#define AT_HOME false

#include <iostream>    // cout, cin, operator>> and operator<<
#include "IntSet.h"

using namespace std;

int main()
{
    // Set the userID if working at home, and initialize for the bug being
    // tested by requesting a bug number from the user. A bug number of zero
    // means that no bugs will be present.

    if ( AT_HOME ) getBugUser( true ); // This will prompt you to type a userID
                                       // Use YOUR undergrad userid here!

    getBug( true );

    IntSet A;     // 1st IntSet for testing
    IntSet B;     // 2nd IntSet for testing
    IntSet C;     // 3rd IntSet for testing
    int entry;    // integer to be inserted or erased from an IntSet
	int choice;

    while( true )
    {
        cout << "\n"
        << "==================================================\n"
        << "\n"
        << "1. Attempt to insert a number to   IntSet A\n"
        << "2. Attempt to erase  a number from IntSet A\n"
        << "3. Attempt to insert a number to   IntSet B\n"
        << "4. Attempt to erase  a number from IntSet B\n"
        << "5. Determine size of IntSet A (zero) or B (not zero)\n"
        << "6. Get element i of IntSet A\n"
        << "7. Find element i in IntSet A\n"
        << "8. Assign C=A (zero) or C=B (not zero)\n"
        << "0. Exit\n"
        << "\n"
        << "Please input your choice: ";
        cin  >> choice;

        if ( choice == 0 )
        {
            break;
        }

        if ( choice < 1  ||  choice > 8 )
        {
            cout << "Choice is not valid. Please try again.\n";
            continue;
        }

        cout << "Please input the number: ";
        cin  >> entry;

        switch( choice )
        {
        case 1:
            A.insert( entry );
            break;
        case 2:
            A.erase( entry );
            break;
        case 3:
            B.insert( entry );
            break;
        case 4:
            B.erase( entry );
            break;
        case 5:
            cout << "\nSize of ";
            if ( entry ) cout << "B";
            else cout << "A";
            cout << " is ";
            if ( entry ) cout << B.size();
            else cout << A.size();
            break;
        case 6:
            cout << "\nEntry " << entry << " is " << A.get( entry );
            break;
        case 7:
            cout << "\nElement " << entry << " is";
            if (!A.find( entry ))
               cout << " not";
            cout << " in A";
            break;
        case 8:
            if ( entry ) C = B;
            else C = A;
            break;
        }

        cout << "\n";
        cout << "IntSet A                     : ";
        A.print();
        cout << "IntSet B                     : ";
        B.print();
        cout << "IntSet C                     : ";
        C.print();
        cout << "Union of IntSet A & B        : ";
        ( A + B ).print();
        cout << "Intersection of IntSet A & B : ";
        ( A * B ).print();

    }

    return 0;    // normal exit code
}
