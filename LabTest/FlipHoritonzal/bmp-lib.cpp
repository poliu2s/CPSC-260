
#include<iostream>
#include<fstream>

using namespace std;


extern unsigned char red[2048][2048];
extern unsigned char green[2048][2048];
extern unsigned char blue[2048][2048];

static unsigned char header[2048];
static int offset;

#define OFFSETLOCATION 10
#define WIDTHLOCATION 18

void easy_read(ifstream &inputFile, int &width, int &height) {
  inputFile.seekg(OFFSETLOCATION);
  inputFile.read((char *)&offset, sizeof(offset));
  inputFile.seekg(WIDTHLOCATION);
  inputFile.read((char *) &width, sizeof(width));
  inputFile.read((char *) &height, sizeof(height));
  inputFile.seekg(0);
  inputFile.read((char *) &header, offset);  
  
  int padding = width % 4;
  
  cout << " width=" << width << " height=" << height << " offset=" << offset 
       << " padding= " << padding << endl;
  
  
int i=0,j=0;
unsigned char colour;
  
  
  for (i=0 ; i<height ; i++) {
    for ( j=0 ; j<width && !inputFile.eof() ; j++) {
      
      inputFile.read((char *)&blue[i][j], sizeof(colour));
      //blue[i][j] = colour;
      
      inputFile.read((char *)&colour, sizeof(colour));
      green[i][j] = colour;
      
      inputFile.read((char *)&colour, sizeof(colour));
      red[i][j] = colour;
    }
    for ( j=1  ; j<=padding ; j++) {
      // get the extra characters
      inputFile.read((char *) &colour, sizeof(colour));
    }
  }
}

void easy_write(ofstream &outfile, int width, int height) {

  outfile.write((char *)&header, offset);
  int padding = width % 4;
  //unsigned int padding = 0;
  int i=0,j=0;
  for ( i=0 ; i<height ; i++) {
    for ( j=0 ; j<width && !outfile.eof()  ; j++) {
      outfile.write((char *) &blue[i][j], sizeof(unsigned char));
      outfile.write((char *) &green[i][j], sizeof(unsigned char));
      outfile.write((char *) &red[i][j], sizeof(unsigned char));

    }
    // Add padding
    for ( j=1  ; j<=padding ; j++) {
      outfile.put(0);
    }
  }
  outfile.close();
}

