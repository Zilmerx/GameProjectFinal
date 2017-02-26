#pragma once

#include "ResourceManager.h"
#include "MapTile.h"

struct Grass : public MapTile
{
	Grass() :
		MapTile( ResourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga") )
	{
	}
};