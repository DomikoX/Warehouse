///////////////////////////////////////////////////////////
//  Container.h
//  Implementation of the Class Container
//  Created on:      31-mar-2016 13:15:01
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_EE1D58C0_4333_4e31_A381_4191BCE9D6B9__INCLUDED_)
#define EA_EE1D58C0_4333_4e31_A381_4191BCE9D6B9__INCLUDED_

#include "Request.h"
#include "Structures\PriorityQueue.h"
#include "Structures\PriorityQueue_Heap.h"
using namespace DS;

class Container
{

public:
	
	Container();
	 ~Container();
	
	PriorityQueue<Request*>* getRequests();
	void addRequest(Request * request);
	Request * unloadOneRequest();
	bool isEmpty();


private:
	PriorityQueue<Request*> *requests_;

};
#endif // !defined(EA_EE1D58C0_4333_4e31_A381_4191BCE9D6B9__INCLUDED_)
