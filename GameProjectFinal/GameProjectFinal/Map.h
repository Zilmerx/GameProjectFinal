#pragma once

#include <vector>
#include <memory>

#include "AllMapTileDefs.h"

#include "BGRColor.h"
#include "Exception.h"

#include "Point2D.h"

class Map
{
	std::vector<std::unique_ptr<MapTile>> m_Map;

	unsigned int width;
	unsigned int height;

public:

	Map();

	std::vector<std::unique_ptr<MapTile>>::iterator begin();
	std::vector<std::unique_ptr<MapTile>>::iterator end();

	void SetMap(char* filename);

	void SetTile(Point2D<unsigned int> pos, std::unique_ptr<MapTile>&& newtile)
	{
		auto& tile = Get(pos);
		newtile->SetGridPosition(pos.x, pos.y);
		tile.swap(std::move(newtile));
	}

	std::unique_ptr<MapTile>& Get(Point2D<unsigned int> point)
	{
		if ((point.x > height-1) || (point.y > width-1))
		{
			THROW_EXCEPTION(OutOfBoundsException, L"Out of bounds")
		}
		return m_Map[(height * point.y) + point.x];
	}

	unsigned int getWidth()
	{
		return width;
	}

	unsigned int getHeight()
	{
		return height;
	}

private:

	std::unique_ptr<MapTile> GetTileFromColor(BGRColor& color);
};