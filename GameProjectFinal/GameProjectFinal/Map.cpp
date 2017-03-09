
#include <fstream>

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

void Map::SetMap(char* filename)
{
	std::ifstream input(filename, std::ios::in | std::ifstream::binary);

	// Extract info from the header.
	char header[54];

	input.read(header, 54);

	// Extract image height and width from header
	width = *(size_t*)&header[18];
	height = *(size_t*)&header[22];

	int padding = 0;

	// Calculate padding
	while ((width * 3 + padding) % 4 != 0)
	{
		padding++;
	}

	int size = width * height;

	// Make a temporary vector to hold bitmap tile colors.
	std::vector<char> temp(size * 3);

	// Resize the map to the size of the map to come.
	m_Map.clear();
	m_Map.reserve(size);

	for (unsigned int y = 0; y <height; y++)
	{
		// Fill the vector with the colors from the bitmap.
		input.read(&temp[0], width * 3 + padding);

		// Retain width length of data, and swizzle RB component.
		for (unsigned int x = 0; x < width * 3; x += 3)
		{
			BGRColor color;
			color.blue = temp[x + 2];
			color.green = temp[x + 1];
			color.red = temp[x + 0];

			std::unique_ptr<MapTile> tile = GetTileFromColor(color);

			tile->SetGridPosition(x / 3, y);

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


	return std::make_unique<EmptyTile>();
}