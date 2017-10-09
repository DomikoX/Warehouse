///////////////////////////////////////////////////////////
//  Container.cpp
//  Implementation of the Class Container
//  Created on:      31-mar-2016 13:15:01
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Container.h"




Container::Container():
requests_(new PriorityQueue_Heap<Request*>())
{

}


Container::~Container(){
	delete requests_;
}


PriorityQueue<Request*>* Container::getRequests(){

	return requests_;
}



void Container::addRequest(Request * request)
{ 
	requests_->push(- request->getStore()->getZone(), request);
}

Request * Container::unloadOneRequest()
{
	Request *pom = requests_->pop();
	pom->setRealized(true);
	return  pom;
}

bool Container::isEmpty()
{
	return requests_->isEmpty();
}
