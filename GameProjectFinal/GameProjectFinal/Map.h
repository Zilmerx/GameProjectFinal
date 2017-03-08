#pragma once

#include <vector>
#include <memory>

#include "AllMapTileDefs.h"

#include "BGRColor.h"
#include "Exception.h"



class Map
{
	size_t width;
	size_t height;
	std::vector<std::unique_ptr<MapTile>> m_Map;

public:

	Map();

	std::vector<std::unique_ptr<MapTile>>::iterator begin();
	std::vector<std::unique_ptr<MapTile>>::iterator end();

	void SetMap(char* filename);

	std::unique_ptr<MapTile>& Get(Point2D<size_t> point)
	{
		if ((point.x < 0 || point.x > height-1)
		 || (point.y < 0 || point.y > width-1))
		{
			THROW_EXCEPTION(OutOfBoundsException, L"Out of bounds")
		}
		return m_Map[(height * point.y) + point.x];
	}

private:

	std::unique_ptr<MapTile> GetTileFromColor(BGRColor& color);
};