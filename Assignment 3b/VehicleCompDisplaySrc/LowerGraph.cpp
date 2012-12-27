#include "LowerGraph.h"


LowerGraph::LowerGraph(int a, int b) : UpperGraph(a)
{
	data2 = MyLinkedList(b);
}


//pre: none
//post: an instance variable will be updated depending on the type and the corresponding formula the parameter indicates 
void LowerGraph::update(string newData){
	string type = "";
	type = newData[2] + newData[3];	

	if(type == "0C"){
		int a = hexConverter( newData[4],  newData[5]);
		int b = hexConverter( newData[6],  newData[7]);
		getData().insert(((a*256)+b)/4);
	}

	else if(type == "0D")
		data2.insert(hexConverter( newData[4],  newData[5]));
	
}

LowerGraph::~LowerGraph(void)
{
	data2.~MyLinkedList();
}
