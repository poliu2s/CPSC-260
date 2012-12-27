// Author: Paul Carter
// Date: March 13, 2001
// Modified: November 16, 2001

#define LINEAR

// Purpose: generates a vector of random integers and sorts it using Quicksort

#include "CTimer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "randomInt.h"
#include <string>
using namespace std;

int listSize = 800000;

void initialize( vector< int >& list );
template< class itemType >
void quicksort( vector< itemType >& list, int left, int right );
template< class itemType >
void swapValues( itemType& value1, itemType& value2 );
template< class itemType >
int partition( vector< itemType >& list, int left, int right );
template< class itemType >
void print( const vector< itemType >& list );


int main( void )
{
    srand( ( unsigned int ) time ( 0 ) );

	cout << "Enter the size of the list to use: ";
	cin >> listSize ;
    vector< int > list( listSize );

    cout << "Initializing..." << endl;
    initialize( list );

// This part can be repeated to compare unsorted and sorted data
//
//
    cout << "Sorting..." << endl;
    CTimer timer;
    timer.start();
    quicksort( list, 0, list.size() - 1 );
    timer.stop();
    cout << "Time: " << timer.elapsedTime() << endl;
 


#ifdef VERBOSE
    cout << "Printing..." << endl;
    print( list );
#endif
//
//
// End of repeat loop
  string wait;
	cout << "Enter a character followed by a carriage return to end" << endl;
	cin >> wait;

    return 0;
}

void initialize( vector< int >& list )
// Postcondition: list contains LISTSIZE random integers in the range
// 1..LISTSIZE
{
    CRandomInt random( 1, listSize );
    int size = list.size();

    for( int index = 0; index < size; index++ )
        list[ index ] = random.getRand();
}



#ifdef LINEAR

// This version requires O(N) stack space in the worst case

template< class itemType >
void quicksort( vector< itemType >& list, int left, int right )
// Postcondition: list elements between index left and index right have been
// sorted in increasing order
{
    if( left < right )
    {
        int pivotPosition = partition( list, left, right );
        quicksort( list, left, pivotPosition - 1 );
        quicksort( list, pivotPosition + 1, right );
    }
}


#else

// This version recursively sorts only the smaller partition and 
// requires O( log N ) stack space in the worst case

template< class itemType >
void quicksort( vector< itemType >& list, int left, int right )
// Postcondition: list elements between index left and index right have been
// sorted in increasing order
{
    while( left < right )
    {
        int pivotPosition = partition( list, left, right );
        if( pivotPosition - left < right - pivotPosition )
        {
            quicksort( list, left, pivotPosition - 1 );
            left = pivotPosition + 1;
        }
        else
        {
            quicksort( list, pivotPosition + 1, right );
            right = pivotPosition - 1;
        }
    }
}

#endif


template< class itemType >
void swapValues( itemType& value1, itemType& value2 )
// Postcondition: value1 and value2 have been swapped
{
    itemType temp;

    temp = value1;
    value1 = value2;
    value2 = temp;
}


template< class itemType >
int partition( vector< itemType >& list, int left, int right )
// Precondition: pivot element is at position left
// Postcondition: list has been partitioned so that elements
// list[ left ] .. list[ pivotPosition - 1 ] are less than or equal to pivot element
// and elements list[ pivotPosition + 1 ] .. list[ right ] are greater
// than or equal to pivot element.  Position of pivot element has been returned
{
    itemType pivotValue = list[ left ];
    int originalLeft = left;
    
    do
    {
        do
        {
            left++; 
        }while( list[ left ] < pivotValue && left < right );

        while( list[ right ] > pivotValue )
            right--;

        if( left < right )
            swapValues( list[ left ], list[ right ] );

    }while( left < right );

    swapValues( list[ originalLeft ], list[ right ] );

    return right;
}

template< class itemType >
void print( const vector< itemType >& list )
// Postcondition: list has been printed on screen
{
    int size = list.size();

    for( int index = 0; index < size; index++ )
        cout << list[ index ] << " ";
}
