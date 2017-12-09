#pragma once

#include <iostream>
#include "Singleton.h"

#include "Exception.h"

class Debug
{
public:

	constexpr bool Debug_is_active() const
	{
		#ifdef _DEBUG
		return true;
		#elif !NDEBUG 
		return true;
		#else
		return false;
		#endif
	}

	static inline void Assert(bool expression, const wchar_t* message)
	{
		if (expression == false)
		{
			THROW_EXCEPTION(UnhandledException, message);
		}
	}
};