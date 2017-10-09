#include "cli.h"
#include <ctime>
#include <climits>
#include <iomanip>
//#include "Windows.h"



Cli::Cli(Warehouse* target) :
	target_(target),
	menu_(ArrayList<MItem>(18,nullptr))
{

	menu_.add(MItem(string("Exit"), &Cli::endFcion));
	menu_.add(MItem(string("Add new Customer"), &Cli::addNewCustomer));
	menu_.add(MItem(string("Add new Store"), &Cli::addNewStore));
	menu_.add(MItem(string("Add new Mineral Water"), &Cli::addNewMineralWater));
	menu_.add(MItem(string("Add new Request"), &Cli::addNewRequest));
	menu_.add(MItem(string("Add new Supplier"), &Cli::addNewSupplier));
	menu_.add(MItem(string("Add new Supply"), &Cli::addNewSupply));
	menu_.add(MItem(string("Show all Customers"), &Cli::printCustomers));
	menu_.add(MItem(string("Show all Mineral Waters"), &Cli::printMineralWaters));
	menu_.add(MItem(string("Show Mineral Water Resources"), &Cli::printMinWaterResources));
	menu_.add(MItem(string("Show all Requests"), &Cli::printRequests));
	menu_.add(MItem(string("Show Unrealizable Requests"), &Cli::printUnreaalizableRequest));

	menu_.add(MItem(string("Show all Suppliers"), &Cli::printSuppliers));

	menu_.add(MItem(string("Check requests"), &Cli::checkRequests));
	menu_.add(MItem(string("Prepare container"), &Cli::prepareContainer));
	menu_.add(MItem(string("Get the Best Supplier"), &Cli::findBestSupplier));

	menu_.add(MItem(string("Get the Best Customer by Mineral Water"), &Cli::findBestCustomerByMinWat));
	menu_.add(MItem(string("Get the Best Customer by Supplier"), &Cli::findBEstCustomerBySupp));
}


Cli::~Cli()
{
}



void Cli::printMenu()
{
	cout << "******Menu******" << endl;
	int i = 0;
	for (MItem item : menu_) {
		cout << left << setw(5) << to_string(i) << item.toString() << endl;
		i++;
	}
	cout << "Please enter a number:" << endl;
}

void Cli::run()
{
	
	printMenu();
	int result = getInteger(0, menu_.size() - 1);

	system("cls");
	cout << "***********************" << endl
		<< menu_[result].toString() << endl
		<< "***********************" << endl;
	menu_[result].run(this);
	cout << endl;
	if (result != 0) {
		run();
	}
}

int Cli::getInteger(int from, int to)
{
	string pomT = getString();
	int pom;
	try
	{
		pom = stoi(pomT);
		if (pom < from || pom > to) {
			throw exception("Invalid parameter");
		}
	}
	catch (const std::exception&)
	{
		printf("You entered bad Number\n");
		return getInteger(from, to);
	}

		
	
	return pom;

}

string Cli::getString()
{
	//cin.ignore();
	string pom;
	std::getline(std::cin, pom);
	
	return pom;
}

time_t Cli::getDate()
{
	
	string date = getString();

	try {
		tm *pomDate = new tm();
		pomDate->tm_mday = stoi(date.substr(0, 2));
		pomDate->tm_mon = stoi(date.substr(3, 2)) - 1;
		pomDate->tm_year = stoi(date.substr(6, 4)) - 1900;

		pomDate->tm_hour = 2; // because of conversion from time_t to tm
		return mktime(pomDate);
	}
	catch (const std::exception& ano)
	{
		printf("You entered a bad Date!");
		getDate();
	}

   
}

string Cli::formatDate(time_t date)
{
	tm *ltm = gmtime(&date);
	string text = "";
	text += to_string(ltm->tm_mday) + ".";
	text += to_string(1 + ltm->tm_mon) + ".";
	text += to_string(1900 + ltm->tm_year);
	
	return text;
}



