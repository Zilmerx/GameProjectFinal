#pragma once

#include "Position.h"

struct MouseManager
{
	static Point2D<int> GetGlobalCursorPos();

	static Point2D<int> GetClientCursorPos();
};