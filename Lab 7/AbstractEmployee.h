// file: AbstractEmployee.h
// Header file for the abstract AbstractEmployee class

#ifndef ABSTRACT_EMPLOYEE_H
#define ABSTRACT_EMPLOYEE_H

#include <string>    // string class used for the Employee name
using namespace std;

// The AbstractEmployee class is the base class for all the
// employee classes. It contains the name, the starting year, 
// and the starting pay period of the employee. It also contains
// a virtual method for computing the pay cheque.

// Class Invariants:
// - The employee name, the starting year, and the starting pay period
//   do not change once an employee is created.

class AbstractEmployee
{
public:
    // Each pay period represents half of month.
    //static const int PAY_PERIODS_PER_YEAR = 24;
    enum{ PAY_PERIODS_PER_YEAR = 24 }; // comment-out previous line and use this one for MS compiler

    AbstractEmployee( string name, int startingYear, int startingPayPeriod );
    // PRE:  startingYear is a non-negative integer.  
    //       startingPayPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
    // POST: A new employee is created with the given name, 
    //       starting year, and starting pay period.

    int getStartingYear( ) const;
    // POST: The employee's starting year is returned.

    int getStartingPayPeriod( ) const;
    // POST: The employee's starting pay period is returned.

    string getName( ) const;
    // POST: The employee name is returned.

    virtual float getPayment( int year, int payPeriod ) const = 0;
    // PRE:   year is a non-negative integer.  
    //        payPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
    // POST:  The amount of payment for the given year and payPeriod is returned.
    //
    // This one is defined to be virtual, so that if we invoke getPayment( ) on
    // a derived employee via an AbstractEmployee pointer, the correct 
    // getPayment( ) method suitable for the particular object will be called.
    //
    // This is a pure virtual member function; concrete subclasses must
    // override this member function.


private:
    string name;              // This is the employee name
    int startingYear;         // The starting year of employment.
    int startingPayPeriod;    // The starting pay period between 
                              // 1 and PAY_PERIODS_PER_YEAR.
};

#endif
