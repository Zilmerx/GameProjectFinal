#pragma once

#include "LimitedT.h"

class Transparency : private LimitedT<float>
{
public:

	Transparency() :
		LimitedT<float>(1.0, 0.0, 1.0)
	{
	}

	Transparency(float value) :
		LimitedT<float>(value, 0.0, 1.0)
	{
	}

	float GetTransparency()
	{
		return GetValue();
	}

	void SetTransparency(float value)
	{
		SetValue(value);
	}
};