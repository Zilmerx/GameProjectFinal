#pragma once

#include "LimitedT.h"

using HP_T = unsigned int;

class HP : public LimitedT<unsigned int>
{
public:

	HP();

	HP(HP_T value);

	bool IsInjured() const;

	bool IsDead() const;

	static constexpr double GetInjuredCriticalPercentage();
};