#pragma once

#include "Singleton.h"
#include "Position.h"

struct MouseManager : Singleton<MouseManager>
{
	Point2D<int> GetGlobalCursorPos();

	Point2D<int> GetClientCursorPos();

	Point2D<int> GetGridCursorPos();
};