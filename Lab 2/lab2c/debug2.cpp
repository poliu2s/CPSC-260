// file: debug2.cpp
//
// Test driver source for the Bag class
//
// Modified by K. S. Booth on 2007-Sep-21
//
// This is an in-lab exercise. The driver should be linked with
// the Bag class and a debugge used to find the errors in the
// Bag class.
 
#include <iostream>    // used in main()
#include "Bag.h"

using namespace std;

int main()
// Library facilities used cout and operator<< from iostream
{
    // Construct a new 'Bag' object
    cout << "Constructing a new Bag object named \"a\"\n";
    Bag a;

    // Printing out its current content
    a.print();

    // Testing the 'insert' function
    cout << '\n';
    cout << "Adding 11 to the bag.\n";
    a.insert(11);
    a.print();
    cout << "Number of occurrences of 11 is " << a.occurrences(11) << "\n";
    cout << "Adding 120 to the bag.\n";
    a.insert(120);
    a.print();
    cout << "Number of occurrences of 120 is " << a.occurrences(120) << "\n";
    cout << "Adding 11 to the bag.\n";
    a.insert(11);
    a.print();
    cout << "Number of occurrences of 11 is " << a.occurrences(11) << "\n";
    cout << "Adding -15 to the bag.\n";
    a.insert(-15);
    a.print();
    cout << "Number of occurrences of -15 is " << a.occurrences(-15) << "\n";
    cout << "Adding 42 to the bag.\n";
    a.insert(42);
    a.print();
    cout << "Number of occurrences of 42 is " << a.occurrences(-15) << "\n";
    for (int i=0; i<6; i++)
    {
       cout << "Adding -15 to the bag.\n";
       a.insert(-15);
       a.print();
       cout << "Number of occurrences of -15 is " << a.occurrences(-15) << "\n";
    }

    // Testing the 'remove' function
    cout << '\n';
    cout << "Removing 11 from the bag.\n";
    a.remove(11);
    a.print();
    cout << "Number of occurrences of 11 is " << a.occurrences(11) << "\n";
    cout << "Removing 25 from the bag.\n";
    a.remove(25);
    a.print();
    cout << "Number of occurrences of 25 is " << a.occurrences(25) << "\n";
    cout << "Removing -15 from the bag.\n";
    a.remove(-15);
    a.print();
    cout << "Number of occurrences of -15 is " << a.occurrences(-15) << "\n";

    return 0;    // normal exit code
}
