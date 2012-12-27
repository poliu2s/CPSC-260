// File:     Complex-driver.cpp
//
// Author:   Paul Carter       *** Your name ALWAYS goes here
//           87654321          *** Your ID number ALWAYS goes here
//           pcarter           *** Your userID ALWAYS goes here
//           L2X               *** Your lab section ALWAYS goes here
//
// Modified: 2001 September 19 *** Add a new date if you modify the file!
//
// Complex class driver source file

#include <iostream>    // used in main()
#include "Complex.h"

using namespace std;

// Library facilities used: cout and operator<< and cin operator>>
// from iostream

int main()
{



   cout << "Creating Complex num1 with default constructor\n";
   cout << "Should have real part = 0, imaginary part = 0\n";

   Complex num1;

   cout << " num1 has real part " << num1.getReal() << "\n";
   cout << " num1 has imaginary part " << num1.getImag() << "\n";

   cout << " num1 = " << num1 << "\n\n";

   // Get user input for num1

   cout << "Enter new value for complex number num1: ";
   cin >> num1;
   cout << "\n";

   cout << " num1 has real part " << num1.getReal() << "\n";
   cout << " num1 has imaginary part " << num1.getImag() << "\n";

   cout << " num1 = " << num1 << "\n";
   cout << " complex conjugate of num1 = " << ~num1 << "\n";
   cout << " num1+num1 = " << num1+num1 << "\n";
   cout << " num1-num1 = " << num1-num1 << "\n";
   cout << " num1*num1 = " << num1*num1 << "\n";
   cout << " 1.0/num1 = " << Complex(1.0)/num1 << "\n";
   cout << " num1/num1 = " << num1/num1 << "\n";
   cout << " num1-- = " << num1-- << "\n";
   cout << " num1 = " << num1 << "\n";
   cout << " ++num1 = " << ++num1 << "\n";
   cout << " num1 = " << num1 << "\n";
   cout << " -num1 = " << -num1 << "\n";
// ----------------------------------------------------------------------
// Remove the comments from the following four lines after you have added
// the appropriate operators to the implementation.
   cout << " +num1 = " << +num1 << "\n";
   cout << " --num1 = " << --num1 << "\n";
   cout << " num1 = " << num1 << "\n";
   cout << " num1++ = " << num1++ << "\n";
   cout << " num1 = " << num1 << "\n";
// ----------------------------------------------------------------------

   cout << "\nCreating new Complex num2 = 3.0 + 4.0i\n";

   Complex num2( 3.0, 4.0 );    // Use parameterized constructor

   cout << " num2 = " << num2 << "\n\n";

   cout << "Creating new Complex num3: 1.5 - 2.0i\n";
   Complex num3( 1.5, -2.0 );    // Use parameterized constructor

   cout << " num3 = " << num3 << "\n\n";

   cout << "Changing Complex num3 to: 0.0 + 0.0i\n";
   num3.setComplex( 0.0, 0.0 );

   cout << " num3 = " << num3 << "\n\n";

   cout << "Attempting: num3 = num1\n";
   num3 = num1;

   cout << " num3 = " << num3 << "\n\n";

   cout << "Attempting: num3 = num1 + num2\n";
   num3 = num1 + num2;

   cout << " num3 = " << num3 << "\n\n";

   cout << "Creating new double doubleNum = 12.34\n";

   double doubleNum = 12.34;

   cout << "Attempting: num3 = num1 + doubleNum\n";
   num3 = num1 + doubleNum;                           // right operand implicitly cast to Complex

   cout << " num3 = " << num3 << "\n\n";

   cout << "Attempting: num3 = doubleNum + num2\n";
   num3 = Complex( doubleNum ) + num2;                // explicit casting necessary here

   cout << " num3 = " << num3 << "\n\n";

   cout << "Attempting: num1 = 13.5\n";       // 13.5 implicitly cast to Complex  
   num1 = 13.5;

   cout << " num1 = " << num1 << "\n\n";

   return 0;   
}
