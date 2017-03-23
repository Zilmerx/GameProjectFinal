#pragma once

template<class T>
struct Point3D;

#include "Point3D.h"
#include "Direction.h"

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

	template<class U>
	Point2D(const Point2D<U>& pos) :
		x{ (T)pos.x },
		y{ (T)pos.y }
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

	inline bool operator==(const Point2D& rhs) { return x == rhs.x && y == rhs.y };

	friend Point2D operator+(Point2D lhs, const Point2D& rhs)
	{
		return Point2D<T>{lhs.x + rhs.x, lhs.y + rhs.y};
	}

};