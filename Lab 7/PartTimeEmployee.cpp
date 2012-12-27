// file: PartTimeEmployee.cpp
// Implementation file for the PartTimeEmployee class

#include <iostream>  // provides cout object and operator<<
#include <string>    // string class used for the Employee name
#include "PartTimeEmployee.h"

using namespace std;

PartTimeEmployee::PartTimeEmployee( string name, 
                                    int startingYear, 
                                    int startingPayPeriod, 
                                    float hourlyWage ) 
                : AbstractEmployee( name, startingYear, startingPayPeriod )
// PRE:  startingYear is a non-negative integer.
//       startingPayPeriod is an integer between 1 and 
//       PAY_PERIODS_PER_YEAR.
//       hourlyWage is a non-negative float.
// POST: A new employee is created with the given name, the startingYear,
//       the startingPayPeriod, and the hourly wage.
{
    this->hourlyWage = hourlyWage;
	cout << "\nCreated a PartTimeEmployee instance." << endl;
}

float PartTimeEmployee::getHourlyWage( ) const
// POST:  The hourly wage of employee is returned.
{
    return hourlyWage;
}

int PartTimeEmployee::getHours( int year, int payPeriod ) const
// PRE:   year is a non-negative integer.  
//        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
// POST:  The number of hours recorded for that pay period is returned.
{
    // Computes the payPeriod
    int target = year * PAY_PERIODS_PER_YEAR + payPeriod;   

    // Compute the starting index, so that we can compare
    // it against 'target'
    int startingIndex = getStartingYear( ) * PAY_PERIODS_PER_YEAR 
                       + getStartingPayPeriod( );

    if ( target < startingIndex  || target >= startingIndex + (int) hours.size( ) )
        return 0;      // If no hours are recorded, return 0.

    return hours[ target - startingIndex ];
}


bool PartTimeEmployee::setHours( int year, int payPeriod, int numHours )
// PRE:   year is a non-negative integer.  
//        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
//        numHours is an non-negative integer.
// POST:  If the year and payPeriod preceed the starting year and
//        starting pay period, numHours is not recorded and setHours( )
//        returns false, otherwise the number of hours recorded 
//        for that pay period is changed and true is returned.
{
    bool status = true;

    // Computes the target payPeriod
    int target = year * PAY_PERIODS_PER_YEAR + payPeriod;

    // Compute the actual starting index, so that we can compare
    // it against 'target'
    int startingIndex = getStartingYear( ) * PAY_PERIODS_PER_YEAR 
                       + getStartingPayPeriod( );


    if ( target < startingIndex )
    {
        cout << "Cannot set hours for pay period preceeding starting year "
             << getStartingYear( ) << " and starting pay period " 
             << getStartingPayPeriod( ) << endl;
        status = false;
    }
    else
    {
        // If that payPeriod is after the last recorded payPeriod,
        // then append space to our vector before to record hours
        if ( target >= startingIndex + (int) hours.size() )
        {
            for( int counter = target - startingIndex - (int) hours.size( );  
                     counter > 0; counter-- )
                hours.push_back( 0 );

            hours.push_back( numHours );
        }
        else
        {
            // Otherwise, just modify the corresponding element in the vector.
            hours[ target - startingIndex ] = numHours;
        }
    }

    return status;
}


float PartTimeEmployee::getPayment( int year, int payPeriod ) const
// PRE:   year is a non-negative integer.  
//        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
// POST:  The amount of payment for that payPeriod is returned.
{
    cout << "\nGot Payment for a PartTimeEmployee instance." << endl;
	return getHours( year, payPeriod ) * hourlyWage;
}










