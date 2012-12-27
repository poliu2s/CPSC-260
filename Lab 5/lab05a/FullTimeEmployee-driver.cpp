// file: FullTimeEmployee-driver.cpp
// Test driver for the FullTimeEmployee class

// Modification History:
//
// AL - September 2001
// PC - October 2001
//

#include <iostream>  // provides cout object and operator<<
#include <string>    // string class used for the Employee name
#include "FullTimeEmployee.h"
#include <fstream>

using namespace std;

// ------------------ Insert your file fstream declarations below.



// ------------------ Insert your file fstream declarations above.

void calculateTarget( const FullTimeEmployee &anEmployee,
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

void printTestResult( const FullTimeEmployee &anEmployee,
		      int aYear,
		      int aPayPeriod,
			  ofstream &ofs1)
// Output the results of a test.
{
    cout << "\n" << aYear << " pay period #" << aPayPeriod
       << " salary = $" 
       << anEmployee.getPayment( aYear, aPayPeriod );

    ofs1 << "\n" << aYear << " pay period #" << aPayPeriod
       << " salary = $" 
       << anEmployee.getPayment( aYear, aPayPeriod );
}

void testEmployee( const FullTimeEmployee& anEmployee,
                   string aName,
	               int aYear,
	               int aPayPeriod,
	               float aMonthlyWage,
				   ofstream &ofs2)
// Create an object using the test data, and print the results.
{
    cout << "\nHave created a new full time employee:" << endl
       << "\tName: " << anEmployee.getName( ) << endl
       << "\tStarting Year: " << anEmployee.getStartingYear( ) << endl
       << "\tStarting Pay Period: " << anEmployee.getStartingPayPeriod( ) << endl
       << "\tMonthly Wage: $" << anEmployee.getMonthlySalary( ) << endl;

	ofs2 << "\nHave created a new full time employee:" << endl
       << "\tName: " << anEmployee.getName( ) << endl
       << "\tStarting Year: " << anEmployee.getStartingYear( ) << endl
       << "\tStarting Pay Period: " << anEmployee.getStartingPayPeriod( ) << endl
       << "\tMonthly Wage: $" << anEmployee.getMonthlySalary( ) << endl;

    int targetYear, targetPayPeriod;
    int payPeriods = AbstractEmployee::PAY_PERIODS_PER_YEAR;
    int start = aYear * payPeriods + aPayPeriod;

    cout << "\n" << anEmployee.getName( ) << "\'s ";
	ofs2 << "\n" << anEmployee.getName( ) << "\'s ";

    for ( int i = start - 1; i <= start + 2; i++ )
    {
        // Check one pay period before, the actual pay period,
        // one and two pay periods after the employee has started.
        calculateTarget( anEmployee, i, targetYear, targetPayPeriod, payPeriods );
        printTestResult( anEmployee, targetYear, targetPayPeriod, ofs2 );
    }

    // Check one year after employee has started.
    calculateTarget( anEmployee, 
                   start + payPeriods,
                   targetYear,
                   targetPayPeriod,
                   payPeriods );

    printTestResult( anEmployee, targetYear, targetPayPeriod, ofs2 );

    // Check a long time after employee has started.
    calculateTarget( anEmployee, 
                   start +  172 * payPeriods + 2,
                   targetYear,
                   targetPayPeriod,
                   payPeriods );

    printTestResult( anEmployee, targetYear, targetPayPeriod, ofs2 );

    cout << endl;
	ofs2 << endl;
}

int main()
// Library facilities used: cout and operator<< from iostream
{

	
    int theYear;
    int thePayPeriod;
    float theMonthlyWage;
	string theName;

	// opens input file
	ifstream inFile("FullTimeEmployee.dat", ios::in);
	if (inFile.fail()) {
		cout << "Problem with file!!!" << endl;
		return 0;
	}

	// opens output file
	ofstream outFile( "output.txt");
	if(outFile.fail()) {
		return 0;
	}

	// input from dat file
	inFile >> theName >> theYear >> thePayPeriod >> theMonthlyWage;
	
	// display calcuated/processed data
	FullTimeEmployee theEmployee1( theName, theYear, thePayPeriod, theMonthlyWage);
    testEmployee( theEmployee1, theName, theYear, thePayPeriod, theMonthlyWage, outFile ); 

	inFile >> theName >> theYear >> thePayPeriod >> theMonthlyWage;
	FullTimeEmployee theEmployee2( theName, theYear, thePayPeriod, theMonthlyWage);
    testEmployee( theEmployee2, theName, theYear, thePayPeriod, theMonthlyWage, outFile ); 

	inFile >> theName >> theYear >> thePayPeriod >> theMonthlyWage;
	FullTimeEmployee theEmployee3( theName, theYear, thePayPeriod, theMonthlyWage);
    testEmployee( theEmployee3, theName, theYear, thePayPeriod, theMonthlyWage, outFile ); 

	outFile << "hello";

	inFile.close();
	outFile.close();


// ------------------ Replace the following with your input code.
/*
    string theName;
    // Full Time Employee #1

    theName = "John";
    theYear = 1998;
    thePayPeriod = 1;
    theMonthlyWage = 1200;  
    FullTimeEmployee theEmployee1( theName, theYear, thePayPeriod, theMonthlyWage );
    testEmployee( theEmployee1, theName, theYear, thePayPeriod, theMonthlyWage ); 


    // Full Time Employee #2

    theName = "Peter";
    theYear = 1992;
    thePayPeriod = 4;
    theMonthlyWage = 1400;  
    FullTimeEmployee theEmployee2( theName, theYear, thePayPeriod, theMonthlyWage );
    testEmployee( theEmployee2, theName, theYear, thePayPeriod, theMonthlyWage );
*/
// ------------------ Replace the above with your input code.

    return 0;    // normal exit code

}
