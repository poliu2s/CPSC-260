// file: FullTimeEmployee.cpp
// Implementation file for the FullTimeEmployee class

#include <string>    // string class used for the Employee name
#include "FullTimeEmployee.h"
#include <iostream>

using namespace std;

// Number of months per year.
static const int MONTHS_PER_YEAR = 12;

FullTimeEmployee::FullTimeEmployee( string name, 
                                    int startingYear, 
                                    int startingPayPeriod, 
                                    float monthlySalary ) 
                : AbstractEmployee( name, startingYear, startingPayPeriod )
// PRE:  startingYear is a non-negative integer.
//       startingPayPeriod is an integer between 1 and 
//       PAY_PERIODS_PER_YEAR.
//       monthlySalary is a non-negative float.
// POST: A new employee is created with the given name,
//       startingYear, startingPayPeriod, and the monthly salary.
{
    this->monthlySalary = monthlySalary;
	cout << "\nCreated a FullTimeEmployee instance." << endl;
}

float FullTimeEmployee::getMonthlySalary( ) const
// POST:  The monthly salary of employee is returned.
{
    return monthlySalary;
}

float FullTimeEmployee::getPayment( int year, int payPeriod ) const
// PRE:   year is a non-negative integer.  
//        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
// POST:  The amount of payment for that payPeriod is returned.
{
    cout << "\nGot Payment for a FullTimeEmployee instance." << endl;
	if ( year < getStartingYear( ) )
        return 0.0;

    if ( year == getStartingYear( )  &&  payPeriod < getStartingPayPeriod( ) )
        return 0.0;

    return monthlySalary * MONTHS_PER_YEAR / PAY_PERIODS_PER_YEAR;
}


