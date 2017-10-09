///////////////////////////////////////////////////////////
//  Supplier.cpp
//  Implementation of the Class Supplier
//  Created on:      31-mar-2016 13:15:04
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Supplier.h"


Supplier::Supplier(string name, string address):
Company(name,address){

}

Supplier::Supplier(Supplier * other) :
	Company(other->getName(), other->getAddress())
{
}



Supplier::~Supplier(){

}