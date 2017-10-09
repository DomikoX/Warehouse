///////////////////////////////////////////////////////////
//  Warehouse.cpp
//  Implementation of the Class Warehouse
//  Created on:      31-mar-2016 13:15:05
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Warehouse.h"

#include <iostream>
#include <algorithm>


bool equalFc(const Record& a, const Record& b) {
	return (&a) == &b;
}

int sortRecordFc(Record* const &a, Record* const& b) {
	string at = a->getMinWat()->getSupplier()->toString() + ""+a->getMinWat()->getName();
	string bt = b->getMinWat()->getSupplier()->toString() + ""+b->getMinWat()->getName();
	
	return at.compare(bt);
}
int sortSupplyFc(Supply * const& a, Supply * const& b) {
	const auto diff = difftime(a->getDate(), b->getDate());
	if (a == b) return 0;
	return a < b ? -1 : 1;
}
int sortSupplierFc(Supplier * const&a, Supplier *const& b) {
	if (a->getRatedValue() == b->getRatedValue()) return 0;
	return a->getRatedValue() < b->getRatedValue() ? 1 : -1;

}
int sortCustomerFc(Customer * const&a, Customer *const& b) {
	if (a->getRatedValue() == b->getRatedValue()) return 0;
	return a->getRatedValue() < b->getRatedValue() ? 1 : -1;

}



Warehouse::Warehouse() :
	customers_(new ArrayList<Customer *>()),
	requests_(new LinkedList<Request *>()),
	supplies_(new ArrayListSorted<Supply *>(sortSupplyFc)),
	mineralWater_(new ArrayList<MineralWater *>()),
	suppliers_(new ArrayList<Supplier *>())

{

}



Warehouse::~Warehouse(){


	for (int i = 0;i < requests_->size();i++) {
		delete (*requests_)[i];
	}
	delete requests_;

	for (int i = 0;i < supplies_->size();i++) {
		delete (*supplies_)[i];
	}
	delete supplies_;


	for (int i = 0;i < customers_->size();i++) {
		delete (*customers_)[i];
	}
	delete customers_;


	for (int i = 0;i < mineralWater_->size();i++) {
		delete (*mineralWater_)[i];
	}
	delete mineralWater_;

	for (int i = 0;i <suppliers_->size();i++) {
		delete (*suppliers_)[i];
	}
	delete suppliers_;
}

void Warehouse::testInitialize()
{
	
	tm *pomDate = new tm();
	

	pomDate->tm_mday = 14;
	pomDate->tm_mon = 4-1;
	pomDate->tm_year = 2016 - 1900;
	pomDate->tm_hour = 2;
	requests_->add(new Request((*customers_)[3]->getStore(0), mktime(pomDate)));
	(*requests_)[0]->addRecord(new Record((*mineralWater_)[2], 28));
	(*requests_)[0]->addRecord(new Record((*mineralWater_)[0], 146));
	(*requests_)[0]->addRecord(new Record((*mineralWater_)[3], 86));
	(*requests_)[0]->addRecord(new Record((*mineralWater_)[1], 54));

	pomDate->tm_mday = 14;
	pomDate->tm_mon = 4 -1;
	pomDate->tm_year = 2016 - 1900;
	pomDate->tm_hour = 2;
	requests_->add(new Request((*customers_)[0]->getStore(1), mktime(pomDate)));
	(*requests_)[1]->addRecord(new Record((*mineralWater_)[0], 156));
	(*requests_)[1]->addRecord(new Record((*mineralWater_)[3], 146));
	(*requests_)[1]->addRecord(new Record((*mineralWater_)[3], 80));
	(*requests_)[1]->addRecord(new Record((*mineralWater_)[1], 15));
	pomDate->tm_mday = 15;
	pomDate->tm_mon = 4 -1;
	pomDate->tm_year = 2016 - 1900;
	pomDate->tm_hour = 2;
	requests_->add(new Request((*customers_)[2]->getStore(0), mktime(pomDate)));

	(*requests_)[2]->addRecord(new Record((*mineralWater_)[0], 40));
	(*requests_)[2]->addRecord(new Record((*mineralWater_)[1], 10));
	(*requests_)[2]->addRecord(new Record((*mineralWater_)[2], 4));
	(*requests_)[2]->addRecord(new Record((*mineralWater_)[3], 89));
	pomDate->tm_mday = 15;
	pomDate->tm_mon = 4 - 1;
	pomDate->tm_year = 2016 - 1900;
	pomDate->tm_hour = 2;
	requests_->add(new Request((*customers_)[1]->getStore(1), mktime(pomDate)));

	(*requests_)[3]->addRecord(new Record((*mineralWater_)[0], 20));
	(*requests_)[3]->addRecord(new Record((*mineralWater_)[1], 10));
	

}





