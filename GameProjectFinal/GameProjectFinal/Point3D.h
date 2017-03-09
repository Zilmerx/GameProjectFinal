#pragma once

template<class T>
struct Point2D;

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

	template<class U>
	Point3D(Point2D<U> pos, value_type z) :
		x{ pos.x },
		y{ pos.y },
		z{ z }
	{
	}
};