///////////////////////////////////////////////////////////
//  Customer.h
//  Implementation of the Class Customer
//  Created on:      31-mar-2016 13:15:01
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_7935DC3E_C837_414f_8802_655B23955C36__INCLUDED_)
#define EA_7935DC3E_C837_414f_8802_655B23955C36__INCLUDED_

#include "Company.h"
#include "Store.h"
#include "Structures\List.h"
#include "Structures\ArrayList.h"
using namespace DS;

class Customer : public Company
{

public:
	Customer(string address, string name);
	~Customer();
	
	List<Store*>* getStoreList();
	void printStores();
	void setStoreList(List<Store*>* newVal);
	void addStore(Store *newStore);
	int getStoreCount();
	Store* getStore(int index);
	
private:
	List<Store*> *storeList_;
	

};
#endif // !defined(EA_7935DC3E_C837_414f_8802_655B23955C36__INCLUDED_)
