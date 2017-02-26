#pragma once

struct ARGBColor
{
	using value_type = unsigned char;

	value_type alpha;
	value_type red;
	value_type green;
	value_type blue;

	ARGBColor() :
		alpha{ 0 },
		red{ 0 },
		green{ 0 },
		blue{ 0 }
	{
	}

	ARGBColor(value_type alpha, value_type red, value_type green, value_type blue) :
		alpha{ alpha },
		red{ red },
		green{ green },
		blue{ blue }
	{
	}

	bool operator==(const ARGBColor& rhs) { return alpha == rhs.alpha && red == rhs.red && green == rhs.green && blue == rhs.blue; }
};