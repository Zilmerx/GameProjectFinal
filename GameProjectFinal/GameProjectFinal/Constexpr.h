#pragma once

#include <limits>

template <int A, int B>
struct _pow
{
	static constexpr unsigned long long value = A * _pow<A, B - 1>::value;
};
template <int A>
struct _pow<A, 0>
{
	static constexpr unsigned long long value = 1;
};


template<class T>
T constexpr sqrtNewtonRaphson(T x, T curr, T prev)
{
	return curr == prev
		? curr
		: sqrtNewtonRaphson(x, 0.5 * (curr + x / curr), curr);
}

template<class T>
double constexpr _sqrt(T x)
{
	return x >= 0 && x < std::numeric_limits<T>::infinity()
		? sqrtNewtonRaphson<T>(x, x, 0)
		: std::numeric_limits<T>::quiet_NaN();
}