void Cli::endFcion()
{
	cout << "Thanks for Using our system please come back again. :)" << endl;
}

void Cli::addNewCustomer()
{
	printf("Enter name of new Customer: \n");
	string name = getString();
	printf("Enter address of new Customer: \n");
	string address = getString();
	
	Customer *pom = new Customer(name,address);
	target_->addCustomer(pom);

	printf("Customer succesfully added\n");
}

void Cli::addNewSupplier()
{
	printf("Enter name of new Supplier: \n");
	string name = getString();
	printf("Enter address of new Supplier: \n");
	string address = getString();

	Supplier *pom = new Supplier(name,address);
	target_->addSupplier(pom);
	printf("Supplier succesfully added\n");
}

void Cli::addNewMineralWater()
{

	printf("Enter name of new Mineral Water\n");
	string name = getString();

	printf("Enter EAN of new Mineral Water\n");
	int ean = getInteger(0, INT_MAX);

	printf("Enter index of Supplier you wanto to add store: \n");
	printSuppliers();
	int index = getInteger(0, target_->getSuppliersCount());

	MineralWater *pom = new MineralWater(ean, name, target_->getSupplier(index));
	target_->addMineralWater(pom);

	printf("Mineral Water  succesfully added\n");
}

void Cli::addNewRequest()
{
	int countOfstores = 0;
	int indexCust = -1;
	while (countOfstores == 0) {
		printf("Enter index of Customer: \n");
		printCustomers();
		indexCust = getInteger(0, target_->getCustomerCount());
		countOfstores = target_->getCustomer(indexCust)->getStoreCount();
		if (countOfstores <= 0) { printf("Sorry choosen customer had no Store, please select another one"); }
	}
	

	printf("Enter index of Store:  \n");

	printStores(target_->getCustomer(indexCust));
	int indexStor = getInteger(0, countOfstores);

	printf("Enter date (DD.MM.YYYY): \n");
	time_t recordDate = getDate();
	time_t now = time(0);


	if ((difftime(recordDate, now) / (60 * 60 * 24)) < 2) {
		printf("Sorry records date is too soon.\n");
		return;
	}

	Request *req = new Request(target_->getCustomer(indexCust)->getStore(indexStor),recordDate);

	int choose = 1;
	while(choose != 0) {
		printf("Enter index of Mineral Water you wanto to add: \n");
		printMineralWaters();
		int indexMinWat = getInteger(0, target_->getMineralWaterCount());

		printf("Enter quantity of mineral water: \n");
		int quantity = getInteger(0, INT_MAX);

		Record* pom = new Record(target_->getMineralWater(indexMinWat), quantity);
		req->addRecord(pom);
		printf("What you want ?\n");
		printf("0 End adding record\n");
		printf("1 Add another record\,");
		choose = getInteger(0, 1);


	}
	
	target_->addRequest(req);
	printf("Request succesfully added\n");

	
}



void Cli::addNewSupply() {
	printf("Enter index of Mineral Water you wanto to get: \n");
	printMineralWaters();
	int indexMinWat = getInteger(0, target_->getMineralWaterCount());


	printf("Enter quantity of mineral water: \n");
	int quantity = getInteger(0, INT_MAX);

	printf("Enter date (DD.MM.YYYY): \n");
	time_t pomDate = getDate();

	Supply *pom = new Supply(pomDate, target_->getMineralWater(indexMinWat), quantity);
	target_->addSupply(pom);
	printf("Supply succesfully added\n");

}

void Cli::addNewStore()
{
	printf("Enter index of customer you wanto to add store: \n");
	printCustomers();

	int index = getInteger(0, target_->getCustomerCount());

	printf("Enter adrres of new store\n");
	string address = getString();

	printf("Enter Zone of store\n");
	int zone = getInteger(0, INT_MAX);
	Store *pom = new Store(address, zone);
	target_->addStoreToSupplier(pom, index);

	printf("Store succesfully added\n");

}


