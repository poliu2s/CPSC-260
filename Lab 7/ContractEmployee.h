// file: ContractEmployee.h
// Header file for the ContractEmployee class

   /* This is to be completed as part of the lab exercise */


#ifndef CONTRACT_EMPLOYEE_H
#define CONTRACT_EMPLOYEE_H

#include <string>    // string class used for the Employee name
#include "AbstractEmployee.h"

using namespace std;


class ContractEmployee : public AbstractEmployee
{
public:

    ContractEmployee( string name, 
                     int startingYear, 
                     int startingPayPeriod,
					 int numberofPayPeriods,
                     float totalPayment );


    float getContractLength( ) const;

	float getContractValue() const;

	float getPayment( int year, int payPeriod ) const;


private:
	float totalPayment;
	int contractLength;
};

#endif