#pragma once

template<class T>
class Point3D;

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


template<class T>
struct Point3D
{
	using value_type = T;

	value_type x, y, z;

	Point3D() :
		x{ 0 },
		y{ 0 },
		z{ 0 }
	{
	}

	Point3D(value_type x, value_type y, value_type z) :
		x{ x },
		y{ y },
		z{ z }
	{
	}

	Point3D(Point2D<T> pos, value_type z) :
		x{ pos.x },
		y{ pos.y },
		z{ z }
	{
	}
};