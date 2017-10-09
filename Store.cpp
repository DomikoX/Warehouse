///////////////////////////////////////////////////////////
//  Store.cpp
//  Implementation of the Class Store
//  Created on:      31-mar-2016 13:15:04
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Store.h"


Store::Store(const string& address, int zone):
address_(address),
zone_(zone)
{

}



Store::~Store(){

}


const string& Store::getAddress(){

	return address_;
}


int Store::getZone(){

	return zone_;
}



string Store::toString()
{
	return address_ + "  " + to_string(zone_) + "th zone";
}
