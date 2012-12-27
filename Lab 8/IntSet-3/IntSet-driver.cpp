// file: IntSet-driver.cpp
// Test driver source for the IntSet class
// This class is an in-lab exercise and is incomplete
 
#include <iostream>    // used in main()
#include "IntSet.h"

using namespace std;

int main()

   // Library facilities used: cout, cin, operator>> and operator<< from 
   // iostream
{
   int choice;
   int entry;
   IntSet A;
   IntSet B;

   while( true )
   {
      cout << "\n"
           << "==================================================\n"
           << "\n"
           << "1. Attempt to insert a number to   IntSet A\n"
           << "2. Attempt to erase  a number from IntSet A\n"
           << "3. Attempt to insert a number to   IntSet B\n"
           << "4. Attempt to erase  a number from IntSet B\n"
           << "0. Exit\n"
           << "\n"
           << "Please input your choice: ";
      cin  >> choice;

      if ( choice == 0 )
      {
         break;
      }

      if ( choice < 1  ||  choice > 5 )
      {
         cout << "Choice is not valid. Please try again.\n";
         continue;
      }

      cout << "Please input the number: ";
      cin  >> entry;

      switch( choice )
      {
       case 1:
         A.insert( entry );
         break;
       case 2:
         A.erase( entry );
         break;
       case 3:
         B.insert( entry );
         break;
       case 4:
         B.erase( entry );
         break;
       case 5:
         A.mystery( entry );
         break;
      }

      cout << "\n";
      cout << "IntSet A                     : ";
      A.print();
      cout << "IntSet B                     : ";
      B.print();
      cout << "Union of IntSet A & B        : ";
      ( A + B ).print();
      cout << "Intersection of IntSet A & B : ";
      ( A * B ).print();
      cout << "odd elements of IntSet A     : ";
      A.odd().print();
      cout << "odd elements of IntSet B     : ";
      B.odd().print();
// uncomment the six lines above after you have implemented operator*
// and odd()
   }

   return 0;    // normal exit code
}
