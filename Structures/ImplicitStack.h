#pragma once

#include "Stack.h"
#include "ArrayList.h"
namespace DS
{
	template<typename T>
	class ImplicitStack :
		public Stack<T>
	{
	public:
		ImplicitStack();
		ImplicitStack(const ImplicitStack<T>& other);
		~ImplicitStack() override;

		Structure* clone() const override;
		ImplicitStack<T>& operator=(const ImplicitStack<T>& other);

		void push(const T& data) override;
	protected:
		int indexOfPeek() const override;
	};

	template<typename T>
	ImplicitStack<T>::ImplicitStack() : Stack<T>(ArrayList<T>())
	{
	
	}

	template<typename T>
	ImplicitStack<T>::ImplicitStack(const ImplicitStack<T>& other) : Stack<T>(ArrayList<T>())
	{
	
	}

	template<typename T>
	ImplicitStack<T>::~ImplicitStack()
	{
	}

	template<typename T>
	Structure* ImplicitStack<T>::clone() const
	{
		return new ImplicitStack<T>(*this);
	}

	template<typename T>
	ImplicitStack<T>& ImplicitStack<T>::operator=(const ImplicitStack<T>& other)
	{
		returnn Stack<T>::operator=(other);
	}

	template<typename T>
	void ImplicitStack<T>::push(const T& data)
	{
		list_->add(data);
	}

	template<typename T>
	inline int ImplicitStack<T>::indexOfPeek() const
	{
		return static_cast<int> ( list_->size()) - 1;
	}
}