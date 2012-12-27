// file: Employee-driver.cpp
// Test driver for the all employee classes
// - shows use of virtual methods and destructors
//
// **********************************************
// NOTE:
// - to "see" virtual destructors in action, you
//   should add destructors to all employee classes.
//   These destructors should simply print a message.
//   
// **********************************************

#include <iostream>  // provide cout object and operator<<
#include <string>    // string class used for the Employee name
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include "ContractEmployee.h"

using namespace std;

int main( )
{
    cout << "**** Employee driver" << endl;

    const int NUM_EMPLOYEES = 3;
    const int PT_START      = 2;
    const int PT_END        = 22;


    AbstractEmployee* arrayEmployee[NUM_EMPLOYEES];
    string name;
    float payment;
    int i, j;

    // set up employee objects
    arrayEmployee[0] = new FullTimeEmployee( "Fred Fulltime",
                                              1997,
                                              1,
                                              4000 );

    arrayEmployee[1] = new PartTimeEmployee( "Patrick Parttime", 
                                              1997,
                                              PT_START,
                                              12 );
    for ( i = PT_END; i >= PT_START; i-- ) 
    {
        // must cast base class pointers to PartTimeEmployee* in 
        // order to access setHours method of PartTimeEmployee class
        ( ( PartTimeEmployee* )arrayEmployee[1] )->setHours( 1997, i, i );
    }

    arrayEmployee[2] = new ContractEmployee( "Connie Contract",
                                              1997,
                                              4,
                                              12,
                                              120000 );

    // Get payments for each employee for each month
    // You can put a breakpoint on call to getPayment( ) and
    // see which subclass' getPayment( ) is executed 
    for ( i = 1; i <= AbstractEmployee::PAY_PERIODS_PER_YEAR; i++ ) 
    {
        cout << "For year 1997: " << endl;
        cout << "Pay Period Number " << i << "\n";
        for ( j = 0; j < NUM_EMPLOYEES; j++ ) 
        {
            name = arrayEmployee[j]->getName();
            payment = arrayEmployee[j]->getPayment( 1997, i );
            cout << "   " << name << " = $" << payment << "\n";
        }
        cout << "\n";
    }

    // Free array - use of destructors.
    for ( i = 0; i < NUM_EMPLOYEES; i++ ) 
    {
        delete arrayEmployee[i];
    }

    return 0;
}
