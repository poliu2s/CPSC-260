// file: Sort-driver.cpp
// Lab test driver for sorting algorithms

#include <string>      // string class
#include <iostream>    // used in main()
#include <fstream>     // used in main()
#include <cassert>     // used in main()
#include <cctype>      // used in convert()

#include "MapBST.h"
#include "MapAVL.h"
#include "Pair.h"
#include "CTimer.h"
#include <string>

using namespace std;


void convert( string& word );
void buildMap( MapAbstract< string, int >& map, ifstream& infile );
void addDataToMap( MapAbstract< string, int >& map, ifstream& infile );
void showFrequencies( const MapAbstract< string, int >& map );


int main( int argc, char* argv[] )
// Library facilities used: cout and operator<< from stream.h
//                          ifstream and operator >> from ifstream.h
//                          assert() from assert.h
{
   MapBST <string, int> BSTmap;
   MapAVL <string, int> AVLmap;

   ifstream infile;
   char filename[128];

   string word;

   // Get the name of the input file (can't be more than 127 characters)
   cout << "Input file: ";
   cin >> filename;

   // MapBST

   infile.open( filename );
   assert( infile );

   cout << "\nRunning BST on " << filename << " ..." << endl;
   cout << "\nCreating a BST map..." << endl;
   
   buildMap( BSTmap, infile );
   
   infile.clear();
   infile.close();


   // MapAVL

   infile.open( filename );
   assert( infile );

   cout << "\nRunning AVL on " << filename << " ..." << endl;
   cout << "\nCreating an AVL map..." << endl;

   buildMap( AVLmap, infile );
   
   infile.clear();
   infile.close();
  string wait;
	cout << "Enter a character followed by a carriage return to end" << endl;
	cin >> wait;

   return 0;    // normal exit code
}


void convert( string& word )
// Post: punctuation marks have been stripped from word and
// remaining characters have been converted to lower case
//
// Library facilities used: inpunct() and tolower() from cctype
{
   int i = 0;
   int j = word.length() - 1;

   while ( i < j && ispunct( word[ i ] ) )
   {
      i++;
   }

   while ( j >= 0 && ispunct( word[ j ] ) )
   {
      j--;
   }

   word = word.substr( i, j - i + 1 );

   for ( int k = 0; k < word.length(); k++ )
   {
      word[ k ] = tolower( word[ k ] );
   }
}

void buildMap( MapAbstract< string, int >& map, ifstream& infile )
// Pre: infile is a valid input file stream
// Post: time taken to build map from data in file stream has been 
// printed on screen
{
   try
   {
      CTimer timer;
      timer.start();
      addDataToMap( map, infile );
      showFrequencies( map );
      timer.stop();
      cout << "Time: " << timer.elapsedTime() << endl;

   }
   catch( exception& excep )
   {
       cout << excep.what() << endl;
   }
}

void addDataToMap( MapAbstract< string, int >& map, ifstream& infile )
// Pre: infile is a valid input file stream
// Post: map has been built from data read from file stream
{
   string word;
   

   while( infile >> word )
   {
      convert( word );

      if ( map.empty( word ) )
      {
         map[ word ] = 1;
      }
      else
      {
         map[ word ] += 1;
      }
   }
}


void showFrequencies( const MapAbstract< string, int >& map )
// Post: the frequency of various words in the map has been displayed on the screen
{
   string testWords[] = { "the", "bzzr", "is", "cold" };
   int numWords = 4;

   cout << "\nThere are " << map.size() << " unique words" << endl;

   for( int count = 0; count < numWords; count++ )
   {
       if( map.empty( testWords[ count ] ) )
           cout << "The word \'" << testWords[ count ] << "\' does not occur." << endl;
       else
           cout << "The word \'" << testWords[ count ] << "\' occurs " << map[ testWords[ count ] ]
            << " times." << endl;
   }
}
