#pragma once

#include "Incopiable.h"

template <class S, class Chain = Vide>
struct Singleton : Incopiable<Chain> 
{
	static S& get() 
	{
		static S singleton;
		return singleton;
	}
};