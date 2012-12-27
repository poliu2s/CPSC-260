

// This program reads the contents of a bmp image, mirrors it
// along a vertical line based at the centre column of 
// the image and writes the new image out

// Include files required for this program - no other includes are needed

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;



// Add prototypes for supplied code to read and write an image file




// Global variables red, green and blue. These variables
// are shared with bmp-lib.cpp. The routines in bmp-lib
// read/write the image data to/from a file into these variables.
// Declare the red,  green, and blue global variables here. 





// pre-condition - global arrays of red, green and blue 
//                   are populated with image data
//               - width accurately indicates the number
//                       of horizontal pixels of the image
//               - height accurately indicates the number of
//                       vertical pixels
// post-condition - the contents of the arrays red, green, and blue
//                  have been changed so that the image they
//                  now contain has been mirrored along a vertical line
// 
// The function bmp_mirror returns void and takes as its arguments
// two integers width and height respectively 

// Complete the following line with the function definition

{
  // Declare and initialize to zero 2 local variables
  // that identify the row and column of the current pixel 


  
  
  
  // iterate over every row in the image

    {
      //  Declare one variable to keep track of the destination column 
      //  for the column being copied from the original. 
      //  Set the initial value
      //  to the last column for the image (Remember the 
      //  last column number is one less than the reported width of the image

      
      // iterate from column 0 to (column width + 1)/2

        {
          // Copy the three colours of the current pixel (i.e. row,column)
          // to the mirrored column location (i.e. row, mirror_column)



	  // Decrement by 1 the mirrored column location

          }
    }
  
}


// Declare the main program
int main(int argc, char **argv) {
  
  // Declare 2 string variables for filenames


  // Prompt for and read the image input file name using the string
  //  "Enter the name of the file to open: "


  
  
  
  
  // Complete the following to open the file by replacing XX with
  // the variable holding the name of the file to open
  ifstream inputImage(XX.c_str(), ios::binary);
  
  // Verify that the file was opened and if not print
  //  "Could not open: " along with the file name on a 
  // single line and return -10
  




  
  // Prompt for the name of the file to save the new image to using
  // the string:  "Enter the name of the file to save to: "
  


  
  // Complete the following to open the file by replacing XX with
  // the variable holding the name of the file to open
  ofstream    outputImage(XX.c_str(), ios::binary);
  
  // Verify that the file was opened and if not print
  //  "Could not open: " along with the file name on a 
  // single line and return -30
  
  




  
  // Declare local variables to get the width and height of the image

  
  // Call easy_read() to read the image
  

  
  // Call bmp_mirror() to mirror the image vertically
  

  
  // Write the image to the file output file

  
  
  return 0;
}

