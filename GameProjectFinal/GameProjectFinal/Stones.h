#pragma once

#include "ResourceManager.h"
#include "MapTile.h"

struct Stones : public MapTile
{
	Stones() :
		MapTile(ResourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/stone01.tga"))
	{
	}
};