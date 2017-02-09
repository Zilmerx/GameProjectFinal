#pragma once

#include "Position.h"

template<class T>
class MyRect
{
	using value_type = T;
	using point_type = Point2D<value_type>;

	point_type TopLeft;
	point_type BotRight;

public:

	MyRect() :
		TopLeft{ 0,0 },
		BotRight{ 1,1 }
	{
	}

	MyRect(Point2D<value_type> TopLeft, Point2D<value_type> BotRight ) :
		TopLeft{ TopLeft },
		BotRight{ BotRight }
	{
	}

	Point2D<value_type> topLeft()
	{
		return BotRight.x - TopLeft.x;
	}

	Point2D<value_type> botRight()
	{
		return BotRight.y - TopLeft.y;
	}

	value_type width()
	{
		return BotRight.x - TopLeft.x;
	}

	value_type height()
	{
		return BotRight.y - TopLeft.y;
	}
};