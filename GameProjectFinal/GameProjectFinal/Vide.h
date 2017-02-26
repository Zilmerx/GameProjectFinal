#pragma once

#include "ResourceManager.h"
#include "MapTile.h"

struct Tile_Vide : public MapTile
{
	Tile_Vide() :
		MapTile(ResourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/UNUSED_DEBUGE.tga"))
	{
	}
};