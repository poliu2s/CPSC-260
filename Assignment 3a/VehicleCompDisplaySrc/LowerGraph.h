#pragma once
#include "uppergraph.h"
class LowerGraph :
	public UpperGraph
{
MyLinkedList data2;
//get method for data
//use get methods for one verticle axis and horizontal axis
//declear one verticle axis 

public:
	LowerGraph(int a, int b);
	~LowerGraph(void);

	//pre: none
	//post: an instance variable will be updated depending on the type and the corresponding formula the parameter indicates 
	void update(string newData);
};
