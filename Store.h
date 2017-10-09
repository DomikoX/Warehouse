///////////////////////////////////////////////////////////
//  Store.h
//  Implementation of the Class Store
//  Created on:      31-mar-2016 13:15:03
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_38EDFBEE_32DB_49ac_BC85_BF175C6865BF__INCLUDED_)
#define EA_38EDFBEE_32DB_49ac_BC85_BF175C6865BF__INCLUDED_
#include <string>
using namespace std;
class Store
{

public:
	Store(const string& address, int zone);
	virtual ~Store();

	const string& getAddress();
	int getZone();
	string toString();

private:
	string address_;
	int zone_;

};
#endif // !defined(EA_38EDFBEE_32DB_49ac_BC85_BF175C6865BF__INCLUDED_)
