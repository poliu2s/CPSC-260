// file: IntSet.h
// IntSet class header Version 3.2
// This class is an in-lab exercise and is incomplete

#ifndef INTSET_H
#define INTSET_H

// This class is a container class that can hold as many integers as
// the amount of available memory allows.
// Only one instance of an integer is allowed and the order of the 
// integers in the IntSet is not guaranteed. The class provides member
// functions to insert and remove integers as well as return the 
// number of integers already in the IntSet.

// Class Invariants:
// - count is the number of integers contained in the IntSet
// - count >= 0

class IntSet
{
  public:

   IntSet();
   // Default constructor
   // PRE:  (none)
   // POST: An empty IntSet is created

   IntSet( const IntSet& originalIntSet );
   // Copy constructor
   // PRE:  (none)
   // POST: A new IntSet is created containing the same elements as 
   //       originalIntSet

   ~IntSet();
   // Destructor
   // PRE:  (none)
   // POST: The IntSet object is destroyed

   void insert( int entry );
   // Mutator member function
   // PRE:  (none)
   // POST: If entry is not already in the IntSet, then the entry is added;
   //       otherwise, set is not changed

   void erase( int target );
   // Mutator member function
   // PRE:  (none)
   // POST: If target is in the IntSet, it is removed; otherwise set is not changed

   int size() const;
   // Accessor member function
   // PRE:  (none)
   // POST: count is returned

   int get( int index ) const;
   // Accessor member function
   // PRE:   0 <= index < ( size() - 1 )
   // POST:  The element at that index value is returned

   bool find( int target ) const;
   // Accessor member function
   // PRE:  (none)
   // POST: If target is in the IntSet, true is returned; otherwise, 
   // false is returned

   void print() const;
   // Accessor member function
   // PRE:  (none)
   // POST: The elements in the IntSet are printed out

   IntSet& operator=( const IntSet& otherIntSet );
   // Member operator function
   // PRE:  (none)
   // POST:  The contents of 'otherIntSet' are copied into the current IntSet

   IntSet operator+( const IntSet& otherIntSet ) const;
   // Member operator function
   // PRE:  (none)
   // POST: A new IntSet is returned that contains the current elements of 
   //       this IntSet plus the elements of otherIntSet

   IntSet operator*( const IntSet& otherIntSet ) const;
   // Member operator function
   // PRE:  (none)
   // POST: A new IntSet is returned that contains the elements that are 
   //       contained in both this IntSet and in otherIntSet

   IntSet odd() const;
   // Member function
   // PRE:  (none)
   // POST: A new IntSet is returned that contains only the odd elements
   //       (those whose values are odd numbers) of this IntSet

   void mystery( int x );
   // Member function
   // PRE:  (none)
   // POST: A mystery modification is made to the IntSet.

  private:

   struct IntSetNode
   // This struct defines the Node of the singly linked list.
   {
      int      item;
      IntSetNode* next;
   };
   
   IntSetNode* list;    // pointer to a singly linked list of IntSet 'elements'
   int  count;          // number of integers stored in the list

   void copy( const IntSet& otherIntSet );
   // Private member function
   // PRE:  (none)
   // POST: This IntSet's original items are freed, and the elements from the 
   //       other IntSet is copied into this IntSet.

   void cleanup( void );
   // Private member function
   // PRE:  (none)
   // POST: the array pointed to data deleted

};

#endif
