// File:     IntSet-driver.h
//
// Author:   Kellogg Booth     *** Your name ALWAYS goes here
//           12345678          *** Your ID number ALWAYS goes here
//           ksbooth           *** Your userID ALWAYS goes here
//           L2X               *** Your lab section ALWAYS goes here
//
// Modified: 2008 Feb 01       *** Add a new date if you modify the file!
//           2007 Oct 05
//
// Class sources file for dynamic array version of IntSet
//
// This class is an in-lab exercise and is incomplete

#include <iostream>    // used in print()
#include <cstdlib>     // for exit() function used in get() 
#include "IntSet.h"

using namespace std;

IntSet::IntSet()
// Default constructor
// POST: An empty IntSet is created
{
    max = INITSIZE;
    count = 0;
    data = new int[ max ];
}


IntSet::IntSet( const IntSet& originalIntSet )
// Copy constructor
// POST: A new IntSet is created containing the same elements as 
//       originalIntSet
{
    copy( originalIntSet );
}


IntSet::~IntSet()
// Destructor
// POST: The IntSet object is destroyed
{
    cleanup();
}


void IntSet::insert( int entry )
// Mutator
// POST: If entry is not already in the IntSet, then the entry is added
//       Otherwise, nothing happens
{
    if ( find( entry ) )
    {
        return;   // The element is already in the IntSet
    }

    if ( count == max )
    {
        grow( INCREMENT );
    }

    data[ count ] = entry;
    count++;
}


void IntSet::erase( int target )
// Mutator
// POST: If target is in the IntSet, it is removed; otherwise nothing 
//       happens
{
    for( int i = 0; i < count; i++ )
    {
        if ( data[ i ] == target )
        {
             data[ i ] = data[ --count ];  // WHAT DOES THIS DO?
             return;
        }
    }
}


int IntSet::size() const
// Accessor 
// POST: count is returned
{
    return count;
}


int IntSet::get( int index ) const
// Accessor 
// POST:  if index is valid, the element at that index value is returned
// otherwise an error message is printed and the program is terminated
{
    if (index < 0 || index >= count)
    {
        cout << "Error! The index " << index << " is out of range!" << endl;
        exit( 1 );
    }

    return data[ index ];
}


bool IntSet::find( int target ) const
// Accessor 
// POST: If target is in the IntSet, it returns true; otherwise, it returns 
//       false
{
    for( int i = 0; i < count; i++ )
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


IntSet& IntSet::operator=( const IntSet& otherIntSet )
// Member overloaded assignment operator function
// POST:  The contents of 'otherIntSet' are copied into the current IntSet
{
    if ( &otherIntSet != this )
    {
        cleanup();
        copy( otherIntSet );
    }

    return *this;
}


IntSet IntSet::operator+( const IntSet& otherIntSet ) const
// Member union operator function
// POST: A new IntSet is returned that contains the current elements of 
//       this IntSet plus the elements of otherIntSet
{
    IntSet temp( *this );

    temp.grow( otherIntSet.count );

    for ( int i = 0; i < otherIntSet.count; i++ )
    {
        temp.insert( otherIntSet.data[ i ] );
    }

    return temp;
}


IntSet IntSet::operator*( const IntSet& otherIntSet) const
// Member intersection operator function
// PRE:  otherIntSet is a valid IntSet
// POST: A new IntSet is returned that contains the elements that are 
//       contained in both this IntSet and in otherIntSet
{
    IntSet temp2( *this );
	
	IntSet temp;
	
	for (int i = 0; i < otherIntSet.count; i++ ) {
		if ( temp2.find(otherIntSet.get(i) ) )
				
				temp.insert( otherIntSet.data[i] );
	}
	
    // ----------------------------------------------------------------
    // This function needs to be implemented!
    // Replace these comments and the following code with your
    // implementation.
    // cout << "The intersection operator is not implemented yet!" << endl;
    
	return temp;
    // ----------------------------------------------------------------
}


void IntSet::copy( const IntSet& otherIntSet )
// Private member helper function
// POST: the array pointed to by otherIntSet.data is copied into the array 
//       array pointed to by data
{
    max = otherIntSet.max;
    count = otherIntSet.count;
    data = new int[ max ];

    for ( int i = 0; i < count; i++ )
    {
        data[ i ] = otherIntSet.data[ i ];
    }
}



void IntSet::cleanup( void )
// Private member helper function
// POST: the array pointed to data deleted
{
    delete [] data;
}


void IntSet::grow( int amount )
// Private member helper function
// POST: If there is sufficient dynamic memory available, 'max' is 
//       increased by 'amount' and the contents of data are copied into a 
//       new array that can hold 'amount' more elements
{
    int* temp;

    max = max + amount;
    temp = new int[ max ];

    for ( int i = 0; i < count; i++ )
    {
        temp[ i ] = data[ i ];
    }

    delete [] data;
    data = temp;
}
