// file: CDList.cpp
// CDList class source
// This is an in-lab exercise and is incomplete or incorrect

#include <iostream>    // used in print()
#include <string>
#include "CDList.h"

using namespace std;

CDList::CDList()
// Default constructor
// PRE:  none
// POST: an empty CDList is created
{
	count = 0;
	head = NULL;
	return;
}


void CDList::insert( const string& title, const string& artist )
// Modification member function that inserts a CD into the CDList
// PRE:  title and artist are valid strings
// POST: the CD is added to the CDList
{
   CDListNode* newNode;

   newNode = new CDListNode;
   newNode->title = title;
   newNode->artist = artist;
   newNode->next = head;
   head = newNode;
   count++;
}


bool CDList::remove( const string& title, const string& artist )
// Modification member function that removes an instance of a CD from the 
// CDList
// PRE:  title and artist are valid strings
// POST: an instance of the CD of the given title by the given artist is 
//       removed from the CDList; returns true if successful, otherwise false
{
   CDListNode* iPtr;
   CDListNode* jPtr;

   iPtr = NULL;
   jPtr = head;

   cout << jPtr->title << endl;
   cout << jPtr->next->title << endl;

   // Search through the list until we fine the given title and artist
   while ( jPtr != NULL && jPtr->title != title || jPtr->artist != artist )
   {
      cout << "In while: " << jPtr->title << endl;
	  cout << "In while: " << jPtr->next->title << endl;

	  iPtr = jPtr;
      jPtr = jPtr->next;

	  
   }

   cout << "While loop done" << endl;
   
   cout << "jPtr = " << jPtr->title << endl <<endl;

   /*
   if (jPtr->title != title) {
		//cout << jPtr->title << jPtr->next->title;
	   iPtr = jPtr;
	   jPtr = jPtr->next;
	   delete jPtr;
	   return true;

   }
   */

   // If we found what the given title and artist, remove it from the list
   if ( jPtr != NULL )
   {
      // See if this is NOT the first CD in the list
      if ( iPtr != NULL )
      {
         iPtr->next = jPtr->next;
      }
	  
      // If it is the first CD in the list, treat it as a special case
      else
      {
         head = jPtr->next;
      }

      delete jPtr;
	  count--;

      return true;
   }
   else
      return false;
}


int CDList::size() const
// Constant member function that returns the number of CDs in the CDList
// PRE:  none
// POST: count is returned
{
   return count;
}


void CDList::print() const
// Constant member function that prints out the CDs in the CDList
// PRE:  none
// POST: the CD titles and artists in the CDList are printed out
// Library facilities used: cout and operator<< from iostream
{
   cout << "\nCD List Contents" << endl << endl;

   if ( head == NULL )
   {
      cout << "None" << endl;
   }

   for ( CDListNode* iPtr = head; iPtr != NULL; iPtr = iPtr->next )
   {
      cout << "\nTITLE: " << iPtr->title << endl;
      cout << "ARTIST: " << iPtr->artist << endl;
   }

   cout << endl;
}
