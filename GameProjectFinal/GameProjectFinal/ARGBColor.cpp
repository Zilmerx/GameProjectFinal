
#include "ARGBColor.h"

ARGBColor::ARGBColor() :
	alpha{ 0 },
	red{ 0 },
	green{ 0 },
	blue{ 0 }
{
}

ARGBColor::ARGBColor(value_type alpha, value_type red, value_type green, value_type blue) :
	alpha{ alpha },
	red{ red },
	green{ green },
	blue{ blue }
{
}