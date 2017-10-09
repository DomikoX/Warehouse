///////////////////////////////////////////////////////////
//  MineralWater.h
//  Implementation of the Class MineralWater
//  Created on:      31-mar-2016 13:29:26
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_0EAE6EAD_4DF4_42fd_B550_038E8EDFBEE8__INCLUDED_)
#define EA_0EAE6EAD_4DF4_42fd_B550_038E8EDFBEE8__INCLUDED_
#include "Supplier.h"
#include <string>
using namespace std;
class MineralWater
{

public:
	MineralWater(int ean, const string& name,Supplier *suplier);
	virtual ~MineralWater();

	int getEAN();
	const string& getName();
	Supplier* getSupplier();
	string toString();

private:
	int ean_;
	string name_;
	Supplier *supplier_;

};
#endif // !defined(EA_0EAE6EAD_4DF4_42fd_B550_038E8EDFBEE8__INCLUDED_)
