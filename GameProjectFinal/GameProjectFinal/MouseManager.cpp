#include "MouseManager.h"

#include <Windows.h>
#include "Settings.h"
#include "SystemClass.h"

Point2D<int> MouseManager::GetGlobalCursorPos()
{
	POINT p;
	if (GetCursorPos(&p))
	{
		return Point2D<int>{p.x, p.y};
	}
	else
	{
		return Point2D<int>{-1, -1};
	}
}

Point2D<int> MouseManager::GetClientCursorPos()
{
	POINT p;
	if (GetCursorPos(&p))
	{
		if (ScreenToClient(Globals::get().system->GetHWND(), &p))
		{
			return Point2D<int>{p.x, p.y};
		}
	}
	else
	{
		return Point2D<int>{-1, -1};
	}
}