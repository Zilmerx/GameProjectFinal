
#include <fstream>

#include "Bitmap.h"
#include "Map.h"

Map::Map()
{
}

std::vector<std::unique_ptr<MapTile>>::iterator Map::begin()
{
	return m_Map.begin();
}

std::vector<std::unique_ptr<MapTile>>::iterator Map::end()
{
	return m_Map.end();
}

void Map::SetMap(std::string filename)
{
	Bitmap bits;
	bits.LoadFrom(filename);

	// Resize the map to the size of the map to come.
	m_Map.clear();
	m_Map.reserve(bits.size());

	for (unsigned int y = 0; y <bits.m_Height; y++)
	{
		for (unsigned int x = 0; x < bits.m_Width; x++)
		{
			std::unique_ptr<MapTile> tile = GetTileFromColor(bits.m_Bits[(y*bits.m_Width)+x]);

			tile->SetGridPosition(x, y);

			m_Map.push_back(std::move(tile));
		}
	}
}

std::unique_ptr<MapTile> Map::GetTileFromColor(BGRColor& color)
{
	if (color == BGRColor(255, 255, 255))
	{
		return std::make_unique<DebugRedSquare>();
	}
	else if (color == BGRColor{ 0, 255, 0 })
	{
		return std::make_unique<Grass>();
	}
	else if (color == BGRColor{ 150, 150, 150 })
	{
		return std::make_unique<Stones>();
	}
	else if (color == BGRColor{ 128, 128, 128 })
	{
		return std::make_unique<Wall>();
	}


	return std::make_unique<EmptyTile>();
}