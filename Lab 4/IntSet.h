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
// Class header file for dynamic array version of IntSet

#ifndef INTSET_H
#define INTSET_H

#include "Bugs.h"   // Necessary for IntSet-buggy.o

// This class is a container class that can hold as many integers as
// the amount of available memory allows.
// Only one instance of an integer is allowed and the order of the 
// integers in the IntSet is not guaranteed. The class provides member
// functions to insert and remove integers as well as return the 
// number of integers already in the IntSet.

// Class Invariants:
// - count is the number of integers contained in the IntSet
// - count >= 0
// - max is the current size of array (which is automatically expanded
//     when necessary)
// - max >= count

class IntSet
{
  public:

   IntSet();
   // Default constructor
   // POST: An empty IntSet is created

   IntSet( const IntSet& originalIntSet );
   // Copy constructor
   // POST: A new IntSet is created containing the same elements as 
   //       originalIntSet

   ~IntSet();
   // Destructor
   // POST: The IntSet object is destroyed

   void insert( int entry );
   // Mutator
   // POST: If entry is not already in the IntSet, then the entry is added
   //       Otherwise, nothing happens

   void erase( int target );
   // Mutator
   // POST: If target is in the IntSet, it is removed; otherwise nothing 
   //       happens

   int size() const;
   // Accessor
   // POST: number of elements in set is returned

   int get( int index ) const;
   // Accessor
    // POST:  if index is valid, the element at that index value is returned
    // otherwise an error message is printed and the program is terminated

   bool find( int target ) const;
   // Accessor
   // POST: If target is in the IntSet, it returns true; otherwise, it returns 
   //       false

   void print() const;
   // Accessor 
   // POST: The elements in the IntSet are printed out

   IntSet& operator=( const IntSet& otherIntSet );
   // Member operator function
   // POST:  The contents of 'otherIntSet' are copied into the current IntSet

   IntSet operator+( const IntSet& otherIntSet ) const;
   // Member operator function
   // POST: A new IntSet is returned that contains the current elements of 
   //       this IntSet plus the elements of otherIntSet

   IntSet operator*( const IntSet& otherIntSet ) const;
   // Member operator function
   // POST: A new IntSet is returned that contains the elements that are 
   //       contained in both this IntSet and in otherIntSet

  private:

   int* data;          // pointer to array to hold integers in the IntSet
   int  max;           // maximum number of items that can be held in the array
   int  count;         // number of integers stored in the array
   const static int INITSIZE  = 10;    // initial size of IntSet
   const static int INCREMENT = 5;     // amount to enlarge the array when full

   void copy( const IntSet& otherIntSet );
   // Private member function
   // POST: the array pointed to by otherIntSet.data is copied into the array 
   //       array pointed to by data

   void cleanup( void );
   // Private member function
   // POST: the array pointed to data deleted

   void grow( int amount );
   // Private member function
   // POST: If there is sufficient dynamic memory available, 'max' is 
   //       increased by 'amount' and the contents of data are copied into a 
   //       new array that can hold 'amount' more elements

};

#endif
