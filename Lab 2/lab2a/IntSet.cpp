// File:     IntSet.cpp
//
// Author:   Po Liu   
//           13623079          
//           x2f7           
//           L2A              
//
// Modified: 2008 January 18   *** Add a new date if you modify the file!
//           2007 January 15
//			 2010 June 25
//
// Source code for an object-oriented version of IntSet, a set of integers.
// This code is for use the debugger lab. We will look for the error
// that has been purposely put into the find() function.
//
// This is an array that can hold from 0 to 10 integers.
// Only one instance of an integer is allowed and the order of the 
// integers in the array is not guaranteed. There are methods
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

IntSet::IntSet()
// Default constructor
// PRE:  (none)
// POST: an empty IntSet is created
{
    count = 0;
}


void IntSet::insert( int entry )
// Mutator
// PRE:  (none)
// POST: If entry is not already in the IntSet and the IntSet is not full, 
//       then the entry is added, otherwise, the IntSet is unchanged.
//       If IntSet is full, an error message is printed and IntSet is
//       unchanged
// Library facilities used: cout object and operator<< from iostream
{
    if ( count >= CAPACITY )
    {
        cout << "Error! The IntSet is full." << endl;

        return;
    }

    if( !find( entry ) )
    {
        data[ count ] = entry;
        count++;
    }
}


void IntSet::erase( int target )
// Mutator
// PRE:  (none)
// POST: if target is in the IntSet, the target is removed from the IntSet;
//       otherwise nothing is done and the IntSet is unchanged
{

   // this function needs to be implemented!
   cerr << "The \"erase()\" method is not implemented yet!" << endl;

}


int IntSet::size() const
// Accessor member function
// PRE:  (none)
// POST: count is returned
{
    return count;
}


int IntSet::get( int index ) const
// Accessor
// PRE:   0 <= index < size()
// POST:  The element at that index value is returned
{
    return data[ index ];
}


bool IntSet::find( int target ) const
// Accessor 
// PRE:  (none)
// POST: If target is in the IntSet, it returns true; otherwise, it returns 
//       false
{
    for( int i = 0; i < count; i++ )    // Fixed bug
    {
        if ( data[ i ] == target )
        {
            return true;
        }
    }

    return false;
}


void IntSet::print() const
// Accessor
// PRE:  (none)
// POST: The elements in the IntSet are printed out
// Library facilities used: cout object and operator<< from iostream
{
    cout << "The IntSet has " << count << " elements:";

    for( int i = 0; i < count; i++ )
    {
        if ( i != 0 )
        {
            cout << ',';
        }

        cout << " " << data[ i ];
    }

    cout << "\n";
}
