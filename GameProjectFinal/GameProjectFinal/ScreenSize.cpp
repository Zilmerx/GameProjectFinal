
#include "ScreenSize.h"


auto ScreenSize::WidthRatio()
{
	return 1.0 - ((((double)height / (double)width) - 1.0) / 2.0);
}

auto ScreenSize::HeightRatio()
{
	return 1.0 - ((((double)width / (double)height) - 1.0) / 2.0);
}


ScreenSize::ScreenSize() :
	height{ GetHeight() },
	width{ GetWidth() }
{
}

ScreenSize::value_type ScreenSize::GetHeight()
{
	RECT size;

	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();

	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &size);

	return size.bottom - size.top;
}

ScreenSize::value_type ScreenSize::GetWidth()
{
	RECT size;

	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();

	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &size);

	return size.right - size.left;
}