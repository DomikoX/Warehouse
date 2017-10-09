///////////////////////////////////////////////////////////
//  Supply.h
//  Implementation of the Class Supply
//  Created on:      31-mar-2016 13:15:04
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_9A0252FB_A7E0_4cc8_9D27_A34AB3535F41__INCLUDED_)
#define EA_9A0252FB_A7E0_4cc8_9D27_A34AB3535F41__INCLUDED_

#include "Supplier.h"
#include "MineralWater.h"
#include <ctime>


class Supply
{

public:
	Supply(time_t date, MineralWater* ean, int quantity);

	Supply(time_t date, MineralWater* ean, int quantity,int rest);
	virtual ~Supply();

	time_t getDate();
	MineralWater* getMinWat();
	int getQuantity();
	int getRest();
	void subRest(int count);
	string toString();

private:
	time_t date_;
	MineralWater* mineralWater_;
	int quantity_;
	int rest_;
	

};
#endif // !defined(EA_9A0252FB_A7E0_4cc8_9D27_A34AB3535F41__INCLUDED_)
