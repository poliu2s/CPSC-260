// file: ContractEmployee-driver.cpp
// Test driver for the ContractEmployee class
//
// This must be written as part of the lab exercises

#include "ContractEmployee.h"
#include <iostream>
#include <string>

void calculateTarget( const ContractEmployee &anEmployee,
                      int target, 
                      int &aTargetYear,
                      int &aTargetPayPeriod,
                      const int payPeriods )
// Calculate target year and pay period.
{
    aTargetYear = target / payPeriods;
    aTargetPayPeriod = target % payPeriods;

    // Since there are no pay period #0, reset to
    // pay period #24 of previous year.
    if ( aTargetPayPeriod == 0 )
    { 
        aTargetYear--;
        aTargetPayPeriod = payPeriods;
    }  
}

void printTestResult( const ContractEmployee &anEmployee,
		      int aYear,
		      int aPayPeriod )
// Output the results of a test.
{
    cout << "\n" << aYear << " pay period #" << aPayPeriod
       << " salary = $" 
       << anEmployee.getPayment( aYear, aPayPeriod );
}

void testEmployee( const ContractEmployee& anEmployee,
                   string aName,
	               int aYear,
	               int aPayPeriod,
	               int aNumberofPayPeriods,
				   float totalPayment)
// Create an object using the test data, and print the results.
{
    cout << "\nHave created a new full time employee:" << endl
       << "\tName: " << anEmployee.getName( ) << endl
       << "\tStarting Year: " << anEmployee.getStartingYear( ) << endl
       << "\tStarting Pay Period: " << anEmployee.getStartingPayPeriod( ) << endl
       << "\tPay Period Wage: $" << anEmployee.getPayment( aYear, aPayPeriod) << endl;


    int targetYear, targetPayPeriod;
    int payPeriods = AbstractEmployee::PAY_PERIODS_PER_YEAR;
    int start = aYear * payPeriods + aPayPeriod;

    cout << "\n" << anEmployee.getName( ) << "\'s ";

    for ( int i = start - 1; i <= start + 2; i++ )
    {
        // Check one pay period before, the actual pay period,
        // one and two pay periods after the employee has started.
        calculateTarget( anEmployee, i, targetYear, targetPayPeriod, payPeriods );
        printTestResult( anEmployee, targetYear, targetPayPeriod );
    }

    // Check one year after employee has started.
    calculateTarget( anEmployee, 
                   start + payPeriods,
                   targetYear,
                   targetPayPeriod,
                   payPeriods );

    printTestResult( anEmployee, targetYear, targetPayPeriod );

    // Check a long time after employee has started.
    calculateTarget( anEmployee, 
                   start +  172 * payPeriods + 2,
                   targetYear,
                   targetPayPeriod,
                   payPeriods );

    printTestResult( anEmployee, targetYear, targetPayPeriod );

    cout << endl;
}

int main()
// Library facilities used: cout and operator<< from iostream
{

    int theYear;
    int thePayPeriod;
    int theNumberofPayPeriods;
	float theTotalPayment;

// ------------------ Replace the following with your input code.

    string theName;
    // Full Time Employee #1

    theName = "John";
    theYear = 1998;
    thePayPeriod = 3;
    theNumberofPayPeriods = 5; 
	theTotalPayment = 150000;
    ContractEmployee theEmployee1( theName, theYear, thePayPeriod, theNumberofPayPeriods, theTotalPayment );
    //testEmployee( theEmployee1, theName, theYear, thePayPeriod,  theNumberofPayPeriods, theTotalPayment ); 

	for (int i = theEmployee1.getStartingPayPeriod(); i <= theEmployee1.getContractLength()+2; i++ ) {

		cout << "For the year of 1998: " << endl;
		cout << "Pay Period Number " << i << " \n";
		cout << "Payment = " << theEmployee1.getPayment(theYear, thePayPeriod +i) << "\n\n";


	}





    // Full Time Employee #2
	/*
    theName = "Peter";
    theYear = 1992;
    thePayPeriod = 4;
    theNumberofPayPeriods = 1600; 
	theTotalPayment = 15000000;
    ContractEmployee theEmployee1( theName, theYear, thePayPeriod, theNumberofPayPeriods, theTotalPayment );
    testEmployee( theEmployee1, theName, theYear, thePayPeriod,  theNumberofPayPeriods, theTotalPayment ); 
	*/

// ------------------ Replace the above with your input code.

    return 0;    // normal exit code

}

