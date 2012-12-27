// file: debug3.cpp
// Test driver for the CDList class
// This is an in-lab exercise and is incomplete or incorrect

#include <iostream>    // used in main()
#include <string>
#include "CDList.h"

using namespace std;

int main()

   // Library facilities used cout and operator<< from iostream
{
   // Construct a new 'CDList' object
   cout << "Constructing an empty CDList" << endl;
   CDList myCDs;

   // Print out the contents of the 'CDList'
   cout << "\nCDList contains " << myCDs.size() << " CDs" << endl;
   myCDs.print();

   // Inserting a CD
   cout << "Inserting a CD: Another Level, Blackstreet" << endl;
   myCDs.insert( "Another Level", "Blackstreet" );

   // Inserting a CD
   cout << "Inserting a CD: No Need to Argue, The Cranberries" << endl;
   myCDs.insert( "No Need to Argue", "The Cranberries" );

   // Inserting a CD
   cout << "Inserting a CD: Don't Smoke in Bed, Holly Cole" << endl;
   myCDs.insert( "Don't Smoke in Bed", "Holly Cole" );

   // Inserting a CD
   cout << "Inserting a CD: She, Harry Connick Jr" << endl;
   myCDs.insert( "She", "Harry Connick Jr" );

   // Inserting a CD
   cout << "Inserting a CD: Wake Up and Smell the Coffee, The Cranberries" << endl;
   myCDs.insert( "Wake Up and Smell the Coffee", "The Cranberries" );

   // Inserting a CD
   cout << "Inserting a CD: Diary of a Mad Band, Jodeci" << endl;
   myCDs.insert( "Diary of a Mad Band", "Jodeci" );

   // Inserting a CD
   cout << "Inserting a CD: Jagged Little Pill, Alanis Morissette" << endl;
   myCDs.insert( "Jagged Little Pill", "Alanis Morissette" );

   // Inserting a CD
   cout << "Inserting a CD: Decksanddrumsandrockandroll, Propellerheads" << endl;
   myCDs.insert( "Decksanddrumsandrockandroll", "Propellerheads" );

   // Print out the contents of the 'CDList'------------------------------------------------------
   cout << "\nCDList contains " << myCDs.size() << " CDs" << endl;
   myCDs.print();

   // Removing a CD
   cout << "Removing a CD: Another Level, Blackstreet" << endl;
   myCDs.remove( "Another Level", "Blackstreet" );

   // Removing a CD
   cout << "Removing a CD: She, Harry Connick Jr" << endl;
   myCDs.remove( "She", "Harry Connick Jr" );

   // Removing a CD
   cout << "Removing a CD: Decksanddrumsandrockandroll, Propellerheads" << endl;
   myCDs.remove( "Decksanddrumsandrockandroll", "Propellerheads" );

   // Removing a CD
   cout << "Removing a CD: No Need to Argue, The Cranberries" << endl;
   myCDs.remove( "No Need to Argue", "The Cranberries" );

   // Print out the contents of the 'CDList'
   cout << "\nCDList contains " << myCDs.size() << " CDs" << endl;
   myCDs.print();

   return 0;    // normal exit code
}
