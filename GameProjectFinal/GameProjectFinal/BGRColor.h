#pragma once

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