///////////////////////////////////////////////////////////
//  Request.h
//  Implementation of the Class Request
//  Created on:      31-mar-2016 13:15:03
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_49D2392F_3B02_4661_868B_E00A22D3C610__INCLUDED_)
#define EA_49D2392F_3B02_4661_868B_E00A22D3C610__INCLUDED_

#include "record.h"
#include "Store.h"
#include "Structures\List.h"

#include "Structures\ArrayList.h"
using namespace DS;
class Request
{

public:
	Request(Store *store, time_t date);

	Request(Store *store, time_t date,int status);
	Request();
	virtual ~Request();
	
	List<Record*>* getRecords();
	
	void addRecord(Record* newRecord);
	time_t getDate();
	Store* getStore();
	string toString();

	int isRealized();
	string getRealizedString();
	void setRealized(bool realized);
	void setMissed();

private:
	List<Record*>* records_;
	time_t date_;
	Store *store_;
	int status_;  // 0 = new 1 = realized yet -1 = cant realize

};
#endif // !defined(EA_49D2392F_3B02_4661_868B_E00A22D3C610__INCLUDED_)
