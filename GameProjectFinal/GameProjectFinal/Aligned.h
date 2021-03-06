#pragma once

class Aligned
{

protected:
	Aligned() {}

public:

	void* operator new(unsigned int i)
	{
		return _aligned_malloc(i, 16);
	}

	void operator delete(void* p)
	{
		_aligned_free(p);
	}
};