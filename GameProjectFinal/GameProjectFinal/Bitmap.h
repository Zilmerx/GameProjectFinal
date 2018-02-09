#pragma once

#include <vector>
#include <string>>
#include "BGRColor.h"

struct Bitmap
{
	std::vector<BGRColor> m_Bits;

	unsigned int m_Width;
	unsigned int m_Height;

	Bitmap()
	{
	}

	size_t size()
	{
		return m_Width * m_Height;
	}

	void LoadFrom(std::string filename)
	{
		std::ifstream input(filename, std::ios::in | std::ifstream::binary);

		// Extract info from the header.
		char header[54];

		input.read(header, 54);

		// Extract image height and width from header
		m_Width = *(unsigned int*)&header[18];
		m_Height = *(unsigned int*)&header[22];

		int padding = 0;

		// Calculate padding
		while ((m_Width * 3 + padding) % 4 != 0)
		{
			padding++;
		}

		int size = m_Width * m_Height;

		// Make a temporary vector to hold bitmap tile colors.
		m_Bits = std::vector<BGRColor>(size);

		for (unsigned int y = 0; y <m_Height; y++)
		{
			// Fill the vector with the colors from the bitmap.
			input.read(reinterpret_cast<char*>(&m_Bits[y * m_Width]), (m_Width * 3) + padding);
		}
	}
};