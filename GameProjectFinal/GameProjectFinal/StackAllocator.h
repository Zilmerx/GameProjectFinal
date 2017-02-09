#pragma once

#include "ByteLiterals.h"
#include "Singleton.h"

template<unsigned long long size>
class StackAllocator : public Singleton<StackAllocator<size>>
{
	char _bytes[size];
	char* _head;

	friend class Singleton<StackAllocator<size>>;

protected:

	StackAllocator() :
		_head{ _bytes }
	{
	}

public:

	template<class T>
	T* allocate(size_t count)
	{
		T* ptr = reinterpret_cast<T*>(_head);

		_head += sizeof(T) * count;

		return ptr;
	}

	template<class T>
	void deallocate(T*, size_t count)
	{
		_head -= sizeof(T) * count;
	}
};