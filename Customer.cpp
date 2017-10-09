///////////////////////////////////////////////////////////
//  Customer.cpp
//  Implementation of the Class Customer
//  Created on:      31-mar-2016 13:15:02
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Customer.h"
#include <iostream>


Customer::Customer(string address, string name):
Company(address,name),
storeList_(new ArrayList<Store*>())
{

}



Customer::~Customer(){

	for (int i = 0;i < storeList_->size();i++) {
		delete (*storeList_)[i];
	}

	delete storeList_;
}





List<Store*>* Customer::getStoreList(){

	return storeList_;
}

void Customer::printStores()
{
	int i = 0;
	cout << "ID   Store \n-------------------------------------------------------------- " << endl;
	for (Store *store : *storeList_) {
		std::cout << to_string(i) + "  " + store->toString();
	}

}


void Customer::setStoreList(List<Store*>* newVal){

	storeList_ = newVal;
}


void Customer::addStore(Store *newStore){
	storeList_->add(newStore);
	
}

int Customer::getStoreCount()
{
	return storeList_->size();
}

Store * Customer::getStore(int index)
{
	return (*storeList_)[index];
}


