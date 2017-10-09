///////////////////////////////////////////////////////////
//  Request.cpp
//  Implementation of the Class Request
//  Created on:      31-mar-2016 13:15:03
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Request.h"


Request::Request(Store * store, time_t date, int status) :
	records_(new ArrayList<Record *>()),
	store_(store),
	date_(date),
	status_(status)
{
}

Request::Request() :
	records_(new ArrayList<Record *>()),
	status_(0)

	{

}



Request::Request(Store * store, time_t date) :
	records_(new ArrayList<Record *>()),
	store_(store),
	date_(date),
	status_(0)
{
}

Request::~Request(){

	for (int i = 0;i < records_->size();i++) {
		delete (*records_)[i];
	}
	delete records_;
}





List<Record*>* Request::getRecords(){

	return records_;
}



void Request::addRecord(Record* newRecord) {
	records_->add(newRecord);
}

time_t Request::getDate()
{
	return date_;
}

Store * Request::getStore()
{
	return store_;
}

string Request::toString()
{
	string text = store_->toString() + "  " + ctime(&date_) +"\n";
	for (Record *rec : *records_) {
		text += rec->toString() + "\n";
	}
	text += "REALIAZTION STATUS = " + to_string(status_) + "\n";
	return text;
}

int Request::isRealized()
{
	return status_;
}

string Request::getRealizedString()
{
	string r[4] = { "MISSED","UREALIZABLE"," NOT YET","REALIZED" };
	return r[status_ + 2];
}

void Request::setRealized(bool realized)
{
	status_ = realized ? 1 : -1;
}

void Request::setMissed()
{
	status_ = -2;
}
