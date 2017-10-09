#pragma once

#include "LinkedList.h"
#include "PriorityQueue.h"
#include "PriorityQueue_List.h"

namespace DS {

	template<typename T>
	class PriorityQueue_LinkedList :
		public PriorityQueue_List<T>
	{
	public:
		PriorityQueue_LinkedList();
		PriorityQueue_LinkedList(const PriorityQueue_LinkedList<T>& other);

		Structure* clone() const override;
		PriorityQueue_LinkedList<T>& operator=(const PriorityQueue_LinkedList<T>& other);

		void push(const int priority, const T& data) override;
		T pop() override;
		T& peek() override;
		const T& peek() const override;
		int peekPriority() const override;
	};

	template<typename T>
	PriorityQueue_LinkedList<T>::PriorityQueue_LinkedList() 
	{
    throw -1;
	}

	template<typename T>
	PriorityQueue_LinkedList<T>::PriorityQueue_LinkedList(const PriorityQueue_LinkedList<T>& other) 
	{
	  throw -1;
	}

	template<typename T>
	inline Structure * PriorityQueue_LinkedList<T>::clone() const
	{
	  throw -1;
	}

	template<typename T>
	inline PriorityQueue_LinkedList<T>& PriorityQueue_LinkedList<T>::operator=(const PriorityQueue_LinkedList<T>& other)
	{
	  throw -1;
	}

	template<typename T>
	inline void PriorityQueue_LinkedList<T>::push(const int priority, const T & data)
	{
    throw -1;
	}

	template<typename T>
	inline T PriorityQueue_LinkedList<T>::pop()
	{
	  throw -1;
	}

	template<typename T>
	inline T & PriorityQueue_LinkedList<T>::peek()
	{
	  throw -1;
	}

	template<typename T>
	inline const T & PriorityQueue_LinkedList<T>::peek() const
	{
	  throw -1;
	}

	template<typename T>
	inline int PriorityQueue_LinkedList<T>::peekPriority() const
	{
	  throw -1;
	}

}