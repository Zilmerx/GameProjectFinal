#pragma once

#include "Constexpr.h"

class MovementCost
{
	constexpr double BaseDiagCost() const
	{
		return _sqrt<double>(2.0);
	}

	virtual double cost() = 0;

public:

	double GetCost()
	{
		return cost();
	}

	double GetDiagCost()
	{
		return cost() * BaseDiagCost();
	}
};