#pragma once

#include <vector>
#include <fstream>
#include <memory>

#include "MapTile.h"

#include "Grass.h"
#include "Stones.h"
#include "Vide.h"

class Map
{
	std::vector<std::unique_ptr<MapTile>> m_Map;

	// Important not to change the position of the members of this class. Reinterpret_cast bizness.
	struct BGRColor
	{
		using value_type = unsigned char;

		value_type blue;
		value_type green;
		value_type red;

		BGRColor() :
			blue{ 0 },
			green{ 0 },
			red{ 0 }
		{
		}

		BGRColor(value_type blue, value_type green, value_type red) :
			blue{ blue },
			green{ green },
			red{ red }
		{
		}

		bool operator==(const BGRColor& rhs) { return blue == rhs.blue && green == rhs.green && red == rhs.red; }
	};

public:

	Map()
	{

	}

	auto begin()
	{
		return m_Map.begin();
	}

	auto end()
	{
		return m_Map.end();
	}

	void SetMap(char* filename)
	{
		std::ifstream input(filename, std::ios::in | std::ifstream::binary);

		// Extract info from the header.
		char header[54];

		input.read(header, 54);

		// Extract image height and width from header
		int width = *(int*)&header[18];
		int height = *(int*)&header[22];

		int padding = 0;

		// Calculate padding
		while ((width * 3 + padding) % 4 != 0)
		{
			padding++;
		}

		int size = width * height;

		// Compute new width, which includes padding
		int widthnew = width * 3 + padding;

		// Make a temporary vector to hold bitmap tile colors.
		std::vector<char> temp(size * 3);

		// Resize the map to the size of the map to come.
		m_Map.clear();
		m_Map.reserve(size);

		float half = ((float)size) / 2.0f;

		for (int y = 0; y <height; y++)
		{
			// Fill the vector with the colors from the bitmap.
			input.read(&temp[0], widthnew);

			// Retain width length of data, and swizzle RB component.
			// BMP stores in BGR format, my usecase needs RGB format
			for (int x = 0; x < width * 3; x += 3)
			{
				int index = (y * width * 3) + (x);
				BGRColor color;
				color.blue	= temp[x + 2];
				color.green = temp[x + 1];
				color.red	= temp[x + 0];

				std::unique_ptr<MapTile> tile = GetTileFromColor(color);

				tile->SetPosition(x/3, y);

				m_Map.push_back(std::move(tile));
			}
		}
	}

private:

	std::unique_ptr<MapTile> GetTileFromColor(BGRColor& color)
	{
		if (color == BGRColor{0, 255, 0})
		{
			return std::make_unique<Grass>();
		}
		else if (color == BGRColor{ 150, 150, 150 })
		{
			return std::make_unique<Stones>();
		}

		return std::make_unique<Tile_Vide>();
	}
};