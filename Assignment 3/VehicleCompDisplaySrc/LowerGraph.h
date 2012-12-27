

//Po Liu,13623079,x2f7
//Hao Ran Wu,26620096,y0f7
//last updated: Jul 22th, 2010

#pragma once
#include "UpperGraph.h"
#include "MyList.h"


// Invariant: a derived class from uppergraph that displays two plots on the same graph
// that are color coded
class LowerGraph : public UpperGraph
{

public:
	LowerGraph(int a, int b);
	~LowerGraph(void);

	//pre: none
	//post: an instance variable will be updated depending on the type and the corresponding formula the parameter indicates 
	void update(int newRPM, int newVS);

	
	//pre: window reference
	//post: displays window with graphs
	void display(Window& screen);


	//pre: window reference
	//post: detaches everything from the window
	void detach(Window& screen);

	//-------------------------

	MyList data2;
	Axis *z2;
	Text *graphPlotName2;

	Open_polyline *tp2_record;
	
	
	Text *tp2Label00;
	Text *tp2Label01;
	Text *tp2Label02;
	Text *tp2Label03;
	Text *tp2Label04;
	Text *tp2Label05;
	Text *tp2Label06;
	Text *tp2Label07;
	Text *tp2Label08;
	Text *tp2Label09;
	Text *tp2Label10;
};
