// File:     Complex.h
//
// Author:   Paul Carter       *** Your name ALWAYS goes here
//           87654321          *** Your ID number ALWAYS goes here
//           pcarter           *** Your userID ALWAYS goes here
//           L2X               *** Your lab section ALWAYS goes here
//
// Modified: 2001 September 19 *** Add a new date if you modify the file!
//
// Complex class header file

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>    // used by operator<<

using namespace std;

// The Complex class defines a complex number composed of a real and 
// imaginary part, both represented by doubles. 

// Note: this version implements a convert constructor to convert
// from type double to type Complex rather than supplying several
// different versions of operator+

// Class Invariants:
// - The real and imaginary parts of a Complex are always defined

class Complex
{
public:

    Complex();
    // Default constructor
    // PRE:  (none)
    // POST: complex number is 0 + 0*i

    Complex( double real, double imag );
    // Parameterized constructor
    // PRE:  (none)
    // POST: complex number is real + imag*i

    Complex( double real );
    // Convert constructor
    // PRE:  (none)
    // POST: complex number is real + 0*i   

    void setComplex( double real, double imag );
    // Mutator
    // PRE:  (none)
    // POST: complex number is real + imag*i

    double getReal() const;
    // Accessor
    // PRE:  (none)
    // POST: real part is returned

    double getImag() const;
    // Accessor
    // PRE:  (none)
    // POST: imaginary part is returned

    const Complex operator+( const Complex& rComplex ) const;
    // Accessor -- Member operator function
    // PRE:  (none)
    // POST: the sum of this Complex and rComplex is returned

    friend const Complex operator-( const Complex& lComplex,
                              const Complex& rComplex );
    // Non-member friend operator function
    // PRE:  (none)
    // POST: the difference of lComplex and rComplex is returned

    inline const Complex operator*( const Complex& rComplex ) const
    // Accessor -- In-line member operator function
    // PRE:  (none)
    // POST: the product of this Complex and rComplex is returned
    {
        return Complex( realPart*rComplex.realPart
                        - imagPart*rComplex.imagPart,
                        realPart*rComplex.imagPart
                        + imagPart*rComplex.realPart );
    }

    inline const Complex operator~() const
    // Accessor -- In-line member operator function
    // PRE:  (none)
    // POST: the complex conjugate is returned
    {
       return Complex( realPart, -imagPart );
    }

    const Complex& operator++();
    // Mutator -- Member prefix operator function
    // PRE:  (none)
    // POST: the real part of the Complex is incremented by one and
    //       the new value is returned

    const Complex operator--( int );
    // Mutator -- Member postfix operator function
    // PRE:  (none)
    // POST: the real part of the Complex is decremented by one and
    //       the original value is returned

    friend ostream& operator<<( ostream& outStream, const Complex& number );
    // Non-member function
    // PRE:  (none)
    // POST: number is output to the given ostream in the form 
    // [realPart] + [imaginaryPart]i

    friend istream& operator>>( istream& inStream, Complex& number );
    // Non-member function
    // PRE:  (none)
    // PRE:  (none)
    // POST: number has been read from the keyboard with format:
    // [realPart]+/-[imagPart]i with no spaces

private:

    double realPart;
    double imagPart;
};

const Complex operator/( const Complex& lComplex, const Complex& rComplex );
// Non-member non-friend operator function
// PRE:  (none)
// POST: the quotient of lComplex and rComplex is returned

const Complex operator-( const Complex& value );
// Non-member non-friend operator function
// PRE:  (none)
// POST: the unary minus (negative) is returned

#endif
