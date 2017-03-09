#pragma once

#include "Singleton.h"
#include "Point2D.h"

struct MouseManager : Singleton<MouseManager>
{
	Point2D<int> GetGlobalCursorPos();

	Point2D<int> GetClientCursorPos();

	Point2D<int> GetGridCursorPos();
};