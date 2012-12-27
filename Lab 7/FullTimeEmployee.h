// file: FullTimeEmployee.h
// Header file for the FullTimeEmployee class

#ifndef FULLTIME_EMPLOYEE_H
#define FULLTIME_EMPLOYEE_H

#include <string>    // string class used for the Employee name
#include "AbstractEmployee.h"

using namespace std;

// The FullTimeEmployee class represents a full time employee.
// It extends the AbstractEmployee class and provides an
// additional data field to keep track of monthly salary.

class FullTimeEmployee : public AbstractEmployee
{
public:

    FullTimeEmployee( string name, 
                     int startingYear, 
                     int startingPayPeriod, 
                     float monthlySalary );
    // PRE:  startingYear is a non-negative integer.
    //       startingPayPeriod is an integer between 1 and 
    //       PAY_PERIODS_PER_YEAR.
    //       monthlySalary is a non-negative float.
    // POST: A new employee is created with the given name,
    //       startingYear, startingPayPeriod, and the monthly salary.

    float getMonthlySalary( ) const;
    // POST:  The monthly salary of employee is returned.

    float getPayment( int year, int payPeriod ) const;
    // PRE:   year is a non-negative integer.  
    //        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
    // POST:  The amount of payment for that payPeriod is returned.

private:
    float monthlySalary;      // This is the monthly salary.
};

#endif
