#pragma once

#include "Mallocator.h"

template<class T>
class MallocatorEmptyType
{

public:

	MallocatorEmptyType()
	{

	}

	T* allocate(unsigned int count)
	{
		return Mallocator::get().allocate<T>(count);
	}

	static void deallocate(T* ptr, unsigned int count)
	{
		return Mallocator::get().deallocate<T>(ptr, count);
	}
};