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

	Open_polyline *tp_record;
	
	int display_points [60];


	int graphx, graphy;



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

