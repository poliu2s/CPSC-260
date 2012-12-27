// file: debug1.cpp
//
// Simple debugging example
//
// Modified by K. S. Booth on 2007-Sep-21
//
// This is an in-lab exercise and is incomplete or incorrect.
// The problems should be identified using a debugger.

#include <iostream>    // used in main()

using namespace std;

void printArray( int array1[], int length ) // Fixed Bug
// Pre: length is the number of elements in the array
// Post: prints given array to standard output
// Library facilities used: cout and operator<< from iostream
{
    int i;

    for ( i = 0; i != length ; i++ )
    {
        cout << "  " << array1[ i ];
    }
}


int sumEvenLocations( int array1[], int length ) // Fixed Bug
// Pre:  length is the number of elements in the array
// Post: sum of the array elements stored in even locations has been returned
//       (even locations are those with even indices: 0, 2, 4, ...)
{
    
	int sum = 0; // Fixed Bug
    int i;

    for ( i = 0; i < length ; i += 2 ) // Fixed Bug
    {
        sum += array1[ i ];
    }

    return sum; // Fixed Bug
}


int main()
// Library facilities used: cout object and operator<< from iostream
{
    int myArray1[ 6 ] = { 1, 17, 2, 5, 4, 20 };
    int myArray2[ 8 ] = { 1, 17, 2, 5, 4, 20, 9, 22 };
    int myArray3[ 7 ] = { 1, 17, 2, 5, 4, 20, 3 };

    cout << "myArray1 contains: {";
    printArray( myArray1, 6 );
    cout << " }\n";

    cout << "The sum of elements at even locations is "
        << sumEvenLocations( myArray1, 6 ) << "\n\n";

    cout << "myArray2 contains: {";
    printArray( myArray2, 8 );
    cout << " }\n";

    cout << "The sum of elements at even locations is "
        << sumEvenLocations( myArray2, 8 ) << "\n\n";

    cout << "myArray3 contains: {";
    printArray( myArray3, 7 );
    cout << " }\n";

    cout << "The sum of elements at even locations is "
        << sumEvenLocations( myArray3, 7 ) << "\n\n";

    return 0;   // normal exit code
}
