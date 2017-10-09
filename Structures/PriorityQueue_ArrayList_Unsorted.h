#pragma once

#include "PriorityQueue.h"
#include "PriorityQueue_ArrayList.h"

namespace DS {
	template<typename T>
	class PriorityQueue_ArrayList_Unsorted :
		public PriorityQueue_ArrayList<T>
	{
	public:
		PriorityQueue_ArrayList_Unsorted();
		PriorityQueue_ArrayList_Unsorted(const PriorityQueue_ArrayList_Unsorted<T>& other);

		Structure* clone() const override;
		PriorityQueue_ArrayList_Unsorted<T>& operator=(const PriorityQueue_ArrayList_Unsorted<T>& other);

		void push(const int priority, const T& data) override;
		T pop() override;
		
	};

	template<typename T>
	PriorityQueue_ArrayList_Unsorted<T>::PriorityQueue_ArrayList_Unsorted()
	{
	}

	template<typename T>
	PriorityQueue_ArrayList_Unsorted<T>::PriorityQueue_ArrayList_Unsorted(const PriorityQueue_ArrayList_Unsorted<T>& other) :
		PriorityQueue_ArrayList<T>(other)
	{
	}

	template<typename T>
	Structure* PriorityQueue_ArrayList_Unsorted<T>::clone() const
	{
		return new PriorityQueue_ArrayList_Unsorted(*this);
	}

	template<typename T>
	PriorityQueue_ArrayList_Unsorted<T>& PriorityQueue_ArrayList_Unsorted<T>::operator=(const PriorityQueue_ArrayList_Unsorted<T>& other)
	{
		PriorityQueue_List<T>::operator=(other);
		return *this;

	}

	template<typename T>
	void PriorityQueue_ArrayList_Unsorted<T>::push(const int priority, const T & data)
	{
		list_->add(new PriorityItem<T>(priority,data));
	}

	template<typename T>
	T PriorityQueue_ArrayList_Unsorted<T>::pop()
	{
		PriorityItem<T> *pom = list_->removeAt(indexOfHighestPriority());
		T data = pom->getData();
		delete pom;
		return data;
	}

}