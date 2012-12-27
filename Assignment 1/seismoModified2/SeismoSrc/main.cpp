
//
// This is example code from Chapter 15.6.1 "Reading a file" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 8th, 2010
//				Jul 7th, 2010
//				Jul 6th, 2010
//created data (downloading data) : Jul 5th, 2010

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities
#include "std_lib_facilities.h"
#include <iostream>
#include <string>

//------------------------------------------------------------------------------

struct Distribution {
    int recordedData;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Distribution& d)
// assume format: one integer per line
{ 
    Distribution dd;


    is >>dd.recordedData;
    if(!is) return is;
    d = dd;
    return is;
}

//------------------------------------------------------------------------------

class Scale {                // data value to coordinate conversion
    int cbase;               // coordinate base
    int vbase;               // base of values
    double scale;
public:
    Scale(int b, int vb, double s) :cbase(b), vbase(vb), scale(s) { }
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

//invarient: totalSlots(maximum number of ints being stored at a time)
//a type that can keep adding new integers and dumping the oldest ones while the 
//total amount of integers being stored at a time conserves
class CustomedList {		
	int counter; 
	int slots;//total slots available
	int total;//total number of int has been inserted
	bool reused;//once total>slots, new inserted ints will be stored from the beginning of the list (the list is being reused)
	int* list; 

public:
	CustomedList(int b) :slots(b){ 
		counter=0;
		list = new int[b];
		reused = false;
		total = 0;
	}

	//pre: none
	//post: an int being inserted
	//	if total<slots, the new int will be stored in a new slot
	//  else, the latest inserted int will be replaced by the new int
	void insert(int a){
		list[counter] = a;
		counter++;
		total++;
		if (counter == slots){
			counter = 0;
			reused = true;
		}
	}

	//pre: 0 <= b < numbers being inserted into the object (in case total < slots)
	//pre: 0 <= b < slots (for total > slots)
	//b = 0 as the the earliest int being inserted 
	//post: return the int corresponding to possition b
	int getInt ( int b){
		if (!reused)
			return list[b];
		else{
			if (counter+b+1>=slots)
				return list[counter+b+1-slots];
			else
				return list[counter+b+1];
		}
	}

	//pre: none
	//post: return reused;
	bool isReused(){
		return reused;
	}

	//pre:none
	//post: return the total number being stored in the list
	int getTotal (){
		if (!reused) return total;
		else return slots;
	}
			
};

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 1000;    // window size
    const int ymax = 800;

    const int xoffset = 100; // distance from left hand side of window to y axis
    const int yoffset = 400;  // distance from bottom of window to x axis

    const int xspace = 40;   // space beyond axis
    const int yspace = 40; 

    const int xlength = xmax-xoffset-xspace;    // length of axes
    const int ylength = ymax-yspace*2;

    const int sampleNum = 48000;

    const double xscale
        = double(xlength)/(sampleNum); // scale of x values
    const double yscale = double(ylength)/10000000;  // scale of y values --> basically the zoom

    Scale xs(xoffset,0,xscale);
    Scale ys(yoffset,0,-yscale);



	// Asks the user to enter the directory name and changes any '/' to '\\'
    cout << "Please enter the file name and directory of the seismic data: " << endl;
	cout << "Note: the program will exit immediately if directory or file name does not exist" << endl;
	cout << "(Example: L:/Courses/cs260/A1Data/earthq1.PGC.BHZ)" << endl << endl;
	string file_name;
    cin >> file_name;
	cout << endl << endl;

	string searchString = "/";
	string replaceString = "\\";
	

	string::size_type pos = 0;
    while ( (pos = file_name.find(searchString, pos)) != string::npos ) {
        file_name.replace( pos, 1, replaceString );
		file_name.insert( pos, replaceString );
        pos++;
    }

	

	// Open the file from the given directory with error checking
	ifstream ifs;
	ifs.open(file_name);
	if (!ifs) error("can't open ",file_name);

    

    Distribution d;

	string title;  //title
	getline(ifs, title);  

	string tempDate;  //temperate storage of the date
	getline(ifs, tempDate);  

	stringstream ss(tempDate);
	char date;

	//complete the title
	ss>>date; title = title+" "+date; ss>>date; title = title + date; ss>>date; title = title + date; ss>>date; title = title + date;
	ss>>date; title = title+" "+date; ss>>date; title = title + date;
	ss>>date; title = title+" "+date; ss>>date; title = title + date;
	ss>>date;
	ss>>date; title = title+" "+date; ss>>date; title = title + date;
	ss>>date; title = title+":"+date; ss>>date; title = title + date;
	ss>>date; title = title+"'"+date; ss>>date; title = title + date+"''";

