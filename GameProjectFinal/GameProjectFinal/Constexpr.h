#pragma once


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