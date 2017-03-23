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

	template<class U>
	Point3D(const Point3D<U>& pos) :
		x{ (T)pos.x },
		y{ (T)pos.y },
		z{ (T)pos.z }
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

	inline bool operator==(const Point3D& rhs) { return x == rhs.x && y == rhs.y && z == rhs.z; };

	friend Point3D operator+(Point3D lhs, const Point3D& rhs)
	{
		return Point3D<T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
	}

	double distance(Point3D other)
	{
		return sqrt(pow(x - other.x,2) + pow(y - other.y, 2) + pow(z - other.z, 2));
	}
};