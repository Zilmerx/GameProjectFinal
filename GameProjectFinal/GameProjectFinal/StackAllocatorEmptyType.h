#pragma once

#include "StackAllocator.h"

class StackAllocatorEmptyType
{

public:

	StackAllocatorEmptyType()
	{

	}

	template<class T>
	T* allocate(size_t count)
	{
		return StackAllocator<10_Mo>::get().allocate<T>(count);
	}


	template<class T>
	static void deallocate(T* ptr, size_t count)
	{
		return StackAllocator<10_Mo>::get().deallocate<T>(ptr, count);
	}
};