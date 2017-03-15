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

	return Point2D<int>{-1, -1};
}

Point2D<int> MouseManager::GetGridCursorPos()
{
	Point2D<int> click = MouseManager::get().GetClientCursorPos();

	XMFLOAT3 cam = Globals::get().camera->GetPosition();
	cam.z = std::abs(cam.z);

	double ScreenHeight = (double)ScreenSize::get().height;
	double ScreenWidth = (double)ScreenSize::get().width;
	click.y = ScreenSize::get().height - click.y;

	constexpr double radian = 45.0 / 180 * PI;
	
	/*
	
	  PI * (sqrt( h^2 + (tan(45) * h)^2)
		    ---------------------------
			         180 / 45.0
     --------------------------------------
	             tan(45) * h
	  
	*/

	const double ratio = (PI * ((std::sqrt( std::pow(cam.z, 2) + std::pow(std::tan(radian) * cam.z, 2))) / (180.0 / 45.0))) / (std::tan(radian) * cam.z);

	const double gridHeight = cam.z * ratio * (ScreenHeight / ScreenWidth);
	const double gridWidth  = cam.z * ratio;

	auto GridPosX = ((double)click.x * gridWidth) / ScreenWidth;
	auto GridPosY = ((double)click.y * gridHeight) / ScreenHeight;

	GridPosX -= (gridWidth / 2.0);
	GridPosY -= (gridHeight / 2.0);

	GridPosX += cam.x + 0.5;
	GridPosY += cam.y + 0.5;

	return Point2D<int>{ (int)GridPosX, (int)GridPosY };
}