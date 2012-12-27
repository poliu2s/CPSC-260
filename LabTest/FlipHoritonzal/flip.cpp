

// This program reads the contents of a bmp image, flips the image horizontally
// and writes the new image out

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





// Declare 3 static unsigned char arrays with the dimensions of 
// of 2048 X 2048. This array will store the flipped image as it 
// is being built.






// pre-condition - global arrays of red, green and blue 
//                   are populated with image data
//               - width accurately indicates the number
//                       of horizontal pixels of the image
//               - height accurately indicates the number of
//                       vertical pixels
// post-condition - the contents of the arrays red, green, and blue
//                  have been changed so that the image they
//                  now contain has been flipped horizontally
// 
// The function bmp_flip returns void and takes as its arguments
// two integers width and height respectively 

// Complete the following line with the function definition

{
	// Declare and initialize to zero 2 local variables
	// that identify the row and column of the current pixel 



	//  Declare one variable to keep track of the destination row 
	//  for the row being copied from the original. Set the initial value
	//  to the last row for the image (Remember the 
	//  last row is one less than the reported height of the image
	int flipped_row = height - 1;

	// iterate over each row

	{
		// iterate over each pixel in the row

		{
			// Copy the three colours of the current pixel
			// to the flipped row location in the flipped version



		}
		// Decrement by 1 the flipped row location

	}

	// Copy the flipped image back to the original
	// Iterate over each row

	{
		// Iterate over each pixel in the row

		{
			// Copy each "flipped" pixel to its
			// same location in the original image



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



	// Call bmp_flip() to flip the image horizontally



	// Write the image to the file output file



	return 0;
}

