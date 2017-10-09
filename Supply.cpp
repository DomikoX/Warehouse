///////////////////////////////////////////////////////////
//  Supply.cpp
//  Implementation of the Class Supply
//  Created on:      31-mar-2016 13:15:05
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Supply.h"


Supply::Supply(time_t date, MineralWater* ean, int quantity):
	date_(date),
	mineralWater_(ean),
	quantity_(quantity),
	rest_(quantity)
{

}



Supply::Supply(time_t date, MineralWater * ean, int quantity, int rest):
	date_(date),
	mineralWater_(ean),
	quantity_(quantity),
	rest_(rest)
{
}

Supply::~Supply(){

}





time_t Supply::getDate(){

	return date_;
}


MineralWater* Supply::getMinWat(){

	return mineralWater_;
}


int Supply::getQuantity(){

	return quantity_;
}

int Supply::getRest()
{
	return rest_;
}







void Supply::subRest(int count)
{
	if (rest_ < count) {
		throw exception("No enaught rest");
		return;
	}
	rest_ -= count;
}




string Supply::toString()
{
	return mineralWater_->toString() + " " + to_string(quantity_) + "pcs "  + ctime(&date_);
}


