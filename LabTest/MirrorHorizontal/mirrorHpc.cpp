

// This program reads the contents of a bmp image, mirrors it
// along a horizontal line based at the centre row of 
// the image and writes the new image out

// Include files required for this program - no other includes are needed

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;



// Add prototypes for supplied code to read and write an image file
void easy_read(ifstream &inputFile, int &width, int &height);
	void easy_write(ofstream &outfile, int width, int height);


// Global variables red, green and blue. These variables
// are shared with bmp-lib.cpp. The routines in bmp-lib
// read/write the image data to/from a file into these variables.
// Declare the red,  green, and blue global variables here. 
 unsigned char red[2048][2048];
 unsigned char green[2048][2048];
 unsigned char blue[2048][2048];




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
// Special Note: BMP images are stored so that the first row of the 
//               image file is the bottom row of the image which 
//               further implies that the last row of the image file
//               is the top row of the image as displayed
// 
// The function bmp_mirror returns void and takes as its arguments
// two integers width and height respectively 

// Complete the following line with the function definition
 void bmp_mirror(int width, int height)
{
  // Declare and initialize to zero 2 local variables
  // that identify the row and column of the current pixel 
	int row=0;
	int col =0;

  
  //  Declare one variable to keep track of the destination row
  //  for the column being copied from the original. 
  //  Set the initial value
  //  to the last row for the image (Remember the 
  //  last row number is one less than the reported height of the image
	int dest_row = height - 1;
  
  
  // iterate over half the rows in the image. (i.e. (height + 1)/2
	for (row = 0; row<(height+1)/2; row++)
    {
      
      // iterate over each column in the image
		for (col =0; col < width; col++)
        {
          // Copy the three colours of the mirror pixel (i.e. mirror_row,column)
          // *to* the current row location (i.e. row, column)
			red[row][col] = red[dest_row][col];
			blue[row][col] = blue[dest_row][col];
			green[row][col] = green[dest_row][col];

	}
      
      // Decrement by 1 the mirrored column location
		dest_row--;
    }
}


// Declare the main program
 int main() {
  
  // Declare 2 string variables for filenames
	 string file1;
	 string file2;
  
  // Prompt for and read the image input file name using the string
  //  "Enter the name of the file to open: "
	 cout << "enter the name of the file to open: ";
	 cin >> file1;

  
  
  
  
  // Complete the following to open the file by replacing XX with
  // the variable holding the name of the file to open
  ifstream inputImage(file1.c_str(), ios::binary);
  
  // Verify that the file was opened and if not print
  //  "Could not open: " along with the file name on a 
  // single line and return -10
  
  if (!inputImage) {
	  cerr << "Could not open: " << file1 << endl;
	  return -10;
  }



  
  // Prompt for the name of the file to save the new image to using
  // the string:  "Enter the name of the file to save to: "
  cout << "enter the name of the file to save to :";
  cin >> file2;


  
  // Complete the following to open the file by replacing XX with
  // the variable holding the name of the file to open
  ofstream    outputImage(file2.c_str(), ios::binary);
  
  // Verify that the file was opened and if not print
  //  "Could not open: " along with the file name on a 
  // single line and return -30
  if (!outputImage) {
	  cerr << "Could not open: " << file2 << endl;
	  return -30;
  }

  




  
  // Declare local variables to get the width and height of the image
  int l_width;
  int l_height;
  
  // Call easy_read() to read the image
  easy_read(inputImage, l_width, l_height);

  
  // Call bmp_mirror() to mirror the image vertically
  bmp_mirror(l_width, l_height);

  
  // Write the image to the file output file
  easy_write(outputImage, l_width, l_height);
  
  
  return 0;
}