void Cli::checkRequests()
{
	auto actualSupply = target_->checkRequests();

	printf("Chybajuce vody:\n------------------------------------------\n");
	for (Record* pom : *actualSupply) {
		cout << setw(20) <<left << pom->getMinWat()->getSupplier()->getName() << setw(15) << pom->getMinWat()->getName() << setw(25) << to_string(-pom->getQuantity()) + "pcs missing" << endl;
	}
	for (int i = 0;i < actualSupply->size();i++) {
		delete (*actualSupply)[i];
	}
	delete actualSupply;
}

void Cli::prepareContainer()
{
	Container *container = target_->prepareContainer();
	while (!container->isEmpty()) {
		Request *pom =  container->unloadOneRequest();

		

			cout << endl << setw(5) << left << "*** UNLOADING REQUEST***" << endl
				<< setw(20) << pom->getStore()->getAddress()
				<< setw(5) << to_string( pom->getStore()->getZone())
				<< setw(10) << formatDate(pom->getDate())
				<< setw(10) << pom->getRealizedString()
				<< endl;
			printRecords(pom->getRecords());
		
		
	}
	
}


void Cli::printMinWaterResources()
{
	cout << "Actual supply of mineral waters:" << endl << endl;
	List<Record *> *actRecs = target_->getActualSupply();
	printRecords( actRecs);
	
	for (int i = 0;i < actRecs->size();i++) {
		delete (*actRecs)[i];
	}
	delete actRecs;


}

void Cli::printRecords(List<Record*> *resource) {
	
	cout << setw(10) << left << "EAN"
		<< setw(20) << "Supplier"
		<< setw(15) << "Mineral Water"
		<< setw(15) << "Quantity(pcs)"
		<< endl << "*****************************************************" << endl;
	List<Record*> *actualSupply = resource;
	for (Record *pom : *actualSupply) {
		cout << setw(10) << left << pom->getMinWat()->getEAN()
			<< setw(20) << pom->getMinWat()->getSupplier()->getName()
			<< setw(15) << pom->getMinWat()->getName() 
			<< setw(15) << pom->getQuantity()<< endl;
	}
}

void Cli::printSuppliers()
{
	cout << setw(5) << left << "ID"
		<< setw(20) << "Name"
		<< setw(20) << "Address"
		<< endl << "*****************************************************" << endl << endl;

	int i = 0;
	for (Supplier *pom : *target_->getSuppliers()) {
	
		cout << setw(5) << left << to_string(i)
			<< setw(20) << pom->getName()
			<< setw(20) << pom->getAddress()
			<< endl;

		i++;
	}

}

void Cli::printCustomers()
{
	cout << setw(5) << left << "ID"
		<< setw(20) << "Name"
		<< setw(20) << "Address"
		<< endl << "*****************************************************" << endl << endl;

	int i = 0;
	for (Customer *pom : *target_->getCustomers()) {

		cout << setw(5) << left << to_string(i)
			<< setw(20) << pom->getName()
			<< setw(20) << pom->getAddress()
			<< endl;

		i++;
	}

}

void Cli::printStores(Customer * cust)
{

	cout << setw(5) << left << "ID"
		<< setw(15) << "Store_Address"
		<< setw(5) << "Zone"<<endl
		<< "*****************************************************" << endl << endl;

	int i = 0;

	for (Store *pom : *cust->getStoreList()) {

		cout << endl << setw(5) << left << to_string(i)
			<< setw(15) << pom->getAddress()
			<< setw(5) << pom->getZone()
			<< endl;
		i++;
	}

}

void Cli::printMineralWaters()
{

	cout << setw(5) << left << "ID" 
		<< setw(10)<<"EAN"
		<< setw(20) << "Supplier"
		<< setw(15) << "Mineral Water"
		<< endl << "*****************************************************" << endl;
	
	int i = 0;
		for (MineralWater *pom : *target_->getMineralWaters()) {
		cout << setw(10) << left << to_string(i) 
			<< setw(10) << pom->getEAN()
			<< setw(20) << pom->getSupplier()->getName()
			<< setw(15) << pom->getName()<< endl;
		i++;
	}
}

