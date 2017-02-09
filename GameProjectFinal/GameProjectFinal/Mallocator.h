#pragma once

#include "ByteLiterals.h"
#include "Singleton.h"

class Mallocator : public Singleton<Mallocator>
{
	friend class Singleton<Mallocator>;

protected:

	Mallocator()
	{
	}

public:

	template<class T>
	T* allocate(size_t count)
	{
		return reinterpret_cast<T*>(malloc(count * sizeof(T)));
	}

	template<class T>
	void deallocate(T* ptr, size_t)
	{
		free(ptr);
	}
};