// file: Bag.h
// Bag class header
// This is an in-lab exercise and is incomplete or incorrect

#ifndef BAG_H
#define BAG_H

// This class is a container class that can hold from 0 to 100 integers.
// More than one instance of an integer is allowed and the order of the 
// the integers in the bag is not guaranteed. The class provides 
// member functions to insert and remove integers as well as return the 
// number of integers already in the Bag.

// Class Invariants:
// - count >= 0
// - count <= 100
// - count is the number of integers contained in the Bag

class Bag
{
public:

    Bag();
    // Default constructor
    // POST: an empty Bag is created

    void insert( int entry );
    // Mutator
    // POST: entry is added to the contents of the bag and the count is 
    //       incremented

    void remove( int target );
    // Mutator
    // POST: if target is in the Bag, one instance of target is removed, 
    //       otherwise nothing happens

    int occurrences( int target ) const;
    // Accessor
    // POST: the number of times target occurs in the Bag is returned

    int size() const;
    // Accessor
    // POST: count is returned

    void print() const;
    // I/O function
    // POST: The elements in the bag are printed out.

private:

    static const int CAPACITY = 100;   // capacity of the Bag
    //enum{ CAPACITY = 100 };          // comment-out previous line and use this one for MS compiler
    int data[ CAPACITY ];              // array to hold integers in the Bag
    int count;                         // number of integers stored in the array

};

#endif