bool Warehouse::addCustomer(Customer *newCustomer){

	customers_->add(newCustomer);
	return true;
}

List<Customer*>* Warehouse::getCustomers()
{
	return customers_;
}



int Warehouse::getCustomerCount()
{
	return customers_->size();
}

Customer * Warehouse::getCustomer(int index)
{
	return (*customers_)[index];
}

Customer * Warehouse::getBestCustomerByMinWat(time_t from, time_t to, MineralWater* minWat)
{
	ArrayListSorted<Customer*> rsa = ArrayListSorted<Customer*>(sortCustomerFc);
	for (Customer *cus : *customers_) {
		cus->clearRatedValue();

		for (Request *req : *requests_) {


			time_t reqTime = req->getDate();
			auto fromDiff = difftime(reqTime,from);
			auto toDiff = difftime(to,reqTime);
			if (fromDiff < 0 || toDiff < 0) {
				continue;
			}


			for (Record *rec : *req->getRecords()) {
				if (minWat == rec->getMinWat()) {
					cus->addRatedValue(rec->getQuantity());
				}
			}
		}
		rsa.add(cus);
	}

	return rsa.removeAt(0);
}

Customer * Warehouse::getBestCustomerBySupp(time_t from, time_t to, Supplier * supp)
{
	ArrayListSorted<Customer*> rsa = ArrayListSorted<Customer*>(sortCustomerFc);
	for (Customer *cus : *customers_) {
		cus->clearRatedValue();

		for (Request *req : *requests_) {


			time_t reqTime = req->getDate();
			auto fromDiff = difftime(from, reqTime);
			auto toDiff = difftime(reqTime, to);
			if (fromDiff < 0 || toDiff < 0) {
				continue;
			}


			for (Record *rec : *req->getRecords()) {
				if (supp == rec->getMinWat()->getSupplier()) {
					cus->addRatedValue(rec->getQuantity());
				}
			}
		}
		rsa.add(cus);
	}

	return rsa.removeAt(0);
}



bool Warehouse::addMineralWater(MineralWater* newMineralWater){

	mineralWater_->add(newMineralWater);
	return true;
}



List<MineralWater*>* Warehouse::getMineralWaters()
{
	return mineralWater_;
}

int Warehouse::getMineralWaterCount()
{
	return mineralWater_->size();
}

MineralWater * Warehouse::getMineralWater(int index)
{
	return (*mineralWater_)[index];
}


bool Warehouse::addStoreToSupplier(Store *newStore, int index){
	Customer* pom = (*customers_)[index];
	pom->addStore(newStore);
	return true;
}


bool Warehouse::addSupplier(Supplier *newSuppler){
	suppliers_->add(newSuppler);
	return true;
}

int Warehouse::getSuppliersCount()
{
	return suppliers_->size();
}

List<Supplier*>* Warehouse::getSuppliers()
{
	return suppliers_;
}



Supplier * Warehouse::getSupplier(int index)
{
	return (*suppliers_)[index];
}

Supplier * Warehouse::getBestSupplier()
{
	ArrayListSorted<Supplier*> rsa = ArrayListSorted<Supplier*>(sortSupplierFc);
	for (Supplier *sup : *suppliers_) {
		sup->clearRatedValue();
		for (Request *req : *requests_) {
			for (Record *rec : *req->getRecords()) {
				if (sup == rec->getMinWat()->getSupplier()) {
					sup->addRatedValue(rec->getQuantity());
				}
			}
		}
		rsa.add(sup);
	}
		
	return rsa.removeAt(0);
}

int Warehouse::addSupply(Supply *newSupply){
	supplies_->add(newSupply);
	return 0;
}

List<Record*>* Warehouse::getActualSupply()
{

	ArrayListSorted<Record*> *actualSupply = new  ArrayListSorted<Record*>(sortRecordFc);


	// zisti aktuálne množstvá vôd na sklade
	for (MineralWater *min : *mineralWater_)
	{
		Record *pom = new Record(min, 0);
		for (Supply *supp : *supplies_) {
			if (min == supp->getMinWat()) {
				int oldQaun = pom->getQuantity();
				pom->setQuantity(oldQaun + supp->getRest());
			}
		}

		actualSupply->add(pom);

	}
	
	return actualSupply;
}


