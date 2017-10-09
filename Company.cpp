///////////////////////////////////////////////////////////
//  Company.cpp
//  Implementation of the Class Company
//  Created on:      31-mar-2016 13:15:01
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Company.h"


Company::Company(const string& name, const string& address ) :
 address_(address),
 name_(name),
 ratedValue_(0)
{

}



Company::~Company(){

}





const string& Company::getAddress(){

	return address_;
}


const string& Company::getName(){

	return name_;
}



string Company::toString()
{
	return name_ + "  " + address_;
}

void Company::clearRatedValue()
{
	ratedValue_ = 0;
}

void Company::addRatedValue(int ratedValue)
{
	ratedValue_ += ratedValue;
}

int Company::getRatedValue()
{
	return ratedValue_;
}
