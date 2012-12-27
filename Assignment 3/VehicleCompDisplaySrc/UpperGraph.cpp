

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 22th, 2010

#include "UpperGraph.h"
#include "MyList.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"
#include "Graph.h"
#include <iostream>
#include <string>

#include "DisplaySleep.h"

using namespace std;

// Invariant: Base class that contains a graph and one line plot

//Constructor
UpperGraph::UpperGraph(int slots)
{
	// List of values
	data = MyList();
	
	graphx = 30;
	graphy = 250;

	// Set the axis and the labels for the graph
	x = new Axis(Axis::x, Point(graphx,graphy), 300, 6, "Time (10 samples per tick)");
	x->label.move(0, 0);
	z = new Axis(Axis::y, Point(graphx,graphy), 200, 10, "Throttle Position (%)");
	z->label.move(0, 0);

	graphTitle = new Text(Point(graphx + 50, 100), "Historical Throttle Position Gauge");
	graphTitle->set_color(Color::blue);

	graphPlotName = new Text(Point(graphx + 250, 200), "Throttle Position Data");
	graphPlotName->set_color(Color::red);

	
	tpLabel00 = new Text(Point(graphx - 10, graphy + 5), "0");
	tpLabel01 = new Text(Point(graphx - 18, graphy + 5 - 20*1), "10");
	tpLabel02 = new Text(Point(graphx - 18, graphy + 5 - 20*2), "20");
	tpLabel03 = new Text(Point(graphx - 18, graphy + 5 - 20*3), "30");
	tpLabel04 = new Text(Point(graphx - 18, graphy + 5 - 20*4), "40");
	tpLabel05 = new Text(Point(graphx - 18, graphy + 5 - 20*5), "50");
	tpLabel06 = new Text(Point(graphx - 18, graphy + 5 - 20*6), "60");
	tpLabel07 = new Text(Point(graphx - 18, graphy + 5 - 20*7), "70");
	tpLabel08 = new Text(Point(graphx - 18, graphy + 5 - 20*8), "80");
	tpLabel09 = new Text(Point(graphx - 18, graphy + 5 - 20*9), "90");
	tpLabel10 = new Text(Point(graphx - 25, graphy + 5 - 20*10), "100");
	
	

		
}


//pre: none
//post: data will be updated and stored into the list data
//modified from update from assignment 2
void UpperGraph::update(int newData){
	
	data.insert(newData);

}

//pre: none
//post: return data
MyList UpperGraph::getData(){
	return data;
}


UpperGraph::~UpperGraph()
{
	data.~MyList();

}


	

void UpperGraph::display(Window& screen) {

	// Use a open polyline to store the graph values
	tp_record = new Open_polyline;
	

	// Cycle through list values and plot graph
	int max = data.getTotal();
	for (int i = max; i > 0; i--) {
		tp_record->add(Point(graphx+300-i*5, graphy - data.getInt(i)*2));
	}

	tp_record->set_color(Color::red);
	
	

	//Attach everything to screen
	screen.attach(*x);
	screen.attach(*z);
	screen.attach(*tp_record);
	screen.attach(*graphTitle);
	screen.attach(*graphPlotName);

	
	screen.attach(*tpLabel00);
	screen.attach(*tpLabel01);
	screen.attach(*tpLabel02);
	screen.attach(*tpLabel03);
	screen.attach(*tpLabel04);
	screen.attach(*tpLabel05);
	screen.attach(*tpLabel06);
	screen.attach(*tpLabel07);
	screen.attach(*tpLabel08);
	screen.attach(*tpLabel09);
	screen.attach(*tpLabel10);
	
	screen.redraw();
	Fl::check();
	
}


//Detaches everything form the window given
// Pre: window reference
// Post: none
void UpperGraph::detach(Window& screen) {

	screen.detach(*x);
	screen.detach(*z);
	screen.detach(*tp_record);
	screen.detach(*graphTitle);
	screen.detach(*graphPlotName);

	
	screen.detach(*tpLabel00);
	screen.detach(*tpLabel01);
	screen.detach(*tpLabel02);
	screen.detach(*tpLabel03);
	screen.detach(*tpLabel04);
	screen.detach(*tpLabel05);
	screen.detach(*tpLabel06);
	screen.detach(*tpLabel07);
	screen.detach(*tpLabel08);
	screen.detach(*tpLabel09);
	screen.detach(*tpLabel10);
	

	delete tp_record;
	tp_record = NULL;


	
}