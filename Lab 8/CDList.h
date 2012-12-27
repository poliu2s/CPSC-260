// file: CDList.h
// CDList class header
// This is an in-lab exercise and is incomplete or incorrect

#ifndef CDLIST_H
#define CDLIST_H
#include <string>

using namespace std;

class CDList

   // This class is a container class that can hold an arbitrary number of 
   // CD structs which contain the artist name and CD title. More than one 
   // instance of the same CD can occur beacuse you might really like that 
   // CD and want to have two or more of them.
   // The class provides member functions to insert and remove CDs, count the 
   // number of CDs, and print out the list of CDs
   // Class Invariants:
   // - count >= 0
   // - count is the number of CDs in the CDList
{
  public:

   CDList();
   // Default constructor
   // PRE:  none
   // POST: an empty CDList is created

   void insert( const string& title, const string& artist );
   // Modification member function that inserts a CD into the CDList
   // PRE:  title and artist are valid strings
   // POST: the CD is added to the CDList

   bool remove( const string& title, const string& artist );
   // Modification member function that removes an instance of a CD from the 
   // CDList
   // PRE:  title and artist are valid strings
   // POST: an instance of the CD of the given title by the given artist is 
   //       removed from the CDList; returns true if successful, otherwise false

   int size() const;
   // Constant member function that returns the number of CDs in the CDList
   // PRE:  none
   // POST: count is returned

   void print() const;
   // Constant member function that prints out the CDs in the CDList
   // PRE:  none
   // POST: the CD titles and artists in the CDList are printed out
   // Library facilities used: cout and operator<< from iostream

  private:

   // This is a struct (which is like a class, but in this case it has
   // no methods) whose objects are the individual nodes in the linked
   // list used to store a CDList.  The member variables are all public,
   // so they can be manipulated by methods in the CDList class, but
   // because the struct is declared within the CDList class and is
   // private, clients of the CDList class cannot access the member
   // variables of the struct objects.

   struct CDListNode
   {
      string      title;
      string      artist;
      CDListNode* next;
   };

   CDListNode* head;    // pointer to the head of the CDList
   int count;           // count of the number of CDs in the CDList

};

#endif
