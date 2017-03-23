#pragma once

#include "ResourceManager.h"
#include "MapTile.h"

struct Wall : public MapTile
{
	Wall();

	double cost() override;
};