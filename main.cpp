#include "cli.h"
#include "Warehouse.h"
#include "ArrayListSorted.h"



int main() {
	
	
	Warehouse war = Warehouse();
	
	war.InitializeFromFile();
	Cli comm = Cli(&war);
    comm.run();

	war.saveToFile();

	
	return 0;
};