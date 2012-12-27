


//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 22th, 2010


#pragma once
#include "MyList.h"
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <string>

#include "DisplaySleep.h"

using namespace std;

// Invariant: Base class that contains a graph and one line plot
class UpperGraph
{
public:
	
	//Constructor that specifies the number of slots
	UpperGraph(int slots);


	//pre: none
	//post: data will be updated and stored into the list data
	//modified from update from assignment 2
	virtual void update(int newData);
	

	//pre: window reference
	//post: displays window with graph
	virtual void display(Window& screen);

	//pre: window reference
	//post: detaches everything from the window
	virtual void detach(Window& screen);


	//pre: none
	//post: return data
	MyList getData();
	
	virtual ~UpperGraph(void);

	//-----------------------------------
	MyList data;
	Axis *x;
	Axis *z;
	Text *graphTitle;
	Text *graphPlotName;

	Open_polyline *tp_record;
	
	int graphx, graphy;

	
	Text *tpLabel00;
	Text *tpLabel01;
	Text *tpLabel02;
	Text *tpLabel03;
	Text *tpLabel04;
	Text *tpLabel05;
	Text *tpLabel06;
	Text *tpLabel07;
	Text *tpLabel08;
	Text *tpLabel09;
	Text *tpLabel10;

};

