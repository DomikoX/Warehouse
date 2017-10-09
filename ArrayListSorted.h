#pragma once
#include "S:\Škola\údajové štruktúry\Semestr\Structures\ArrayList.h"
namespace DS
{
template<typename T>
class ArrayListSorted :
	public ArrayList<T>
{
public:

	//konstruktor este s  compare fcion
	ArrayListSorted( const CompareFunction<T>& compareFcion);
	ArrayListSorted(const ArrayListSorted<T>& other);
	ArrayListSorted();
	
	void add(const T& data) override;

private:

	void  insert(const T& data, const int index) override;
	CompareFunction<T> compFcion_;

};



template<typename T>
inline ArrayListSorted<T>::ArrayListSorted(const CompareFunction<T>& compareFcion):
	compFcion_(compareFcion)
{
}

template<typename T>
inline ArrayListSorted<T>::ArrayListSorted(const ArrayListSorted<T>& other):
	ArrayList<T>(other)
{
}

template<typename T>
inline ArrayListSorted<T>::ArrayListSorted()
{
}




template<typename T>
void ArrayListSorted<T>::add(const T & data)
{

	// obj * const &
	int startIndex = 0;
	int stopIndex = static_cast<int>(size());

	while (startIndex < stopIndex) {
		int index = startIndex + (stopIndex - startIndex) / 2;

		
		if (compFcion_( data,(*this)[index]) > 0) {
			startIndex = index + 1;
		}
		else {
			stopIndex = index;
		}
	}

	ArrayList<T>::insert(data, stopIndex);

}

template<typename T>
void ArrayListSorted<T>::insert(const T & data, const int index)
{
	//prekryte
}
}