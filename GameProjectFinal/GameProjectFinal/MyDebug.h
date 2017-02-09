#pragma once

#include "Singleton.h"

#include <assert.h>

class My_Debug : public Singleton<My_Debug>
{
public:

	constexpr bool debug_is_active() const
	{
		#ifdef _DEBUG
		return true;
		#elif !NDEBUG 
		return true;
		#else
		return false;
		#endif
	}

	
};