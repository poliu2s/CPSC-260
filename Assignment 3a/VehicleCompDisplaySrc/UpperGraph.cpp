#include "UpperGraph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"
#include "Graph.h"
#include <iostream>
#include <string>

#include "DisplaySleep.h"

using namespace std;


UpperGraph::UpperGraph(int slots)
{
	data = MyLinkedList(slots);
	
	graphx = 30;
	graphy = 220;

	
	x = new Axis(Axis::x, Point(graphx,graphy), 300, 10, "Time (seconds)");
	x->label.move(0, 0);
	z = new Axis(Axis::y, Point(graphx,graphy), 200, 0, "Throttle Position");
	z->label.move(0, 0);


	
	//tempLine.add(Point(30,220));
	//tempLine.add(Point(100, 300));

	
	
}

//the following 3 methods are from assignment 2 for the purpose of being used internally


//translate a single digit hex number into a decimal number
int UpperGraph::hexTranslator(char num){
	switch (num) {
	case 'A': return 10;
	case 'B': return 11;
	case 'C': return 12;
	case 'D': return 13;
	case 'E': return 14;
	case 'F': return 15;
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default:
		cout << "Error did not find a number!!!";

	}
}

//convert a 2 digits hex number into a decimal number
int UpperGraph::hexConverter(char left, char right){
	return (hexTranslator (left))*16+hexTranslator(right);
}


//pre: none
//post: data will be updated and stored into the list data
//modified from update from assignment 2
void UpperGraph::update(int newData){
		
	data.insert(newData);
	
	for (int i =0; i<60; i++) {

		display_points[i] = 0;
	}

	for (int i = 0; i < data.getTotal(); i++) {			// cycle through entire list
		
		cout << endl << "The datagetINt function:  " << data.getInt(i) << endl;
		display_points[i] = data.getInt(i);
		
	}


}

//pre: none
//post: return data
MyLinkedList UpperGraph::getData(){
	return data;
}

//and 3 more get method

UpperGraph::~UpperGraph()
{
	data.~MyLinkedList();
}


	

void UpperGraph::display(Window& screen) {



	
	
	tp_record = new Open_polyline;


	for (int i = 0; i<60; i++) {
		tp_record->add(Point(graphx+i*5, graphy - display_points[i]*2));
	}

	tp_record->set_color(Color::red);
	
	

	//Attach everything to screen
	screen.attach(*x);
	screen.attach(*z);
	screen.attach(*tp_record);
	

	screen.redraw();
	Fl::check();
	

	//DisplaySleep(40);



}

void UpperGraph::detach(Window& screen) {

	screen.detach(*x);
	screen.detach(*z);
	screen.detach(*tp_record);

	delete tp_record;
	tp_record = NULL;

}