// file: PartTimeEmployee.h
// Header file for the PartTimeEmployee class

#ifndef PARTTIME_EMPLOYEE_H
#define PARTTIME_EMPLOYEE_H

#include <string>    // string class used for the Employee name
#include <vector>    // STL vector class used for keeping track of the hours
#include "AbstractEmployee.h"

using namespace std;

// The PartTimeEmployee class represents a part time employee.
// It extends the AbstractEmployee class and provides
// additional data fields to keep track of the hours and the hourly wage.

class PartTimeEmployee : public AbstractEmployee
{
public:

    PartTimeEmployee( string name, 
                     int startingYear, 
                     int startingPayPeriod, 
                     float hourlyWage );  
    // PRE:  startingYear is a non-negative integer.
    //       startingPayPeriod is an integer between 1 and 
    //       PAY_PERIODS_PER_YEAR.
    //       hourlyWage is a non-negative float.
    // POST: A new employee is created with the given name, the startingYear,
    //       the startingPayPeriod, and the hourly wage.

    float getHourlyWage( ) const;
    // POST:  The hourly wage of employee is returned.

    int getHours( int year, int payPeriod ) const;
    // PRE:   year is a non-negative integer.  
    //        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
    // POST:  The number of hours recorded for that pay period is returned.

    bool setHours( int year, int payPeriod, int numHours );
    // PRE:   year is a non-negative integer.  
    //        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
    //        numHours is an non-negative integer.
    // POST:  If the year and payPeriod preceed the starting year and
    //        starting pay period, numHours is not recorded and setHours( )
    //        returns false, otherwise the number of hours recorded 
    //        for that pay period is changed and true is returned.

    float getPayment( int year, int payPeriod ) const;
    // PRE:   year is a non-negative integer.  
    //        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
    // POST:  The amount of payment for that payPeriod is returned.

private:
    float hourlyWage;  // the hourly wage.
    vector<int> hours; // Each element in "hours" represents the number of 
                       // hours recorded for a particular pay period.
                       // The size of "hours" represents the number
                       // of pay periods between the starting pay period
                       // and the last pay period for which a number of hours
                       // was recorded.
};

#endif
