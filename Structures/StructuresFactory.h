#pragma once

#include "Structure.h"
#include "StructureID.h"
#include <vector>

namespace DS {

	
	class AbstractDataStructures
	{
	private:
		StructureADS ads_;
		Structure* prototype_;
		std::vector<Structure*>* clones_;
		int totalCreated_;

	public:
		AbstractDataStructures(StructureADS ads, Structure* prototype);
		~AbstractDataStructures();

		StructureADS getADSType();

		Structure* clonePrototype();
		void removeStructure(const int index);
		int totalCreated() const;

		Structure* getCloneByIndex(const int index) const;
	};

	class AbstractDataTypes
	{
	private: struct StructureWithADS
	{
		Structure* structure;
		StructureADS ads;
	};
	private:
		StructureADT adt_;
		std::vector<AbstractDataStructures*>* structures_;
		std::vector<StructureWithADS>* activeStructures_;
	public:
		AbstractDataTypes(StructureADT adt);
		~AbstractDataTypes();

		StructureADT getADTType() const;

		void registerPrototype(StructureADS ads, Structure* prototype);
		Structure* createStructure(StructureADS ads);
		void removeStructure(const int index);

		AbstractDataStructures* getADSContainerByType(const StructureADS type) const;
		AbstractDataStructures* getADSContainerByIndex(int index) const;

		Structure* getActiveStructureByIndex(const int index) const;

		size_t activeStructuresSize() const;
		size_t ADSContainerSize() const;
	};

	class StructuresFactory
	{
	private:
		static StructuresFactory* factory_;

		std::vector<AbstractDataTypes*>* types_;

		StructuresFactory();
		~StructuresFactory();
	public:
		static StructuresFactory* getFactory();
		static void finalize();

		AbstractDataTypes* getADTContainer(const StructureADT adt) const;

		void registerPrototype(StructureADS ads, Structure* prototype);

		Structure* createStructure(StructureADS ads);
		void removeStructure(StructureADT adt, const int index);

	};

}

