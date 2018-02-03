#pragma once

#include "StackAllocator.h"

class StackAllocatorEmptyType
{

public:

	StackAllocatorEmptyType()
	{

	}

	template<class T>
	T* allocate(unsigned int count)
	{
		return StackAllocator<10_Mo>::get().allocate<T>(count);
	}


	template<class T>
	static void deallocate(T* ptr, unsigned int count)
	{
		return StackAllocator<10_Mo>::get().deallocate<T>(ptr, count);
	}
};