///////////////////////////////////////////////////////////
//  Supplier.h
//  Implementation of the Class Supplier
//  Created on:      31-mar-2016 13:15:04
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_9F5E5BD9_D704_4d1c_BE27_04ADAACBE6FC__INCLUDED_)
#define EA_9F5E5BD9_D704_4d1c_BE27_04ADAACBE6FC__INCLUDED_

#include <string>

#include "Company.h"
using namespace std;

class Supplier : public Company
{

public:
	Supplier(string name, string address);
	Supplier(Supplier *other);
	virtual ~Supplier();
	
	

};
#endif // !defined(EA_9F5E5BD9_D704_4d1c_BE27_04ADAACBE6FC__INCLUDED_)
