// Author:  Paul Carter
// Date: June 22, 1999
// Revised: January 7, 2000
// File: randomInt.cpp

// ADT for generating a random integer in a specified range

// Assumptions:  random number generator has been seeded by client.

#include <cstdlib>
#include "randomInt.h"

// Constructors
CRandomInt::CRandomInt()
// Postcondition: range has been set to 0..RAND_MAX
{
    m_low = 0;
    m_high = RAND_MAX;
}

CRandomInt::CRandomInt( int low, int high )
// Precondition: low < high; high - low <= RAND_MAX
// Postcondition: range has been set to low..high
{
    m_low = low;
    m_high = high;
}
	
// Mutators
void CRandomInt::setInterval( int low, int high )
// Precondition: low < high, high - low <= RAND_MAX
// Postcondition: range has been set to low..high
{
    m_low = low;
    m_high = high;
}

// Inspectors
int CRandomInt::getLow( void ) const
// Postcondition: low bound has been returned
{
    return m_low;
}

int CRandomInt::getHigh( void ) const
// Postcondition: high bound has been returned
{
    return m_high;	
}

// Facilitators
int CRandomInt::getRand( void ) const
// Postcondition: random number in the range low..high 
// has been returned
{
    return rand() % ( m_high - m_low + 1 ) + m_low;
}

