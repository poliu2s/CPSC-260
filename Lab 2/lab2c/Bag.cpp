// file: Bag.cpp
//
// Bag class source
//
// Modified by K. S. Booth on 2007-Sep-21
//
// This is an in-lab exercise and is incomplete or incorrect.
// The problems should be identified using a debugger.

#include <iostream>    // used in insert() and print()
#include "Bag.h"

using namespace std;

Bag::Bag()
// Default constructor
// POST: an empty Bag is created
{
   count = 0;
}


void Bag::insert( int entry )
// Mutator
// POST: entry is added to the contents of the bag and the count is 
//       incremented
// Library facilities used: cout and operator<< from iostream
{
   if ( count > CAPACITY )
   {
      cout << "Bag is full\n";
   }
   else
   {
      data[ count ] = entry;
      count++;
   }
}


void Bag::remove( int target )
// Mutator
// POST: If target is in the Bag, ONE instance of the target is
//       removed, leaving others that may be present.
//
//       Otherwise nothing happens and the Bag remains unchanged.
{
   int i;

   for ( i = 0; i < count; i++ )
   {
     if (data[ i ] == target)
     {
        data[ i ] = data[ count ];
        count--;
     }
   }
}


int Bag::occurrences( int target ) const
// Accessor
// POST: the number of times target occurs in the Bag is returned
{
   int answer;
   int i;

   answer = 0;

   for ( i = 0; i < count; i++ )
   {
      if ( target = data[ i ] )
      {
         answer++;
      }
   }

   return answer;
}


int Bag::size() const
// Accessor
// POST: count is returned
{
   return count;
}


void Bag::print() const
// I/O function
// POST: The elements in the bag are printed out.
// Library facilities used: cout and operator<< from iostream
{
   int i;

   cout << "The bag has " << count << " elements:";

   for( i = 0; i < count; i ++ )
   {
      if ( i != 0 )
      {
         cout << ',';
      }
      cout << " " << data[ i ];
   }

   cout << "\n";
}
