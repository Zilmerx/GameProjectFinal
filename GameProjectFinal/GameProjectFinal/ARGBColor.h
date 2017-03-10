#pragma once

struct ARGBColor
{
	using value_type = unsigned char;

	value_type alpha;
	value_type red;
	value_type green;
	value_type blue;

	ARGBColor();

	ARGBColor(value_type alpha, value_type red, value_type green, value_type blue);

	bool operator==(const ARGBColor& rhs) { return alpha == rhs.alpha && red == rhs.red && green == rhs.green && blue == rhs.blue; }
};