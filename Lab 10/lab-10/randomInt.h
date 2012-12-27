// Author:  Paul Carter
// Date: June 22, 1999
// Revised: January 7, 2000
// File: randomInt.h

// ADT for generating a random integer in a specified range

// Assumptions: random number generator has been seeded by client


#ifndef _CRANDOMINT_
#define _CRANDOMINT_


class CRandomInt
{
public:
    // Constructors
    CRandomInt();
    // Postcondition: range has been set to 0..RAND_MAX
    CRandomInt( int low, int high );
    // Precondition: low < high; high - low <= RAND_MAX
    // Postcondition: range has been set to low..high

    // Mutators
    void setInterval( int low, int high );
    // Precondition: low < high; high - low <= RAND_MAX
    // Postcondition: range has been set to low..high

    // Inspectors
    int getLow( void ) const;
    // Postcondition: low bound has been returned
    int getHigh( void ) const;
    // Postcondition: high bound has been returned

    // Facilitators
    int getRand( void ) const;
    // Postcondition: random number in range low..high
    // has been returned
	
private:
    int m_low;	// low end of range 
    int m_high;	// high end of range
};


#endif


