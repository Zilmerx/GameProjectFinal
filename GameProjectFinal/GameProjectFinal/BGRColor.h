#pragma once

struct BGRColor
{
	using value_type = unsigned char;

	value_type blue;
	value_type green;
	value_type red;

	BGRColor();

	BGRColor(value_type blue, value_type green, value_type red);

	bool operator==(const BGRColor& rhs) { return blue == rhs.blue && green == rhs.green && red == rhs.red; }
};