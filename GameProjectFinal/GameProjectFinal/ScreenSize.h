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

	auto WidthRatio()
	{
		return 1.0 - ((((double)height / (double)width) - 1.0) / 2.0);
	}

	auto HeightRatio()
	{
		return 1.0 - ((((double)width / (double)height) - 1.0) / 2.0);
	}

private:

	ScreenSize() :
		height{ GetHeight() },
		width{ GetWidth() }
	{
	}

	value_type GetHeight()
	{
		RECT size;

		// Get a handle to the desktop window
		const HWND hDesktop = GetDesktopWindow();

		// Get the size of screen to the variable desktop
		GetWindowRect(hDesktop, &size);

		return size.bottom - size.top;
	}

	value_type GetWidth()
	{
		RECT size;

		// Get a handle to the desktop window
		const HWND hDesktop = GetDesktopWindow();

		// Get the size of screen to the variable desktop
		GetWindowRect(hDesktop, &size);

		return size.right - size.left;
	}
};