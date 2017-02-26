#pragma once

#include <vector>
#include <memory>

#include "AllMapTileDefs.h"

#include "BGRColor.h"

class Map
{
	std::vector<std::unique_ptr<MapTile>> m_Map;

public:

	Map();

	std::vector<std::unique_ptr<MapTile>>::iterator begin();
	std::vector<std::unique_ptr<MapTile>>::iterator end();

	void SetMap(char* filename);

private:

	std::unique_ptr<MapTile> GetTileFromColor(BGRColor& color);
};