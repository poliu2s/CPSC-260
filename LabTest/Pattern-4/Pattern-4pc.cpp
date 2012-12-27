/* This program draws the following pattern on the screen:


********************
*********  *********
********    ********
*******      *******
******        ******
*****          *****
****            ****
***              ***
**                **
*                  *


*/

// Include files required for this program - no other includes are needed
#include <iostream>
#include <cstdlib>

using namespace std;

// 2 dimensional 80 x 80 global variable for storing the pattern



// pre-condition - global array pattern is populated with pattern data
// post-condition - the contents of the pattern have been displayed
//
// The function display_pattern returns void and takes as its arguments
// one integer which denotes the number of rows in the pattern 
// Complete the following line with the function definition named display_pattern

{
  
  // variables used for looping over the columns and rows

  
  // print out a new line

  
  // iterate over pattern's rows
  
  {
    
    // iterate over pattern's columns (remember there are n*2 columns)
    // printing out each element in the row

    
    // print a new line - not part of the iteration
    cout<<endl;
  }
}


// pre-condition - the pattern array is empty
// post-condition - the pattern array contains the required pattern 
//
// The function generate_pattern returns void and takes as its arguments
// one integer which denotes the number of rows in the patterns

// Complete the following line with the function definition for generate_pattern

{
  // declare 2 variables x and y to keep track of current position
  // within the pattern array, initialize them to 0

  
  // Declare 2 variables, i and j used for looping

  
  // using i and starting at 1 loop for the numer of rows in the picture
  
  {
    
    // Descriptive comment: loop for generating upper triangle on the left
    
    // using j loop from 1 to n-i + 1

    {
      // Set this pattern location x, y to *

      // increment y 

    }           
    
    // Descriptive Comment: loop for generating the spaces spacing
    
    // Using j loop from 1 to  one less than i

    {  
      // Set this pattern location x, y to ' '
    
      // increment y
    
      // Set this pattern location x, y to ' '
    
      // increment y
    
    }
    
    // Descriptive Comment: loop for generating upper triangle on the right
    
    // Using j loop from 1 to  n - i + 1

    {
      // set this pattern location x,y to '*'

      // increment y

    }       
    // move to next line by incrementing x, and setting y to 0       

  }
}
// Declare the main program

{
  
  // Declare local variable to get the number of rows
 
  
  // propmpt user to input size using the string "Enter the number of rows :"
  // and read the size


  
  // call generate_pattern to generate and store the required pattern

  
  // call display_pattern to display the required pattern

  
  // wait for user action
  system("pause");
  return 0;
}
