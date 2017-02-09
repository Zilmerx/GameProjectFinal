#pragma once

#include "Mallocator.h"

template<class T>
class MallocatorEmptyType
{

public:

	MallocatorEmptyType()
	{

	}

	T* allocate(size_t count)
	{
		return Mallocator::get().allocate<T>(count);
	}

	static void deallocate(T* ptr, size_t count)
	{
		return Mallocator::get().deallocate<T>(ptr, count);
	}
};