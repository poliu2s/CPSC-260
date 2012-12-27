// File:     IntSet.cpp
//
// Author:   Kellogg Booth     *** Your name ALWAYS goes here
//           12345678          *** Your ID number ALWAYS goes here
//           ksbooth           *** Your userID ALWAYS goes here
//           L20               *** Your lab section ALWAYS goes here
//
// Modified: 2008 January 11   *** Add a new date if you modify the file!
//           2007 January 15
//
// Source code for Version 0 of IntSet, a set of integers.
//
// This is an array that can hold from 0 to 10 integers.
// Only one instance of an integer is allowed and the order of the 
// integers in the array is not guaranteed. There are functions
// to insert and remove integers as well as return the 
// number of integers already in the array.

// Invariants:
//
// - 0 <= count <= 10
// - count is the number of integers contained in the array
// - for 0 <= i < count each IntSet[i] is a unique integer
//
// Library facilities used: cout

#include <iostream>    // used in insert() and print()
#include "IntSet.h"

using namespace std;

/* The following two functions are here only to maintain compatibility
*  with the but testing version of the code.
*/

void setBug( int i, bool verbose )
// Dummy version of setBug() that does nothing
// PRE:  (none)
// POST: (none)
{
}

void getBug(bool verbose )
// Dummy version of getBug() that does nothing
// PRE:  (none)
// POST: (none)
{
}

static const int CAPACITY = 10;   // capacity of the array

static int data[ CAPACITY ];      // array to hold integers in the IntSet
static int counter;               // number of integers stored in the array
                                  /*
                                     NOTE: For technical reason this variable
                                     is named "counter" instead of "count".
                                     later versions of IntSet will use "count"
                                     instead.
                                  */

void init()
// Initialize the IntSet array and count
// PRE:  (none)
// POST: the IntSet is empty (no elements)
{
    counter = 0;
}


void insert( int entry )
// Mutator
// PRE:  (none)
// POST: If entry is not already in the IntSet and the IntSet is not full, 
//       then the entry is added, otherwise, the IntSet is unchanged.
//       If IntSet is full, an error message is printed and IntSet is
//       unchanged
{
    if ( counter >= CAPACITY )
    {
        cerr << "*\n *\n  *\n   *\n    * Error! The IntSet is full." << endl;
        return;
    }

    if( !find( entry ) )
    {
        data[ counter ] = entry;
        counter++;
    }
}


void erase( int target )
// Mutator
// PRE:  (none)
// POST: if target is in the IntSet, the target is removed from the IntSet;
//       otherwise nothing is done and the IntSet is unchanged
{

   // this function needs to be implemented!
   cerr << "*\n *\n  *\n   *\n    * Error! The \"erase()\" method is not implemented yet!" << endl;

}


int size()
// Accessor
// PRE:   0 <= index < size()
// POST:  The element at that index value is returned (the return
//        value is undefined if index is out of range)
{
    return counter;
}


int get( int index )
// Accessor
// PRE:   0 <= index < size()
// POST:  The element at the index value is returned (the return
//        value is undefined if index is out of range)
{
    return data[ index ];
}


bool find( int target )
// Accessor 
// PRE:  (none)
// POST: If target is in the IntSet, it returns true; otherwise, it returns 
//       false
{
    for( int i = 0; i < counter; i++ )
    {
        if ( data[ i ] == target )
        {
            return true;
        }
    }

    return false;
}


void print()
// Accessor
// PRE:  (none)
// POST: The elements in the IntSet are printed out
// Library facilities used: cout object and operator<< from iostream
{
    cout << "The IntSet has " << counter << " element";
    if ( counter == 1 ) cout  << ":";
    else cout  << "s:";

    for( int i = 0; i < counter; i++ )
    {
        if ( i != 0 )
        {
            cout << ',';
        }

        cout << " " << data[ i ];
    }

    cout << "\n";
}
