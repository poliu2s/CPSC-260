// File:     IntSet.h
//
// Author:   Kellogg Booth     *** Your name ALWAYS goes here
//           12345678          *** Your ID number ALWAYS goes here
//           ksbooth           *** Your userID ALWAYS goes here
//           L2X               *** Your lab section ALWAYS goes here
//
// Modified: 2008 January 22   *** Add a new date if you modify the file!
//           2007 January 15
//
// Header file for Version 1 of Intset, a set of integers

#ifndef INTSET_H
#define INTSET_H

#include "Bugs.h"   // Necessary for IntSet-buggy.o

class IntSet

   // This class is a container class that can hold from 0 to 10 integers.
   // Only one instance of an integer is allowed and the order of the 
   // integers in the IntSet is not guaranteed. The class provides member
   // functions to insert and remove integers as well as return the 
   // number of integers already in the IntSet.

   // Class Invariants:
   // - 0 <= count <= 10
   // - count is the number of integers contained in the IntSet
   // - for 0 <= i < count each data[i] is a unique integer
   //
   // Library facilities used: cout object and operator<< from iostream
{
public:

    IntSet();
    // Default constructor
    // PRE:  (none)
    // POST: an empty IntSet is created

    void insert( int entry );
    // Mutator
    // PRE:  (none)
    // POST: If entry is not already in the IntSet and the IntSet is not full, 
    //       then the entry is added, otherwise, the IntSet is unchanged.
    //       If IntSet is full, an error message is printed and IntSet is
    //       unchanged

    void erase( int target );
    // Mutator
    // PRE:  (none)
    // POST: if target is in the IntSet, the target is removed from the IntSet;
    //       otherwise nothing is done and the IntSet is unchanged

    int size() const;
    // Accessor member function
    // PRE:  (none)
    // POST: count is returned

    int get( int index ) const;
    // Accessor
    // PRE:   0 <= index < size()
    // POST:  The element at that index value is returned (the return
    //        value is undefined if index is out of range)

    bool find( int target ) const;
    // Accessor 
    // PRE:  (none)
    // POST: If target is in the IntSet, it returns true; otherwise, it returns 
    //       false

    void print() const;
    // Accessor
    // PRE:  (none)
    // POST: The elements in the IntSet are printed out
    // Library facilities used: cout object and operator<< from iostream

    static const int CAPACITY = 10;   // capacity of set (this is public!)

private:

    int  data[ CAPACITY ]; // array to hold integers in the IntSet
    int  count;            // number of integers stored in the array
};

#endif
