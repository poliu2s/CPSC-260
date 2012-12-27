// File:     Complex.cpp
//
// Author:   Po Liu       *** Your name ALWAYS goes here
//           13623079          *** Your ID number ALWAYS goes here
//           x2f7           *** Your userID ALWAYS goes here
//           L2A               *** Your lab section ALWAYS goes here
//
// Modified: 28 June 2010
//			 2001 September 19 *** Add a new date if you modify the file!
//
// Complex class source file

#include <iostream>    
#include <cmath>        
#include "Complex.h"

using namespace std;

Complex::Complex()
// Default constructor
//
// PRE:  (none)
//
// POST: complex number is 0 + 0*i
{
    realPart = imagPart = 0.0;
}

Complex::Complex( double real, double imag )
// Parameterized constructor
//
// PRE:  (none)
//
// POST: complex number is real + imag*i
{
    realPart = real;
    imagPart = imag;
}

Complex::Complex( double real )
// Convert constructor
//
// PRE:  (none)
//
// POST: complex number is real + 0 * i   
{
    realPart = real;
    imagPart = 0.0;
}

void Complex::setComplex( double real, double imag )
// Mutator
//
// PRE:  (none)
//
// POST: complex number is real + imag*i
{
    realPart = real;
    imagPart = imag;
}

double Complex::getReal() const
// Accessor
//
// PRE:  (none)
//
// POST: real part is returned
{
    return realPart;
}

double Complex::getImag() const
// Accessor
//
// PRE:  (none)
//
// POST: imaginary part is returned
{   
    return imagPart;
}

const Complex Complex::operator+( const Complex& rComplex ) const
// Accessor -- Member operator function
//
// PRE:  (none)
//
// POST: the sum of this Complex and rComplex is returned
{
    Complex sum;

    sum.realPart = realPart + rComplex.realPart;
    sum.imagPart = imagPart + rComplex.imagPart;

    return sum;
}

const Complex operator-( const Complex& lComplex, const Complex& rComplex )
// Non-member friend operator function
//
// PRE:  (none)
//
// POST: the difference of this Complex and rComplex is returned
{
    Complex difference;

    difference.realPart = lComplex.realPart - rComplex.realPart;
    difference.imagPart = lComplex.imagPart - rComplex.imagPart;

    return difference;
}

const Complex operator/( const Complex& lComplex, const Complex& rComplex )
// Non-member non-friend operator function
//
// PRE:  (none)
//
// POST: the quotient of this Complex and rComplex is returned
{
    double divisor = rComplex.getReal()*rComplex.getReal()
                   + rComplex.getImag()*rComplex.getImag();

    double realNum = lComplex.getReal()*rComplex.getReal()
                   + lComplex.getImag()*rComplex.getImag();

    double imagNum = lComplex.getImag()*rComplex.getReal() 
                   - lComplex.getReal()*rComplex.getImag();

    return Complex( realNum/divisor, imagNum/divisor );
}

const Complex& Complex::operator++()
// Mutator -- Member prefix operator function
//
// PRE:  (none)
//
// POST: the real part of the Complex is incremented by one and
//       the new value is returned
{
   realPart += 1.0;
   return *this;
}

const Complex Complex::operator--( int )
// Mutator -- Member postfix operator function
//
// PRE:  (none)
//
// POST: the real part of the Complex is decremented by one and
//       the original value is returned
{
   Complex value( *this );
   realPart -= 1.0;
   return value;
}

ostream& operator<<( ostream& outStream, const Complex& number )
// Non-member function
//
// PRE:  (none)
//
// POST: number is output to the given ostream in the form 
// [realPart] +/- [imagPart]i
//
// outStream is a valid ostream 
// Uses cout and << from iostream library
// Uses abs() from cmath library
{
    outStream << number.realPart << ( number.imagPart < 0 ? "-" : "+" )
        << fabs( number.imagPart ) << "i";

    return outStream;
}

istream& operator>>( istream& inStream, Complex& number )
// Non-member function
//
// PRE:  (none)
//
// POST: number has been read from the keyboard with format:
// [realPart]+/-[imagPart]i with no spaces
//
// inStream is a valid istream
// Uses cin and >> from iostream library
{
    char iChar;    // used to read 'i' 

    inStream >> number.realPart >> number.imagPart >> iChar;

    return inStream;
}

const Complex operator-( const Complex& value )
// Non-member non-friend operator function
//
// PRE:  (none)
//
// POST: the unary minus (negative) is returned
{
   return Complex( -value.getReal(), -value.getImag() );
}
