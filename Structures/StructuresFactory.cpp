#include "StructuresFactory.h"
#include "DSRoutines.h"
//#include "../GUI/Logger.h"
//#include "../GUI/Routines.h"

using namespace std;
using namespace DS;

StructuresFactory* StructuresFactory::factory_ = nullptr;

AbstractDataStructures::AbstractDataStructures(StructureADS ads, Structure * prototype) :
	ads_(ads),
	prototype_(prototype),
	clones_(new std::vector<Structure*>),
	totalCreated_(0)
{
}

AbstractDataStructures::~AbstractDataStructures()
{
	for (vector<Structure*>::iterator it = clones_->begin(); it != clones_->end(); it++)
		delete *it;
	delete clones_;
	delete prototype_;
}

StructureADS AbstractDataStructures::getADSType()
{
	return ads_;
}

Structure * AbstractDataStructures::clonePrototype()
{
	Structure* newStructure = prototype_->clone();
	totalCreated_++;
	clones_->push_back(newStructure);
	return newStructure;
}

void AbstractDataStructures::removeStructure(const int index)
{
	Structure* deleted = getCloneByIndex(index);
	if (deleted != nullptr)
	{
		clones_->erase(clones_->begin() + index);
		delete deleted;
	}
}

int AbstractDataStructures::totalCreated() const
{
	return totalCreated_;
}

Structure * DS::AbstractDataStructures::getCloneByIndex(const int index) const
{
	return index >= 0 && static_cast<size_t>(index) < clones_->size() ? clones_->at(index) : nullptr;
}

AbstractDataTypes::AbstractDataTypes(StructureADT adt) :
	adt_(adt),
	structures_(new vector<AbstractDataStructures*>),
	activeStructures_(new vector<StructureWithADS>)
{
}

AbstractDataTypes::~AbstractDataTypes()
{
	for (vector<AbstractDataStructures*>::iterator it = structures_->begin(); it != structures_->end(); it++)
		delete *it;
	delete activeStructures_;
}

StructureADT DS::AbstractDataTypes::getADTType() const
{
	return adt_;
}

void AbstractDataTypes::registerPrototype(StructureADS ads, Structure * prototype)
{
	if (getADSContainerByType(ads) == nullptr)
		structures_->push_back(new AbstractDataStructures(ads, prototype));
	else
		throw logic_error("Prototype for type " + UI::Routines::convertStructureADSToStr(ads) + " is already registered!");
}

Structure * AbstractDataTypes::createStructure(StructureADS ads)
{
	AbstractDataStructures* ADS = getADSContainerByType(ads);

	if (ADS != nullptr)
	{
		StructureWithADS newStructure;
		newStructure.structure = ADS->clonePrototype();
		newStructure.ads = ads;

		activeStructures_->push_back(newStructure);
		return newStructure.structure;
	}
	else 
		throw logic_error("Can not create structure of type " + UI::Routines::convertStructureADSToStr(ads) + "!");
}

void AbstractDataTypes::removeStructure(const int index)
{
	AbstractDataStructures* ADS = index >= 0 && static_cast<size_t>(index) < activeStructures_->size() ? getADSContainerByType(activeStructures_->at(index).ads) : nullptr;
	if (ADS != nullptr)
	{
		activeStructures_->erase(activeStructures_->begin() + index);
		ADS->removeStructure(index);
	}
	else
		throw logic_error("Can not remove structure from index " + UI::Routines::convertIntToStr(index) + "!");
}

AbstractDataStructures * DS::AbstractDataTypes::getADSContainerByType(const StructureADS type) const
{
	for (vector<AbstractDataStructures*>::iterator it = structures_->begin(); it != structures_->end(); it++)
		if ((*it)->getADSType() == type)
			return *it;
	return nullptr;
}

AbstractDataStructures * DS::AbstractDataTypes::getADSContainerByIndex(int index) const
{
	return index >= 0 && static_cast<size_t>(index) < structures_->size() ? structures_->at(index) : nullptr;
}

Structure * DS::AbstractDataTypes::getActiveStructureByIndex(const int index) const
{
	return index >= 0 && static_cast<size_t>(index) < activeStructures_->size() ? activeStructures_->at(index).structure : nullptr;
}

size_t AbstractDataTypes::activeStructuresSize() const
{
	return activeStructures_->size();
}

size_t DS::AbstractDataTypes::ADSContainerSize() const
{
	return structures_->size();
}

StructuresFactory::StructuresFactory() :
	types_(new vector<AbstractDataTypes*>)
{
	for (int i = 0; i < StructureADT::adtCount; i++)
		types_->push_back(new AbstractDataTypes(static_cast<StructureADT>(i)));
}

StructuresFactory::~StructuresFactory()
{
	for (vector<AbstractDataTypes*>::iterator it = types_->begin(); it != types_->end(); it++)
		delete *it;
	delete types_;
}

StructuresFactory * DS::StructuresFactory::getFactory()
{
	if (factory_ == nullptr)
		factory_ = new StructuresFactory();
	return factory_;
}

void StructuresFactory::finalize()
{
	delete factory_;
}

AbstractDataTypes * DS::StructuresFactory::getADTContainer(const StructureADT adt) const
{
	return types_->at(adt);
}

void StructuresFactory::registerPrototype(StructureADS ads, Structure * prototype)
{
	try
	{
		StructureADT adt = DSRoutines::convertADStoADT(ads);
		AbstractDataTypes* types = (*types_)[adt];
		types->registerPrototype(ads,prototype);

		Logger::Hint("Prototype registered: " + UI::Routines::convertStructureADSToStr(ads));
	}
	catch (exception ex)
	{
		Logger::Error("Prototype registration failed: " + string(ex.what()));
	}
}

Structure * StructuresFactory::createStructure(StructureADS ads)
{
	try
	{
		StructureADT adt = DSRoutines::convertADStoADT(ads);
		AbstractDataTypes* types = (*types_)[adt];
		return types->createStructure(ads);
	}
	catch (invalid_argument ex)
	{
		Logger::Error("Structure creation failed: : " + string(ex.what()));
		return nullptr;
	}
}

void DS::StructuresFactory::removeStructure(StructureADT adt, const int index)
{
	try
	{
		AbstractDataTypes* types = (*types_)[adt];
		types->removeStructure(index);
	}
	catch (exception ex)
	{
		Logger::Error("Structure removal failed: " + string(ex.what()));
	}
}