	//go through the next two lines
	getline(ifs, tempDate); 
	getline(ifs, tempDate);  

	
	cout<<"Regarding to reality, and due to designing purpose, datas within 15 minutes     after a trigger value has been detected would not be examined (they will only be displayed on the graph)."<<endl;
	cout<<"As a result, please make sure the trigger value is sufficiently high enough."<<endl;
	cout<<"Please enter an trigger value: "<<endl;	
	int triggerValue;
	cin>>triggerValue;

	//Check if trigger value is positive
	if (!(triggerValue>0)) {
		cout << "The trigger value must be an integer and greater than 0." << endl;
		return 0;
	}

	cout << endl << "Please be patient..." << endl;

	const int fiveMin = 12000; //sample numbers for 5 minutes
	const int maxMin = 48000; //max sample numbers (20minutes)

	//using the array beforeEarthQuake to collect 5 minutes worth of data
	CustomedList beforeEarthQuake(fiveMin); 
	 
	//------------------------------------------------------------------------------start going over the file
    while (ifs) {
		 
		int tempt;// it holds the next data which being examined
		
		//start reading datas from the file again
		
		ifs>>d;
		tempt = d.recordedData ;
		
		//trigger value detected
		if (tempt>=triggerValue){
			Open_polyline recordedData;
			int dataCounter = 0;

			//------------------------------------------------------------previous 5 minutes!!
			//load datas from the array beforeEarthQuake to the line 
			dataCounter = fiveMin - beforeEarthQuake.getTotal();
			for (int k = 0; k < beforeEarthQuake.getTotal(); k++){
				int x = xs(dataCounter);
				recordedData.add(Point(x,ys(beforeEarthQuake.getInt(k))));
				dataCounter++;
			}
			//loading datas for the previous 5 minutes finished
			
			//load the trigger value
			recordedData.add(Point(xs(dataCounter),ys(tempt)));

			//keep on loading new data from the file
			while (ifs>>d && dataCounter < maxMin) {
				int x = xs(dataCounter);
				recordedData.add(Point(x,ys(d.recordedData)));
				dataCounter++;

				//load the last five minutes to beforeEarthQuake
				
				if ((maxMin - dataCounter - fiveMin)<0)
					beforeEarthQuake.insert(d.recordedData);
							
			}
			//--------------------- Lay out of the Graph -----------------------------------------------------------
			Simple_window win(Point(100,100),xmax,ymax,title);
			
			// Plot the x axis representing time
			Axis x(Axis::x, Point(xoffset,ymax-yoffset), xlength, 20, "Time (minutes)");
			x.label.move(550,0);

			//Plot the y axis representing Magnitude
			Axis y(Axis::y, Point(xoffset,ymax-yspace), ylength, 0,"Magnitude (Seismic Units)");
			y.label.move(-10, -10);

			// Declaration of Time Labels
			Text time_Labels0(Point(xoffset + 0*(double)xlength/20 - 5 , ymax-yoffset - 7), "-5");
			Text time_Labels1(Point(xoffset + 1*(double)xlength/20 - 5 , ymax-yoffset - 7), "-4");
			Text time_Labels2(Point(xoffset + 2*(double)xlength/20 - 5 , ymax-yoffset - 7), "-3");
			Text time_Labels3(Point(xoffset + 3*(double)xlength/20 - 5 , ymax-yoffset - 7), "-2");
			Text time_Labels4(Point(xoffset + 4*(double)xlength/20 - 5 , ymax-yoffset - 7), "-1");
			Text time_Labels5(Point(xoffset + 5*(double)xlength/20 - 5 , ymax-yoffset - 7), "0");
			Text time_Labels6(Point(xoffset + 6*(double)xlength/20 - 5 , ymax-yoffset - 7), "1");
			Text time_Labels7(Point(xoffset + 7*(double)xlength/20 - 5 , ymax-yoffset - 7), "2");
			Text time_Labels8(Point(xoffset + 8*(double)xlength/20 - 5 , ymax-yoffset - 7), "3");
			Text time_Labels9(Point(xoffset + 9*(double)xlength/20 - 5 , ymax-yoffset - 7), "4");
			Text time_Labels10(Point(xoffset + 10*(double)xlength/20 - 5 , ymax-yoffset - 7), "5");
			Text time_Labels11(Point(xoffset + 11*(double)xlength/20 - 5 , ymax-yoffset - 7), "6");
			Text time_Labels12(Point(xoffset + 12*(double)xlength/20 - 5 , ymax-yoffset - 7), "7");
			Text time_Labels13(Point(xoffset + 13*(double)xlength/20 - 5 , ymax-yoffset - 7), "8");
			Text time_Labels14(Point(xoffset + 14*(double)xlength/20 - 5 , ymax-yoffset - 7), "9");
			Text time_Labels15(Point(xoffset + 15*(double)xlength/20 - 5 , ymax-yoffset - 7), "10");
			Text time_Labels16(Point(xoffset + 16*(double)xlength/20 - 5 , ymax-yoffset - 7), "11");
			Text time_Labels17(Point(xoffset + 17*(double)xlength/20 - 5 , ymax-yoffset - 7), "12");
			Text time_Labels18(Point(xoffset + 18*(double)xlength/20 - 5 , ymax-yoffset - 7), "13");
			Text time_Labels19(Point(xoffset + 19*(double)xlength/20 - 5 , ymax-yoffset - 7), "14");
			Text time_Labels20(Point(xoffset + 20*(double)xlength/20 - 5 , ymax-yoffset - 7), "15");
			


			// Declaration of Magnitude Labels (values are hard-coded in)
			Text seismic_Labels01(Point(xoffset-80,ymax-yspace), "-5000000");
			Text seismic_Labels02(Point(xoffset-80,ymax-yspace - 1*(double)ylength/10), "-4000000");
			Text seismic_Labels03(Point(xoffset-80,ymax-yspace - 2*(double)ylength/10), "-3000000");
			Text seismic_Labels04(Point(xoffset-80,ymax-yspace - 3*(double)ylength/10), "-2000000");
			Text seismic_Labels05(Point(xoffset-80,ymax-yspace - 4*(double)ylength/10), "-1000000");
			Text seismic_Labels06(Point(xoffset-80,ymax-yspace - 5*(double)ylength/10), "0");
			Text seismic_Labels07(Point(xoffset-80,ymax-yspace - 6*(double)ylength/10), "1000000");
			Text seismic_Labels08(Point(xoffset-80,ymax-yspace - 7*(double)ylength/10), "2000000");
			Text seismic_Labels09(Point(xoffset-80,ymax-yspace - 8*(double)ylength/10), "3000000");
			Text seismic_Labels10(Point(xoffset-80,ymax-yspace - 9*(double)ylength/10), "4000000");
			Text seismic_Labels11(Point(xoffset-80,ymax-yspace - 10*(double)ylength/10), "5000000");
			
			
			// Declaring and formating of dashed line at t=0
			Line activation_point(Point(xs(12000),yspace),Point(xs(12000),ymax - yspace));
			activation_point.set_style(Line_style::dash);
	 
			// Plot data labels
			Text data_label(Point(xmax-200,ymax-yspace*2),"Plotted Seismic Data");
			recordedData.set_color(Color::red);
			data_label.set_color(Color::red);

			// Graph Title
			Text graphTitle(Point(xspace*4,yspace), "Graph of Seismic Data Illustrating Earthquake Magnitude from -5 to +15 mins");
			graphTitle.set_color(Color::blue);


			// Attach everything to the window
		    //win.attach(recordedData);

			win.attach(data_label);
			
			win.attach(seismic_Labels01);
			win.attach(seismic_Labels02);
			win.attach(seismic_Labels03);
			win.attach(seismic_Labels04);
			win.attach(seismic_Labels05);
			win.attach(seismic_Labels06);
			win.attach(seismic_Labels07);
			win.attach(seismic_Labels08);
			win.attach(seismic_Labels09);
			win.attach(seismic_Labels10);
			win.attach(seismic_Labels11);

			win.attach(time_Labels0);
			win.attach(time_Labels1);
			win.attach(time_Labels2);
			win.attach(time_Labels3);
			win.attach(time_Labels4);
			win.attach(time_Labels5);
			win.attach(time_Labels6);
			win.attach(time_Labels7);
			win.attach(time_Labels8);
			win.attach(time_Labels9);
			win.attach(time_Labels10);
			win.attach(time_Labels11);
			win.attach(time_Labels12);
			win.attach(time_Labels13);
			win.attach(time_Labels14);
			win.attach(time_Labels15);
			win.attach(time_Labels16);
			win.attach(time_Labels17);
			win.attach(time_Labels18);
			win.attach(time_Labels19);
			win.attach(time_Labels20);


			win.attach(x);
			win.attach(y); 
			win.attach(activation_point);
			win.attach(graphTitle);

			win.attach(recordedData);

			//reattach some components since they might be covered by the graph 
			win.attach(time_Labels0);
			win.attach(time_Labels1);
			win.attach(time_Labels2);
			win.attach(time_Labels3);
			win.attach(time_Labels4);
			win.attach(time_Labels5);
			win.attach(time_Labels6);
			win.attach(time_Labels7);
			win.attach(time_Labels8);
			win.attach(time_Labels9);
			win.attach(time_Labels10);
			win.attach(time_Labels11);
			win.attach(time_Labels12);
			win.attach(time_Labels13);
			win.attach(time_Labels14);
			win.attach(time_Labels15);
			win.attach(time_Labels16);
			win.attach(time_Labels17);
			win.attach(time_Labels18);
			win.attach(time_Labels19);
			win.attach(time_Labels20);

			win.attach(x);
			win.attach(activation_point);
			win.attach(graphTitle);

			win.wait_for_button();
			

		}	


		else beforeEarthQuake.insert(tempt); //if tempt is not greater then the trigger value, store it in beforeEarthQuake 
		
	}
}

catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

//------------------------------------------------------------------------------