void Cli::findBestSupplier()
{
	Supplier* pom = target_->getBestSupplier();

	cout << left << setw(20) << "Name"
		<< setw(20) << "Address"
		<< setw(15) << "Quantity"
		<< endl << "*****************************************************" << endl << endl;

		cout <<  left << setw(20) << pom->getName()
			<< setw(20) << pom->getAddress()
			<< setw(15) << to_string(pom->getRatedValue())
			<< endl;

		delete pom;
	
}

void Cli::findBestCustomerByMinWat()
{
	printf("Enter index of Mineral Water you wanto find by: \n");
	printMineralWaters();
	int indexMinWat = getInteger(0, target_->getMineralWaterCount());
	printf("Enter begining date (DD.MM.YYYY): \n");
	time_t from = getDate();

	printf("Enter ending date (DD.MM.YYYY): \n");
	time_t to = getDate();


	Customer * cus = target_->getBestCustomerByMinWat(from, to , target_->getMineralWater(indexMinWat));

	cout << left << "Name"
		<< setw(20) << "Address"
		<< endl << "*****************************************************" << endl ;
	cout << left << setw(20) << cus->getName()
		<< setw(20) << cus->getAddress()
		<< endl;
}

void Cli::findBEstCustomerBySupp()
{
	printf("Enter index of Supplier you wanto to find by: \n");
	printSuppliers();
	int index = getInteger(0, target_->getSuppliersCount());

	printf("Enter begining date (DD.MM.YYYY): \n");
	time_t from = getDate();

	printf("Enter ending date (DD.MM.YYYY): \n");
	time_t to = getDate();


	Customer * cus = target_->getBestCustomerBySupp(from, to, target_->getSupplier(index));

	cout <<  left << "Name"
		<< setw(20) << "Address"
		<< endl << "*****************************************************" << endl ;
    cout << left << setw(20) << cus->getName()
			<< setw(20) << cus->getAddress()
			<< endl;

}

void Cli::printRequests()
{
	
	cout << setw(5) << left << "ID"
		<< setw(20) << "Store_Address"
		<< setw(5) <<  "Zone"
		<< setw(10) << "Date"
		<< setw(10) << "Realized" <<endl
		<< "*****************************************************" << endl;

	int i = 0;

	for (Request *pom : *target_->getRequests()) {
		
		cout << endl << setw(5) << left << to_string(i)
			<< setw(20) << pom->getStore()->getAddress()
			<< setw(5) << to_string(pom->getStore()->getZone())
			<< setw(10) << formatDate(pom->getDate())
			<< setw(10) << pom->getRealizedString()
			<< endl;
		printRecords(pom->getRecords());
		i++;
	}
}

void Cli::printUnreaalizableRequest()
{
	cout << setw(5) << left << "ID"
		<< setw(20) << "Store_Address"
		<< setw(5) << "Zone"
		<< setw(10) << "Date"
		<< setw(10) << "Realized" << endl
		<< "*****************************************************" << endl;

	int i = 0;

	for (Request *pom : *target_->getRequests()) {
		if (pom->isRealized() != -1) {
			continue;
		}
		cout << endl << setw(5) << left << to_string(i)
			<< setw(20) << pom->getStore()->getAddress()
			<< setw(5) << to_string(pom->getStore()->getZone())
			<< setw(10) << formatDate(pom->getDate())
			<< setw(10) << pom->getRealizedString()
			<< endl;
		printRecords(pom->getRecords());
		i++;
	}
}

Cli::MItem::MItem(string & text, mFcion fcion):
	text_(text),
	fcion_(fcion)
{
}

string& Cli::MItem::toString()
{
	return text_;
}

void Cli::MItem::run(Cli * owner)
{
	(owner->*fcion_)();
}