List<Record*> * Warehouse::checkRequests(){


	
	List<Record*> *actualSupply = getActualSupply();

	// odrata z aktualnych mnoztiev na sklade tie ktoré požadujú zákazníci
	for (Request *req : *requests_) {
		if (req->isRealized() != 0) {
			continue;
		}

		for (Record *rec : *(req->getRecords())) {
				for (int i = 0;i < actualSupply->size();i++) {
					
				if ((*actualSupply)[i]->getMinWat() == rec->getMinWat()) {
					int oldQaun = (*actualSupply)[i]->getQuantity();
					(*actualSupply)[i]->setQuantity(oldQaun - rec->getQuantity());
					
				}
			}
		}
	}

	// nechá len vody ktorých je nedostatok
	
	for (int i = 0;i < actualSupply->size();i++) {
		if ((*actualSupply)[i]->getQuantity() >= 0) {
			delete actualSupply->removeAt(i);
			i--;
		}
	}
	return actualSupply;

	
	
}




bool Warehouse::addRequest(Request * newRequest)
{
	requests_->add(newRequest);
	return true;
}

List<Request*>* Warehouse::getRequests()
{
	return  requests_;
}






Container * Warehouse::prepareContainer()
{
	findTommorowUnrealizable();

	Container *cont = new Container();

	for (Request *req : *requests_) {
		const auto diff = difftime(req->getDate(), time(0));
		//ešte nezrealizovanie a len 
		if (req->isRealized() != 0 || (diff / (60 * 60 * 24)) > 1) {
			continue;
		}
		
		for (Record *rec : *(req->getRecords())) {
			int neededCount = rec->getQuantity();
			for (Supply *supp : *supplies_) {
				if (neededCount == 0) {
					break;
				}
				//hladam vodu pozadovaneho typu
				if (rec->getMinWat() == supp->getMinWat()) {
					int suppQ = supp->getRest();
					if (neededCount > suppQ) {
						neededCount -= suppQ;
						//v supply všetky vody vyberieme 
						supp->subRest(suppQ);
					}
					else {
						supp->subRest(neededCount);
						neededCount = 0;
					}
					

				}
			}
			
		}
		cont->addRequest(req);
	}

	return cont;

}

void Warehouse::printUnrealize()
{	
	for (Request *pom : *requests_) {
		if (pom->isRealized() < 0) {
			cout << pom->toString() << endl;
		}
	}
}



void Warehouse::findTommorowUnrealizable()
{

	time_t now = time(0);

	for (Request *req : *requests_) {
		const auto diff = difftime(req->getDate(), now);
		//ešte nezrealizovanie a len ktore maju by zajtra
		if (req->isRealized() != 0 || (diff / (60 * 60 * 24)) > 1) {
			continue;
		}
		if (req->isRealized() != 0 || (diff / (60 * 60 * 24)) < 0) {
			// nastavi na zmeškane
			req->setMissed();
			continue;
		}

		for (Record *rec : *(req->getRecords())) {
			int neededCount = rec->getQuantity();
			for (Supply *supp : *supplies_) {
				if (neededCount <= 0) {
					break;
				}
				if (rec->getMinWat() == supp->getMinWat()) {
						neededCount -= supp->getRest();
				}
			}
			if (neededCount > 0) {
				req->setRealized(false);
			}
		}
	}
}

