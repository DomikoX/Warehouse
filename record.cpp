///////////////////////////////////////////////////////////
//  record.cpp
//  Implementation of the Class record
//  Created on:      31-mar-2016 13:15:03
//  Original author: Doxisko
///////////////////////////////////////////////////////////


#include "record.h"



Record::Record(MineralWater * minWat, int quantity):
mineralWater_(minWat),
quantity_(quantity)
{

}



Record::~Record(){
	
}






MineralWater * Record::getMinWat(){

	return mineralWater_;
}


int Record::getQuantity(){

	return quantity_;
}







void Record::setQuantity(int newVal){

	quantity_ = newVal;
}



string Record::toString()
{
	
	return   mineralWater_->toString() + "   "  + to_string(quantity_) + "pcs " ;
}
