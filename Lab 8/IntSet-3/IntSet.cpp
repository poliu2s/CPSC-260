// file: IntSet.cpp
// IntSet class source Version 3.2
// This class is an in-lab exercise and is incomplete

#include <iostream>    // used in print()
#include "IntSet.h"

using namespace std;

IntSet::IntSet()
// Default constructor
// PRE:  (none)
// POST: An empty IntSet is created
{
   count = 0;
   list = NULL;
}


IntSet::IntSet( const IntSet& originalIntSet )
// Copy constructor
// PRE:  (none)
// POST: A new IntSet is created containing the same elements as 
//       originalIntSet
{
   copy( originalIntSet );
}


IntSet::~IntSet()
// Destructor
// PRE:  (none)
// POST: The IntSet object is destroyed
{
   cleanup();
}


void IntSet::insert( int entry )
// Modification member function
// PRE:  (none)
// POST: If entry is not already in the IntSet, then the entry is added;
//       otherwise, set is not changed
{
   IntSetNode* newNode;

   if ( find( entry ) )
   {
      return;    // The element is already in the IntSet
   }

   // Construct a new node to hold this integer
   newNode = new IntSetNode;
   newNode->item = entry;

   // Insert the new node into our list
   newNode->next = list;
   list = newNode;

   // Increment the 'count' variable
   count++;
}


void IntSet::erase( int target )
// Modification member function
// PRE:  (none)
// POST: If target is in the IntSet, it is removed; otherwise set is not changed
{
   IntSetNode* ptr;    // Pointer that traverses the list to find the node

   // Is the list empty? If so, then there's nothing to be done
   if ( list == NULL )
   {
      return;
   }

   // Is the FIRST item the target? If so, simply delete it.
   if ( list->item == target )
   {
      IntSetNode* temp = list;    // Saves the node we need to delete.
      list = list->next;          // Remove the node from the list
      delete temp;                // Delete the saved node
      count--;                    // Decrement the count in the IntSet
      return;
   }

   // Searches the REST of the list for the target
   for( ptr = list;  ptr->next != NULL;  ptr = ptr->next )
   {
      if ( ptr->next->item == target )
      {
         IntSetNode* temp = ptr->next;    // Saves the node we need to delete
         ptr->next = ptr->next->next;     // Removes the node from the list
         delete temp;                     // Delete the saved node
         count--;                         // Decrement the count in the IntSet
         return;
      }
   }
}


int IntSet::size() const
// Accessor member function
// PRE:  (none)
// POST: count is returned
{
   return count;
}


int IntSet::get( int index ) const
// Accessor member function
// PRE:   0 <= index < ( size() - 1 )
// POST:  The element at that index value is returned
{
   IntSetNode* ptr;
   int i;

   ptr = list;   // IntSet the pointer to the FIRST node in the list

   for( i = 0;  i < index ; i++ )  // Skip the first 'index' number of nodes
   {
      ptr = ptr -> next;
   }

   return ptr->item;               // Return the item
}


bool IntSet::find( int target ) const
// Accessor member function
// PRE:  (none)
// POST: If target is in the IntSet, true is returned; 
// otherwise, false is returned
{
   // Pointer that traverses the list to find the node
   IntSetNode* ptr;

   for( ptr = list;  ptr != NULL;  ptr = ptr->next )
   {
     if ( ptr->item == target )
     {
        return true;
     }
   }

   return false;
}


void IntSet::print() const
// Accessor member function
// PRE:  (none)
// POST: The elements in the IntSet are printed out
// Library facilities used: cout object and operator<< from iostream
{
   // Pointer that traverses the list to find the node
   IntSetNode* ptr;

   cout << "The IntSet has " << count << " elements:";

   for( ptr = list;  ptr != NULL;  ptr = ptr->next )
   {
      if ( ptr != list )
      {
         cout << ',';
      }

      cout << " " << ptr->item;
   }

   cout << "\n";
}


IntSet& IntSet::operator=( const IntSet& otherIntSet )
// Member operator function
// PRE:  (none)
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
// Member operator function
// PRE:  (none)
// POST: A new IntSet is returned that contains the current elements of 
//       this IntSet plus the elements of otherIntSet
{
   IntSet temp( *this );
   IntSetNode* ptr;

   for( ptr = otherIntSet.list;  ptr != NULL;  ptr = ptr->next )
   {
      temp.insert( ptr->item );
   }

   return temp;
}


IntSet IntSet::operator*( const IntSet& otherIntSet ) const
// Member operator function
// PRE:  (none)
// POST: A new IntSet is returned that contains the elements that are 
//       contained in both this IntSet and in otherIntSet
{

	IntSet temp;

   // this function needs to be implemented
	for (int i = 0; i < this->size(); i++) {

		for (int j = 0; j < otherIntSet.size(); j++) {

			if (this->get(i) == otherIntSet.get(j)) {
				temp.insert(this->get(i));

			}

		}

	}

	return temp;
}


IntSet IntSet::odd() const
// Member function
// PRE:  (none)
// POST: A new IntSet is returned that contains only the odd elements
//       (those whose values are odd numbers) of this IntSet
{

   // this function needs to be implemented

   /*
   *  When implementing this function, do not use ANY of the
   *  the methods in the class EXCEPT for the default constructor.
   *  You must build the IntSet that will be returned "by hand"
   *  using low-level manipulations of the linked lists in the
   *  original IntSet and the new IntSet that is returned as the
   *  value of function.
   */
	
	IntSet temp;

	for (IntSetNode* i = list; i != NULL; i = i->next) {

		if (i->item % 2 != 0) {
			temp.insert(i->item);
			
			

		}
	}

	return temp;
}


void IntSet::copy( const IntSet& otherIntSet )
// Private member function
// PRE:  (none)
// POST: This IntSet's original items are freed, and the elements from the 
//       other IntSet is copied into this IntSet.
{
   IntSetNode* ptr;
   IntSetNode* newNode;

   count = otherIntSet.count;
   list = NULL;

   for( ptr = otherIntSet.list;  ptr != NULL;  ptr = ptr->next )
   {
      // Construct a new node with the given item
      newNode = new IntSetNode;
      newNode->item = ptr->item;

      // Insert it into the list
      newNode->next = list;
      list = newNode;
   }
}


void IntSet::cleanup( void )
// Private member function
// PRE:  (none)
// POST: all of the IntSetNodes pointed to list are deleted
{
   IntSetNode* target;  // address of the node to delete

   while( list != NULL)
   {
      target = list;
      list = list -> next;
      delete target;
   }
}
