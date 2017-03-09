#pragma once

template<class T>
struct Point3D;

#include "Point3D.h"

template<class T>
struct Point2D
{
	using value_type = T;

	value_type x, y;

	Point2D() :
		x{ 0 },
		y{ 0 }
	{
	}

	Point2D(value_type x, value_type y) :
		x{ x },
		y{ y }
	{
	}

	Point2D(Point3D<T> pos) :
		x{ pos.x },
		y{ pos.y }
	{
	}
};