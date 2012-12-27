/* This program draws the following pattern on the screen:

**************
 ************
  **********
   ********
    ******
     ****
      **

*/


// Include files required for this program - no other includes are needed
#include <iostream>
#include <cstdlib>

using namespace std;

// 2 Dimensional 80x80 global variable named pattern to store the pattern



// pre-condition - global array pattern is populated with pattern data
// post-condition - the contents of the pattern have been displayed
//
// The function called display_pattern returns void and takes as its argumenst
// one integer which denotes the number of rows in the pattern

// Complete the following line with the function definition

{
  
  // declare variables used for looping over the columns and rows


  // print out a new line

  
  // iterate over pattern's rows

  {
    
        // iterate over pattern's columns printing out each element
    // in the row. (remember there are twice
    // as many columns as there are rows) 

    {

    }
    
    // print a new line // not part of the previous iteration

    }
  
}


// pre-condition - the pattern array is empty
// post-condition - the pattern array contains the required pattern 
//
// The function generate_pattern returns void and takes as its arguments
// one integer which denotes the number of rows in the pattern

// Complete the following line with the function definition

{
  // Declare 2 variables i, and j to keep track of current position
  // within the pattern. Initialize these variables to 0

  
  // Declare 2 variables, i and j to be used for looping


  // Set i = to 1 and then using i loop for the number of rows in the picture 

  {
    
    // descriptive comment - loop for generating upper triangle on the left
    
    // Using j loop from 1 to i

    {
      // Set this pattern location x,y to '*'

      // increment y

    }
    
    // descriptive comment - loop for generating spacing
    
    // Using j loop from the high number (number of rows - i)*2 to 1 

    {
      // Set this pattern location x,y to ' '

      // increment y

    }
    
    // descriptive comment - loop for generating upper triangle on the right
    
    // Using j loop from 1 to i

    {
      // set this pattern location x,y to '*'

      // increment y

    }
    
    // move to next line by incrementing x and setting y to 0        

  }
}


// Declare the main program

{
  
  // Declare local variable to get the number of rows

  
  // prompt the  user to input the number of rows 
  //using the prompt "Enter the number of rows: "


  
  // Call generate_pattern to generate and store the required pattern
  // Use the size read above as the parameter
        

        
  // call display_pattern with the size read above as the parameter
 

  
  // wait for user action
  system("pause");
  return 0;
}
