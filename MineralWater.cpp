///////////////////////////////////////////////////////////
//  MineralWater.cpp
//  Implementation of the Class MineralWater
//  Created on:      31-mar-2016 13:29:26
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "MineralWater.h"


MineralWater::MineralWater(int ean, const string& name, Supplier* supplier) :
ean_(ean),
name_(name),
supplier_(supplier)
{

}



MineralWater::~MineralWater(){

}





int MineralWater::getEAN(){

	return ean_;
}


const string& MineralWater::getName(){

	return name_;
}


Supplier* MineralWater::getSupplier(){

	return supplier_;
}


string MineralWater::toString()
{
	return to_string(ean_) + "  " + name_ + " Supp:" + supplier_->toString();
}
