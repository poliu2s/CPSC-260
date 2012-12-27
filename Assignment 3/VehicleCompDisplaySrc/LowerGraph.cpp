

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 22th, 2010

#include "LowerGraph.h"
#include "MyList.h"
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <string>

// Invariant: a derived class from uppergraph that displays two plots on the same graph
// that are color coded
LowerGraph::LowerGraph(int a, int b) : UpperGraph(a)
{
	data2 = MyList();


	graphx = 30;
	graphy = 600;
	

	//Set up the graph for Vehicle speed data
	x = new Axis(Axis::x, Point(graphx,graphy), 300, 6, "Time (10 samples per tick)");
	z = new Axis(Axis::y, Point(graphx,graphy), 200, 10, "Speed (km/h) ");
	z->set_color(Color::dark_blue);

	graphTitle = new Text(Point(graphx + 50, graphy-180), "Historical EngineRPM and Speed");
	graphTitle->set_color(Color::blue);

	graphPlotName = new Text(Point(graphx + 200, graphy-70), "Vehicle Speed");
	graphPlotName->set_color(Color::dark_blue);

	
	tpLabel00 = new Text(Point(graphx - 20, graphy + 5), "0");
	tpLabel01 = new Text(Point(graphx - 20, graphy + 5 - 20*1), "10");
	tpLabel02 = new Text(Point(graphx - 20, graphy + 5 - 20*2), "20");
	tpLabel03 = new Text(Point(graphx - 20, graphy + 5 - 20*3), "30");
	tpLabel04 = new Text(Point(graphx - 20, graphy + 5 - 20*4), "40");
	tpLabel05 = new Text(Point(graphx - 20, graphy + 5 - 20*5), "50");
	tpLabel06 = new Text(Point(graphx - 20, graphy + 5 - 20*6), "60");
	tpLabel07 = new Text(Point(graphx - 20, graphy + 5 - 20*7), "70");
	tpLabel08 = new Text(Point(graphx - 20, graphy + 5 - 20*8), "80");
	tpLabel09 = new Text(Point(graphx - 20, graphy + 5 - 20*9), "90");
	tpLabel10 = new Text(Point(graphx - 30, graphy + 5 - 20*10), "100");


	// Set up graph for Engine RPM data ------------------------------


	z2 = new Axis(Axis::y, Point(graphx +300,graphy), 200, 10, "Rev per min (rpm) ");
	z2->set_color(Color::dark_magenta);
	

	graphPlotName2 = new Text(Point(graphx + 160, graphy-120), "Engine RPM");
	graphPlotName2->set_color(Color::dark_magenta);

	
	tp2Label00 = new Text(Point(graphx + 320, graphy + 5), "0");
	tp2Label01 = new Text(Point(graphx + 320, graphy + 5 - 20*1), "300");
	tp2Label02 = new Text(Point(graphx + 320, graphy + 5 - 20*2), "600");
	tp2Label03 = new Text(Point(graphx + 320, graphy + 5 - 20*3), "900");
	tp2Label04 = new Text(Point(graphx + 320, graphy + 5 - 20*4), "1200");
	tp2Label05 = new Text(Point(graphx + 320, graphy + 5 - 20*5), "1500");
	tp2Label06 = new Text(Point(graphx + 320, graphy + 5 - 20*6), "1800");
	tp2Label07 = new Text(Point(graphx + 320, graphy + 5 - 20*7), "2100");
	tp2Label08 = new Text(Point(graphx + 320, graphy + 5 - 20*8), "2400");
	tp2Label09 = new Text(Point(graphx + 320, graphy + 5 - 20*9), "2700");
	tp2Label10 = new Text(Point(graphx + 320, graphy + 5 - 20*10), "3000");



}


//pre: none
//post: an instance variable will be updated depending on the type and the corresponding formula the parameter indicates 
void LowerGraph::update(int newRPM, int newVS){
	
	data.insert(newRPM);
	data2.insert(newVS);
			
}

LowerGraph::~LowerGraph(void)
{
	data2.~MyList();
}


// Takes a reference to a window and displays both of the plots in the graph
// pre: window reference
// post: none
void LowerGraph::display(Window& screen) {

	
	tp_record = new Open_polyline;
	tp2_record = new Open_polyline;
	
	int max = data2.getTotal();
	for (int i = max; i > 0 ; i--) {
		tp_record->add(Point(graphx+300-i*5, graphy - data2.getInt(i)*2));
	}

	tp_record->set_color(Color::dark_blue);

	max = data.getTotal();
	for (int i = max; i > 0; i--) {
		tp2_record->add(Point(graphx+300-i*5, graphy - data.getInt(i)/15));
	}
	
	tp2_record->set_color(Color::dark_magenta);



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


	screen.attach(*tp2_record);
	screen.attach(*graphPlotName2);
	screen.attach(*z2);

	screen.attach(*tp2Label00);
	screen.attach(*tp2Label01);
	screen.attach(*tp2Label02);
	screen.attach(*tp2Label03);
	screen.attach(*tp2Label04);
	screen.attach(*tp2Label05);
	screen.attach(*tp2Label06);
	screen.attach(*tp2Label07);
	screen.attach(*tp2Label08);
	screen.attach(*tp2Label09);
	screen.attach(*tp2Label10);
	
	screen.redraw();
	Fl::check();
	

}

// Detaches everything from window
// Pre: window reference
// Post: none
void LowerGraph::detach(Window& screen) {

	//Detach everything from the screen and delete objects to prevent memory loss

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


	screen.detach(*tp2_record);
	screen.detach(*graphPlotName2);
	screen.detach(*z2);

	screen.detach(*tp2Label00);
	screen.detach(*tp2Label01);
	screen.detach(*tp2Label02);
	screen.detach(*tp2Label03);
	screen.detach(*tp2Label04);
	screen.detach(*tp2Label05);
	screen.detach(*tp2Label06);
	screen.detach(*tp2Label07);
	screen.detach(*tp2Label08);
	screen.detach(*tp2Label09);
	screen.detach(*tp2Label10);
	

	delete tp_record;
	delete tp2_record;
	tp_record = NULL;
	tp2_record = NULL;


	
}
