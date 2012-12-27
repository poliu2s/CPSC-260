// file: ContractEmployee.cpp
// Source file for the ContractEmployee class

#include "ContractEmployee.h"
#include <string>
#include <iostream>

   /* This is to be completed as part of the lab exercise */

using namespace std;

ContractEmployee::ContractEmployee( string name, 
                                    int startingYear, 
                                    int startingPayPeriod, 
                                    int numberofPayPeriods,
									float totalPayment) 
                : AbstractEmployee( name, startingYear, startingPayPeriod )

{
    
	this->contractLength = numberofPayPeriods;
	this->totalPayment = totalPayment;
	cout << "\nCreated a ContractEmployee instance." << endl;
}

float ContractEmployee::getContractLength( ) const
{
    return contractLength;
}

float ContractEmployee::getContractValue() const
{
	return totalPayment;

}

float ContractEmployee::getPayment( int year, int payPeriod ) const
{
	cout << "\nGot Payment for a ContractEmployee instance." << endl;
	if (year*24 + payPeriod  >   getStartingYear()*24 + getStartingPayPeriod() &&
		year*24 + payPeriod  <=    getStartingYear()*24 + getStartingPayPeriod() + getContractLength())
	{
		return (getContractValue()/getContractLength());
	}
    
	return 0;
}
