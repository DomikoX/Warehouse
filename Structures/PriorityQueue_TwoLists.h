#pragma once

#include "PriorityQueue.h"

namespace DS {

	template<typename T>
	class PriorityQueue_TwoLists :
		public PriorityQueue
	{
	public:
		PriorityQueue_TwoLists();
		PriorityQueue_TwoLists(const PriorityQueue_TwoLists<T>& other);
		~PriorityQueue_TwoLists();

		Structure* clone() const;
		Structure& operator=(const Structure& other) override;
		PriorityQueue<T>& operator=(const PriorityQueue<T>& other) override;
		PriorityQueue_TwoLists<T>& operator=(const PriorityQueue_TwoLists<T>& other);

		size_t size() const;
		bool isEmpty() const;
		void clear();

		void push(const int priority, const T& data);
		T pop();
		T& peek();
		const T& peek() const;
		int peekPriority() const;
	private:
		// atributy
	};

	template<typename T>
	PriorityQueue_TwoLists<T>::PriorityQueue_TwoLists()
	{
    throw -1;
	}

	template<typename T>
	PriorityQueue_TwoLists<T>::PriorityQueue_TwoLists(const PriorityQueue_TwoLists<T>& other)
	{
    throw -1;
	}

	template<typename T>
	PriorityQueue_TwoLists<T>::~PriorityQueue_TwoLists()
	{
	}

	template<typename T>
	Structure * PriorityQueue_TwoLists<T>::clone() const
	{
	  throw -1;
	}

	template<typename T>
	Structure & PriorityQueue_TwoLists<T>::operator=(const Structure & other)
	{
	  throw -1;
	}

	template<typename T>
	PriorityQueue<T>& PriorityQueue_TwoLists<T>::operator=(const PriorityQueue<T>& other)
	{
	  throw -1;
	}

	template<typename T>
	PriorityQueue_TwoLists<T>& PriorityQueue_TwoLists<T>::operator=(const PriorityQueue_TwoLists<T>& other)
	{
	  throw -1;
	}

	template<typename T>
	size_t PriorityQueue_TwoLists<T>::size() const
	{
	  throw -1;
	}

	template<typename T>
	bool PriorityQueue_TwoLists<T>::isEmpty() const
	{
	  throw -1;
	}

	template<typename T>
	void PriorityQueue_TwoLists<T>::clear()
	{
    throw -1;
	}

	template<typename T>
	void PriorityQueue_TwoLists<T>::push(const int priority, const T & data)
	{
    throw -1;
	}

	template<typename T>
	T PriorityQueue_TwoLists<T>::pop()
	{
	  throw -1;
	}

	template<typename T>
	T & PriorityQueue_TwoLists<T>::peek()
	{
	  throw -1;
	}

	template<typename T>
	const T & PriorityQueue_TwoLists<T>::peek() const
	{
	  throw -1;
	}

	template<typename T>
	int PriorityQueue_TwoLists<T>::peekPriority() const
	{
	  throw -1;
	}

}