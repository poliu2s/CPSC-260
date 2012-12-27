#include <iostream>
// Author: Norm Hutchinson (cobbled together from stuff written by Paul Carter)
// Date: Dec 2, 2004

// Purpose: generates a list of random integers and sorts it using Heapsort

#include "CTimer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "randomInt.h"
#include <string>
using namespace std;

int listSize = 0;

template< typename type >
void heapsort( type* data, int size )
	//PRE: the capacity of the array pointed to by data
	//     is at least size
	//POST: the first size elements of data have been
	//     sorted in descending order
{
    int swpIndx;
    buildHeap( data, size );
    for ( swpIndx = size - 1; swpIndx > 0; swpIndx-- )
	{
        swap( data[ 0 ], data[ swpIndx ] );
        reheapDown( data, 0, swpIndx );
	}
}

template< typename type >
void buildHeap( type* data, int size )
	//PRE: data points to an array of data of capacity at
	//     least size elements
	//POST: the first size elements of data are a heap
{
    int index;
    for( index = size / 2 - 1; index >= 0; index-- )
        reheapDown( data, index, size );
}

template< typename type >
void reheapDown( type* data, int top, int size )
// PRE: data between index top + 1 and index size  1
//      is a heap
// POST: data between index top and index size  1 is
//      a heap
{
    int leftChild = 2 * top + 1;
    int rightChild = 2 * top + 2;
    int minChild;
	if( leftChild < size )
    {
        // find index of smallest child
        if( rightChild >= size ||
			data[ leftChild ] < data[ rightChild ] )
            minChild = leftChild;
        else
			minChild = rightChild;

        // if data at top is greater than smallest
		// child then swap and continue
		if( data[ top ] > data[ minChild ] )
        {
            swap( data[ top ], data[ minChild ] );
            reheapDown( data, minChild, size );
        }
    }
}

void initialize(int *list, int size)
	// PRE:  none
	// POST: list contains LISTSIZE random integers in the range
	//       1..LISTSIZE
{
    CRandomInt random( 1, listSize );

    for( int index = 0; index < size; index++ )
        list[ index ] = random.getRand();
}

void print(int *list, int size)
	// PRE: none
	// POST: the first size ints in the list are printed
{
    for( int index = 0; index < size; index++ )
        cout << list[ index ] << " ";
	cout << endl;
}

// Generate a list of 100 ints, sort them and print them
int main( void )
{
    srand( ( unsigned int ) time ( 0 ) );

	cout << "Enter the size of the array to sort: ";
    cin >> listSize;
    int *list = new int[listSize];

    cout << "Initializing..." << endl;
    initialize( list, listSize );



// This part can be repeated to compare unsorted and sorted data
//
//
    cout << "Sorting..." << endl;
    CTimer timer;
    timer.start();
    heapsort( list, listSize );
    timer.stop();
  



#ifdef VERBOSE
    cout << "Printing..." << endl;
    print( list, listSize);
#endif
//
//
// End of repeat loop
   string wait;
	cout << "Enter a character followed by a carriage return to end" << endl;
	cin >> wait;

    return 0;
}
