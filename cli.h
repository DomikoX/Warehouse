#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Warehouse.h"




class MenuI;
class Cli
{

	using mFcion = void(Cli::*)();
public:
	
	Cli(Warehouse* target);
	~Cli();

	void testMethods();
	void printMenu();
	void run();
	void initializeMenu();
	int getInteger(int from, int to);
	string getString();
	time_t getDate();
	string formatDate(time_t date);

	void endFcion();
	void addNewCustomer();
	void addNewStore();
	void addNewSupplier();
	void addNewSupply();
	void addNewMineralWater();
	void addNewRequest();
	void checkRequests();
	void prepareContainer();
	void printMinWaterResources();

	void printRequests();
	void printUnreaalizableRequest();
	void printRecords(List<Record*> *records);
	void printSuppliers();
	void printCustomers();
	void printStores(Customer *cust);
	void printMineralWaters();

	void findBestSupplier();

	void findBestCustomerByMinWat();
	void findBEstCustomerBySupp();



private:
	class MItem {
	public: 
		MItem(string &text, mFcion fcion);
		string& toString();
		void run(Cli *owner);
	private:
		string text_;
		mFcion fcion_;

	};

	ArrayList<MItem> menu_;
	Warehouse *target_;
	

};







