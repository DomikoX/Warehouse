///////////////////////////////////////////////////////////
//  record.h
//  Implementation of the Class record
//  Created on:      31-mar-2016 13:15:02
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_83A87F8B_EF19_41ae_9A54_A274965BF0E2__INCLUDED_)
#define EA_83A87F8B_EF19_41ae_9A54_A274965BF0E2__INCLUDED_

#include "MineralWater.h"
#include <ctime>
typedef std::time_t time_t;

class Record
{

public:
	Record(MineralWater *minWat,int quantity);
	virtual ~Record();

	
	MineralWater * getMinWat();
	int getQuantity();
	void setQuantity(int newVal);
	
	string toString();

private:
	
	MineralWater *mineralWater_;
	int quantity_;
	

};
#endif // !defined(EA_83A87F8B_EF19_41ae_9A54_A274965BF0E2__INCLUDED_)
