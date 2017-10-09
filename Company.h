///////////////////////////////////////////////////////////
//  Company.h
//  Implementation of the Class Company
//  Created on:      31-mar-2016 13:15:00
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#if !defined(EA_D162E393_5F49_4f8d_810E_C6EA479923C9__INCLUDED_)
#define EA_D162E393_5F49_4f8d_810E_C6EA479923C9__INCLUDED_
#include <string>
using namespace std;

class Company
{

public:
	Company(const string& address, const string& name);
	virtual ~Company();

	const string& getAddress();
	const string& getName();
	string toString();
	void clearRatedValue();
	void addRatedValue(int ratedValue);
	int getRatedValue();


private:
	string address_;
	string name_;
	int ratedValue_;


};
#endif // !defined(EA_D162E393_5F49_4f8d_810E_C6EA479923C9__INCLUDED_)
