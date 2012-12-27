#pragma once
#include "MyLinkedList.h"
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <string>

#include "DisplaySleep.h"

using namespace std;
class UpperGraph
{
	MyLinkedList data;
	//the graph, and 2 axises


	Axis *x;
	Axis *z;
	Text *graphTitle;
	Text *graphPlotName;

	Open_polyline *tp_record;
	
	int display_points [60];
	int graphx, graphy;

	/*
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
	*/



public:
	//the following 3 methods are from assignment 2 for the purpose of being used internally

	//translate a single digit hex number into a decimal number
	int hexTranslator(char num);

	//convert a 2 digits hex number into a decimal number
	int hexConverter(char left, char right);

	
	UpperGraph(int slots);


	//pre: none
	//post: data will be updated and stored into the list data
	//modified from update from assignment 2
	virtual void update(int newData);

	
	virtual void display(Window& screen);

	virtual void detach(Window& screen);

	//pre: none
	//post: return data
	MyLinkedList getData();
	//and 3 more get method



	

	virtual ~UpperGraph(void);
};

