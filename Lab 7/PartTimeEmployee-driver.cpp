// file: PartTimeEmployee-driver.cpp
// Test driver for the PartTimeEmployee class

// Modification History:
//
// AL - September 2001
// PC - October 2001
//

#include <iostream>  // provides cout object and operator<<
#include <string>    // string class used for the Employee name
#include "PartTimeEmployee.h"

using namespace std;

// Function Prototypes

// Create an object using the test data, and print the results.
void testEmployee( const PartTimeEmployee& anEmployee,
                   string aName, 
                   int aYear, 
		           int aPayPeriod, 
		           float aMonthlyWage );

// Set the number of hours for the employee using the test data,
// and print the results.
void testHours( PartTimeEmployee& anEmployee, 
                int aYear, 
                int aPayPeriod, 
                int aNumberOfHours );


// Output the resutls of a test.
void printTestResults( const PartTimeEmployee& anEmployee, 
		       int aYear, 
		       int aPayPeriod );


int main()
// Library facilities used: cout and operator<< from iostream
{

    string theName = "Jane";
    int theYear = 1997;
    int thePayPeriod = 24;
    float theHourlyWage = 8.0;
    int theNumberOfHours;


    // PartTime Employee #1
    PartTimeEmployee theEmployee( theName, theYear, thePayPeriod, theHourlyWage );
    testEmployee( theEmployee, theName, theYear, thePayPeriod, theHourlyWage );

    // PartTime Employee - Set of Hours #1
    theYear = 1998;
    thePayPeriod = 1;
    theNumberOfHours = 150;
    testHours( theEmployee, theYear, thePayPeriod, theNumberOfHours );

    // PartTime Employee - Set of Hours #2
    theYear = 1998;
    thePayPeriod = 3;
    theNumberOfHours = 135;
    testHours( theEmployee, theYear, thePayPeriod, theNumberOfHours );

    // PartTime Employee - Set of Hours #3
    theYear = 1998;
    thePayPeriod = 6;
    theNumberOfHours = 200;
    testHours( theEmployee, theYear, thePayPeriod, theNumberOfHours );

    // PartTime Employee - Set of Hours #3
    theYear = 1998;
    thePayPeriod = 2;
    theNumberOfHours = 155;
    testHours( theEmployee, theYear, thePayPeriod, theNumberOfHours );

    // PartTime Employee - Set of Hours #5
    theYear = 1996;
    thePayPeriod = 2;
    theNumberOfHours = 300;
    testHours( theEmployee, theYear, thePayPeriod, theNumberOfHours );

    return 0;    // normal exit code
}

void testEmployee( const PartTimeEmployee& anEmployee,
                   string aName,
	               int aYear,
	               int aPayPeriod,
	               float aMonthlyWage )
// Create an object using the test data, and print the results.
{
  cout << "\nHave created a new part time employee:" << endl
       << "\tName: " << anEmployee.getName( ) << endl
       << "\tStarting Year: " << anEmployee.getStartingYear( ) << endl
       << "\tStarting Pay Period: " << anEmployee.getStartingPayPeriod( ) << endl
       << "\tHourly Salary: $" << anEmployee.getHourlyWage( ) << endl;
}

void testHours( PartTimeEmployee& anEmployee, 
                int aYear, 
                int aPayPeriod, 
                int aNumberOfHours )

  // Set the number of hours for the employee using the test data,
  // and print the results.
{
    const int END_TEST_PERIOD = 8;
    const int START_TEST_PERIOD = -1;

    cout << "\nAttempting to set hours for the part time employee:" << endl
       << "\tName: " << anEmployee.getName( ) << endl
       << "\tFor Year: " << aYear << endl
       << "\tFor Pay Period: " << aPayPeriod << endl
       << "\tNumber of Hours: "<< aNumberOfHours << endl;

    if ( anEmployee.setHours( aYear, aPayPeriod, aNumberOfHours ) )
    {
        cout << "\nHave set the number of hours for the part time employee:" << endl
        << "\tName: " << anEmployee.getName( ) << endl
        << "\tFor Year: " << aYear << endl
        << "\tFor Pay Period: " << aPayPeriod << endl
        << "\tNumber of Hours: " << anEmployee.getHours( aYear, aPayPeriod ) 
        << endl;

        int targetYear, targetPayPeriod;
        int payPeriods = AbstractEmployee::PAY_PERIODS_PER_YEAR;
        int startingYear = anEmployee.getStartingYear( );
        int startingPayPeriod = anEmployee.getStartingPayPeriod( );
        int start = startingYear * payPeriods + startingPayPeriod;

        cout << "\n" << anEmployee.getName( ) << "\'s ";

        // Check one pay period before employee has started.

        for ( int increment = START_TEST_PERIOD; 
           increment <= END_TEST_PERIOD; increment++ )
        {
            targetYear = ( start + increment ) / payPeriods;
            targetPayPeriod = ( start + increment ) % payPeriods;
            // Since there are no pay period #0.
            if ( targetPayPeriod == 0 )
            { 
                targetYear--;
                targetPayPeriod = payPeriods;
            }  

            // print results from START_TEST_PERIOD to END_TEST_PERIOD
            printTestResults( anEmployee, targetYear, targetPayPeriod );
        }
    }

    cout << endl;
}

void printTestResults( const PartTimeEmployee &anEmployee,
		       int aYear,
		       int aPayPeriod )
// Output the results of a test.
{
    cout << "\n" << aYear << " pay period #" << aPayPeriod 
       << " this employee worked for "
       << anEmployee.getHours( aYear, aPayPeriod ) 
       << " and salary = $" 
       << anEmployee.getPayment( aYear, aPayPeriod );
}
