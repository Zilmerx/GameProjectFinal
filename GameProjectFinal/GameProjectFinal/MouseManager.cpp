#include "MouseManager.h"

#include <Windows.h>
#include "ScreenSize.h"
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

Point2D<int> MouseManager::GetGridCursorPos()
{
	Point2D<int> click = MouseManager::get().GetClientCursorPos();

	XMFLOAT3 cam = Globals::get().camera->GetPosition();
	cam.z = std::abs(cam.z);

	float ScreenHeight = (float)ScreenSize::get().height;
	float ScreenWidth = (float)ScreenSize::get().width;
	click.y = ScreenHeight - click.y;

	using T = long double;

	const T halfRatio = ((1 - ScreenHeight / ScreenWidth) / 2);

	const T GridHeight = (cam.z - (cam.z * halfRatio) - 1);
	const T GridWidth = (cam.z + (cam.z * halfRatio) - 1);

	const T GridPosY = cam.y + (((T)click.y * GridHeight) / ScreenHeight) - (GridHeight / 2);
	const T GridPosX = cam.x + (((T)click.x * GridWidth) / ScreenWidth) - (GridWidth / 2);

	return Point2D<int>{ (int)std::round(GridPosX), (int)std::round(GridPosY) };
}