void Warehouse::saveToFile()
{
	ofstream file;
	file.open("warehouse.txt");

	// print  Suppliers
	file << to_string(suppliers_->size()) + "\n";
	for (auto pom : *suppliers_) {
		string name = pom->getName();
		replace(name.begin(), name.end(), ' ', '_');

		string address = pom->getAddress();
		replace(address.begin(), address.end(), ' ', '_');

		file << name + " " + address + "\n";
	}

	// print Mineral Waters
	file << to_string(mineralWater_->size()) + "\n";
	for (auto pom : *mineralWater_) {

		string name = pom->getName();
		replace(name.begin(), name.end(), ' ', '_');


		file << to_string(pom->getEAN()) + " " + name + " " + to_string(suppliers_->getIndexOf(pom->getSupplier())) + "\n";
	}

	// print Customer
	file << to_string(customers_->size()) + "\n";
	for (auto pom : *customers_) {


		string name = pom->getName();
		replace(name.begin(), name.end(), ' ', '_');

		string address = pom->getAddress();
		replace(address.begin(), address.end(), ' ', '_');

		file << name + " " + address + "\n";

		// print customers stores
		file << to_string(pom->getStoreList()->size()) + "\n";
		for (auto sto : *pom->getStoreList()) {

			

			string address = sto->getAddress();
			replace(address.begin(), address.end(), ' ', '_');

			file << address + " " + to_string(sto->getZone()) + "\n";
		}

	}
	 
	// print supplies
	file << to_string(supplies_->size()) + "\n";
	for (auto pom : *supplies_) {
		file << to_string(pom->getQuantity()) + " " + to_string(pom->getRest()) + " " + to_string(mineralWater_->getIndexOf(pom->getMinWat())) + " " +  to_string(pom->getDate())  +"\n";
	}


	ArrayList<Store *> stores = ArrayList<Store *>();
	for (auto pom : *customers_) {
		for (auto sto : *pom->getStoreList()) {
			stores.add(sto);
		}
	}

	// print requests
	file << to_string(requests_->size()) + "\n";
	for (auto pom : *requests_) {
		file << to_string(pom->isRealized())  + " " + to_string(pom->getDate()) +  " " + to_string(stores.getIndexOf(pom->getStore())) + "\n";

		// print records
		file << to_string(pom->getRecords()->size()) + "\n";
		for (auto rec : *pom->getRecords()) {
			file << to_string(rec->getQuantity())+ " " + to_string(mineralWater_->getIndexOf(rec->getMinWat()))+  "\n";
		}


	}


	file.close();
}

void Warehouse::InitializeFromFile()
{
	customers_->clear();
	requests_->clear();
	supplies_->clear();
	mineralWater_->clear();
	suppliers_->clear();


	ifstream file;
	file.open("warehouse.txt");

	// read  suppliers
	int count;
	file >> count;
	file.ignore();
	for (int i = 0; i < count;i++) {
		string name;
		file >> name;
		string address;
		file >> address;

		replace(name.begin(), name.end(), '_', ' ');
		replace(address.begin(), address.end(), '_', ' ');
		suppliers_->add(new Supplier(name, address));
	
	}

	// read Mineral Waters
	file >> count;
	file.ignore();
	for (int i = 0; i < count;i++) {
		int ean;
		file >> ean;
		string name;
		file >> name;
		int supp;
		file >> supp;
		
		replace(name.begin(), name.end(), '_', ' ');

		mineralWater_->add(new MineralWater(ean, name, (*suppliers_)[supp]));

	}


	// read customers
	file >> count;
	file.ignore();
	for (int i = 0; i < count;i++) {
		string name;
		file >> name;
		string address;
		file >> address;

		replace(name.begin(), name.end(), '_', ' ');
		replace(address.begin(), address.end(), '_', ' ');
		customers_->add(new Customer(name, address));

		//read customers stores 
		int count2;
		file >> count2;
		file.ignore();
		for (int j = 0; j < count2;j++) {
			string address2;
			file >> address2;
			int zone;
			file >> zone;

			replace(address2.begin(), address2.end(), '_', ' ');

			(*customers_)[i]->addStore(new Store(address2, zone));

		}

	}


	// read supplies
	file >> count;
	file.ignore();
	for (int i = 0; i < count;i++) {
		int quantity;
		file >> quantity;
		int rest;
		file >> rest;
		int minWater;
		file >> minWater;
		int date;
		file >> date;

		supplies_->add(new Supply(date, (*mineralWater_)[minWater], quantity, rest));

	}



	ArrayList<Store *> stores = ArrayList<Store *>();
	for (auto pom : *customers_) {
		for (auto sto : *pom->getStoreList()) {
			stores.add(sto);
		}
	}

	// read requests
	file >> count;
	file.ignore();
	for (int i = 0; i < count;i++) {
		int realized;
		file >> realized;
		int date;
		file >> date;
		int store;
		file >> store;
		requests_->add(new Request(stores[store], date,realized));

		// read requests records
		int count2;
		file >> count2;
		for (int j = 0; j < count2;j++) {
			int  quantity;
			file >> quantity;
			int minWat;
			file >> minWat;
			(*requests_)[i]->addRecord(new Record((*mineralWater_)[minWat], quantity));
		}


	}



	file.close();
}



