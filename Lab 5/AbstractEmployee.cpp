// file: AbstractEmployee.cpp
// Implementation file for the AbstractEmployee class

#include <string>    // string class used for the Employee name
#include "AbstractEmployee.h"

using namespace std;

AbstractEmployee::AbstractEmployee( string name, 
                                    int startingYear, 
                                    int startingPayPeriod )
// PRE:  startingYear is a non-negative integer.  
//       startingPayPeriod is an integer between 1 and PAY_PERIODS_PER_YEAR.
// POST: A new employee is created with the given name, 
//       starting year, and starting pay period.
{
    this->name = name;
    this->startingYear = startingYear;
    this->startingPayPeriod = startingPayPeriod;
}

int AbstractEmployee::getStartingYear( ) const
// POST: The employee's starting year is returned.
{
    return startingYear;
}

int AbstractEmployee::getStartingPayPeriod( ) const
// POST: The employee's starting pay period is returned.
{
    return startingPayPeriod;
}

string AbstractEmployee::getName( ) const
// POST: The employee name is returned.
{
    return name;
}
