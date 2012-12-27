// File:     IntSet-driver.cpp
//
// Author:   Po Liu  
//           13623079         
//           x2f7        
//           L2A             
//
// Modified: 2008 January 22   *** Add a new date if you modify the file!
//           2007 January 15
//			 2010 June 25
//
// Test driver source for Version 1 of IntSet, a set of integers
//
// This is for an in-lab exercise
 
#include <iostream>    // cout, cin, operator>> and operator<<
#include "IntSet.h"

using namespace std;

int main()
{
   // Initialize the IntSet class for the bug being tested.
   // A bug number of zero means no bugs present.

    getBug( true );

    int choice;   // command number

    IntSet A;     // 1st IntSet for testing
    IntSet B;     // 2nd IntSet for testing
    int entry;    // integer to be inserted or erased from an IntSet

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
        << "0. Exit\n"
        << "\n"
        << "Please input your choice: ";
        cin  >> choice;

        if ( choice == 0 )
        {
            break;
        }

        if ( choice < 1  ||  choice > 7 )
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
        }

        cout << "\n";
        cout << "IntSet A                     : ";
        A.print();
        cout << "IntSet B                     : ";
        B.print();
    }

    return 0;    // normal exit code
}
