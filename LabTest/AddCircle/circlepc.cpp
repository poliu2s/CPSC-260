

// This program reads the contents of a bmp image, draws a circle
// and writes the new image out

// Include files required for this program - no other includes are needed

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;



// Add prototypes for supplied code to read and write an image file
void easy_read(ifstream &fname,int &width, int &height);
void easy_write(ofstream &fname, int width, int height);


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
//               - radius is the radius of the desired circle
// post-condition - a circle is drawn into the contents of the arrays
//                  red, green and blue
//                  the circle will be centered at width/2 and height/2
//                  and it will be coloured black
// 
// The function bmp_circle returns void and takes as its arguments
// three integers width, height, and radius respectively 

// Complete the following line with the function definition
void bmp_circle(int width, int height, int radius)
{
  // Declare and initialize to zero 2 local variables
  // that identify the row and column of the current pixel 
  int row = 0;
  int column = 0;
  
  // Declare two variables, centre_row and centre_column 
  // that identify the centre of the picture. Initialize the two 
  // variables to the middle row and middle column respectively. 
  // The middle row is 1/2 the height of the picture and the 
  // centre column is 1/2 the width of the picture 

  int center_row = height / 2;
  int center_column = width / 2;
  
  
  // Descriptive comment - The routine will now iterate over 
  // each pixel in the picture and compute its distance from the 
  // the centre of the picture. If the distance is less than or 
  // equal to the radius value passed in, the pixel is inside a circle
  // of the specified radius and the pixel at the location is changed
  // to yellow.

  // set the radius parameter to be the square of itself.
  
  radius = radius * radius;


  // Descriptive Comment: -- Recall that the formula for a
  // a circle in a cartesian co-ordinate system is 
  // X^2 + y^2 = R^2. 

  // The above assumes that the circle is centred at 0, 0
  // which is not the case here. So the first thing to do is 
  // compute new X and Y values coresponding to a 0,0 located circle
  // Once that is done X^2 + y^2 can be compared to R^2 to see if the 
  // point is inside or outside the circle
  
  // iterate over each row
  for (row=0 ; row < height; row++) 
    {
      // Declare the variable newY and set it to the 
      // number of rows from the current row to the centre row.
      // The number is to be signed
      int newY = row - center_row;
      
      // square newY
      newY *= newY;
      
      // iterate over each pixel column in the row
      for (column=0 ; column<width; column++) 
        {
          // Declare a newX variable and set newX to be the 
          // number of columns from the current column to the 
          // centre column
          int newX = column - center_column;
          
          // square newX;
          newX = newX * newX;
          
          // if  newX + newY  (really X^2 + y^2 at this point)
          //    less than or equal to the current value of 
          // radius (i.e. R^2) the point is inside the circle
	  
          // Replace with if statement that evaluates the above
          if (newX + newY <= radius) 
          { // code to execute when X^2 + Y^2 <= R^ is true
            // Colour the original pixel yellow (R = 255, G = 255, B = 0)
            // the pixel location of interest is current row and column
            // being iterated on
	    red[row][column] = 255;
	    green[row][column] = 255;
	    blue[row][column] = 0;
	  }
        }
    }
}


// Declare the main program
int main(int argc, char **argv) 
{
  
  // Declare 2 string variables for filenames
  string inputName, outputName;
  
  // Declare a variable for the radius of the circle
  int radius;
  
  // Prompt for and read the image input file name using the string
  //  "Enter the name of the file to open: "
  cout << "Enter the name of the file to open: ";
  cin >> inputName;
  
  
  // Complete the following to open the file by replacing XX with
  // the variable holding the name of the file to open
  ifstream inputImage(inputName.c_str(), ios::binary);
  
  // Verify that the file was opened and if not print
  //  "Could not open: " along with the file name on a 
  // single line and return -10
  
  if (!inputImage) {
    cerr << "Could not open: " << inputName << endl;
    return -10;
  }
  
  // Prompt with "Enter the radius of the circle in pixels: "
  cout << "Enter the radius of the circle in pixels: ";
  cin >> radius;
  
  
  // Prompt for the name of the file to save the new image to using
  // the string:  "Enter the name of the file to save to: "
  
  cout << "Enter the name of the file to save to: ";
  cin >> outputName;
  
  // Complete the following to open the file by replacing XX with
  // the variable holding the name of the file to open
  ofstream    outputImage(outputName.c_str(), ios::binary);
  
  // Verify that the file was opened and if not print
  //  "Could not open: " along with the file name on a 
  // single line and return -30
  
  
  if (!outputImage) {
    cerr << "Could not open: \"" <<  outputName << "\" for writing. " << endl; 
    return -30;
  }
  
  // Declare local variables to get the width and height of the image
  int width, height;
  
  // Call easy_read() to read the image
  
  easy_read(inputImage, width, height);
  
  // call bmp_circle() to draw a circle
  
  bmp_circle(width, height, radius);
  
  // Write the image to the file output file
  easy_write(outputImage, width, height);
  
  
  return 0;
}
