///////////////////////////////////////////////////////////
//  Warehouse.h
//  Implementation of the Class Warehouse
//  Created on:      31-mar-2016 13:15:05
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_9A4FF717_6700_4275_ABED_5ECF54AD0FDF__INCLUDED_)
#define EA_9A4FF717_6700_4275_ABED_5ECF54AD0FDF__INCLUDED_

#include "Customer.h"
#include "MineralWater.h"
#include "Supplier.h"
#include "Supply.h"
#include "Request.h"
#include "Container.h"

#include "Structures\LinkedList.h"
#include "ArrayListSorted.h"

#include <fstream>


class Warehouse
{

public:
	Warehouse();
	 ~Warehouse();
	void testInitialize();
	
	bool addCustomer(Customer *newCustomer);
	List<Customer *>* getCustomers();
	int getCustomerCount();
	Customer* getCustomer(int index);
	Customer* getBestCustomerByMinWat(time_t from , time_t to, MineralWater* minWat);
	Customer* getBestCustomerBySupp(time_t from, time_t to, Supplier *supp);

	bool addMineralWater(MineralWater *newMineralWater);
	List<MineralWater *>* getMineralWaters();
	int getMineralWaterCount();
	MineralWater* getMineralWater(int index);



	bool addStoreToSupplier(Store *newStore, int customerIndex);

	bool addSupplier(Supplier *newSuppler);
	int getSuppliersCount();
	List<Supplier*>* getSuppliers();
	Supplier* getSupplier(int index);
	Supplier *getBestSupplier();


	int addSupply(Supply *newSupply);

	List<Record*>* getActualSupply();

	List<Record*> * checkRequests();
	bool addRequest( Request *newRequest);
	List<Request *>* getRequests();
	

	Container * prepareContainer();
	void printUnrealize();


	void saveToFile();
	void InitializeFromFile();
private:
	void findTommorowUnrealizable();
	
	List<Customer*> *customers_;
	List<Request*> *requests_;
	ArrayList<Supply*> *supplies_;
	List<Supplier*> *suppliers_;
	List<MineralWater*> *mineralWater_;
	

};
#endif // !defined(EA_9A4FF717_6700_4275_ABED_5ECF54AD0FDF__INCLUDED_)
