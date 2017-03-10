#pragma once

#include "Windows.h"
#include "Singleton.h"

class ScreenSize : public Singleton<ScreenSize>
{
	friend struct Singleton<ScreenSize>;

public:

	using value_type = unsigned long;

	value_type height;
	value_type width;

	auto WidthRatio();

	auto HeightRatio();

private:

	ScreenSize();

	value_type GetHeight();

	value_type GetWidth();
};