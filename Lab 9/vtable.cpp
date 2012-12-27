//  File:    vtable.cpp
//
//  Author:  Kellogg Booth
//           Donald Acton
//  Date:    March 26, 2006
//           November 15, 2009
//  Examples of inheritance and surreptitious surveillance and sabotage
//  of the VTABLE to see how it works.

#include <iostream>
#include <string>
using namespace std;

static const int SIZE = 6;

void dump( int** memory, char* label )
//  Function to look at the memory to see what pointer values might
//  be there.  The output format is hexadecimal, which is achieved
//  by doing a cast.
{
   cout << "Dump - " << label << endl <<endl;
   cout << "  Memory Address : Contents at Memory Location" <<endl;
   for (int i=0; i<SIZE; i++ )
      cout << "  " << memory+i << ":" << (int*) memory[i] << endl;
}

class AAA
// Declare a base class with three methods, two of them virtual.
// All of the methods have the same signature because we will play
// around with them later.
{
   public:

      virtual void one( int i )
/* REMOVE THIS LINE AFTER THE FIRST COMPILATION IN THE LAB EXERCISES
      {
         cout << "  AAA::one(" << i << ")" << endl;
      }
REMOVE THIS LINE AFTER THE FIRST COMPILATION IN THE LAB EXERCISES */ ;

      virtual void two( int j )   
      {
         cout << "  AAA::two(" << j << ")" << endl;
      }

      void two( double x )
      {
         cout << "  AAA::two(" << x << ")" << endl;
      }

      void three( int k )
      {
         cout << "  AAA::three(" << k << ")" << endl;
      }
};

class BBB : public AAA
// Derived class of the base class. The destructor and another method are
// made virtual and an existing virtual method is overridden.
{
   public:

      virtual ~BBB()
      {
         cout << "  BBB::destructor" << endl;
      }

      virtual void three( int l )
      {
         cout << "  BBB::three(" << l << ")" << endl;
      }

      void two( int m )
      {
         cout << "  BBB::two(" << m << ")" << endl;
      }
};

class CCC : public BBB
// A further derived class from the first derived class. The destructor
// and two of the virtual methods are overridden.
{
   public:

      ~CCC()
      {
         cout << "  CCC::destructor" << endl;
      }

      void three( int n )
      {
         cout << "  CCC::three(" << n << ")" << endl;
      }

      void one( int o )
      {
         cout << "  CCC::one(" << o << ")" << endl;
      }
};

class DDD : public BBB
// A second further derived class from the first derived class.
// The destructor and all of the virtual methods are overridden.
{
   public:

      virtual ~DDD()
      {
         cout << "  DDD::destructor" << endl;
      }

      void three( int p )
      {
         cout << "  DDD::three(" << p << ")" << endl;
      }

      void two( int q )
      {
         cout << "  DDD::two(" << q << ")" << endl;
      }

      void one( int r )
      {
         cout << "  DDD::one(" << r << ")" << endl;
      }
};

int main()
// Use the classes to explore how VTABLES are organized.
{
   // Declare an object of each type
   AAA* pA = new AAA;
   AAA* pB = new BBB;
   AAA* pC = new CCC;
   AAA* pD = new DDD;

   // Make generic (int***) pointers to each object by casting
   int*** qA = (int***) pA;
   int*** qB = (int***) pB;
   int*** qC = (int***) pC;
   int*** qD = (int***) pD;

   // Make generic (int**) pointers to each VTABLE by casting
   int** vA = qA[0];
   int** vB = qB[0];
   int** vC = qC[0];
   int** vD = qD[0];

   // See what things look like in memory.
   dump( vA, "VTABLE for AAA" );
   dump( vB, "VTABLE for BBB" );
   dump( vC, "VTABLE for CCC" );
   dump( vD, "VTABLE for DDD" );

   // Call all three methods on the AAA object
   cout << "1 - AAA Object" << endl;
   pA->one(1);
   pA->two(1);
   pA->three(1);

   // Call all three methods on the BBB object
   cout << "2- BBB Object" << endl;
   pB->one(1);
   pB->two(1);
   pB->three(1);

   // Call all three methods on the CCC object
   cout << "3- CCC Object" << endl;
   pC->one(1);
   pC->two(1);
   pC->three(1);

   // Build a fake VTABLE by copying the VTABLE for the class CCC
   int* VTABLE[SIZE];
   for ( int i=0; i<SIZE; i++ ) VTABLE[i] = vC[i];

   // Make the VPTR for the CCC object point to the fake VTABLE
   qC[0] = VTABLE;

   // See if the fake VTABLE does the same thing as the real one
   cout << "4 - CCC Object with a fake VTABLE " << endl;
   pC->one(4);
   pC->two(4);
   pC->three(4);

   // Set the one() entry in the fake VTABLE to be AAA::one()
   VTABLE[0] = vA[0];
   cout << "5 - CCC Object with a modified VTABLE " << endl;
   pC->one(5);
   pC->two(5);
   pC->three(5);

   // Set the one() entry in the fake VTABLE to be CCC::three()
   VTABLE[0] = vC[3];
   cout << "6 - CCC Object with a very modified VTABLE " << endl;
   pC->one(6);
   pC->two(6);
   pC->three(6);

   // Set the VTABLE for the CCC object to be the DDD VTABLE
   qC[0] = qD[0];
   cout << "7 - CCC Object with the DDD VTABLE " << endl;
   pC->one(7);
   pC->two(7);
   pC->three(7);

   // Explicitly delete the pointers
   cout << "Delete all pointers" << endl;
   cout << " AAA object" << endl;
   delete pA;
   cout << " BBB object" << endl;
   delete (BBB*) pB;
   cout << " CCC object" << endl;
   delete pC;
   cout << " DDD object" << endl;
   delete (BBB*) pD;

   cout << "All done fooling around" << endl;
   cout << "Enter any non-white followed by carriage return to end this program" <<endl;
   string ans;
   cin >> ans;
}
