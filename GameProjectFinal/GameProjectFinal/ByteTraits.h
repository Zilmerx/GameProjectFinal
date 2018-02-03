#pragma once

#include "Constexpr.h"

#include "ByteTypes.h"

template<class>
struct byte_traits;

template<>
struct byte_traits<Byte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 0>::value;
	}
};

template<>
struct byte_traits<KiloByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 1>::value;
	}
};

template<>
struct byte_traits<MegaByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 2>::value;
	}
};

template<>
struct byte_traits<GigaByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 3>::value;
	}
};

template<>
struct byte_traits<TeraByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 4>::value;
	}
};

template<>
struct byte_traits<PetaByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 5>::value;
	}
};

template<>
struct byte_traits<ExaByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 6>::value;
	}
};

template<>
struct byte_traits<ZetaByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 7>::value;
	}
};

template<>
struct byte_traits<YottaByte>
{
	static constexpr unsigned int to_neutral(unsigned int val)
	{
		return val * _pow<_pow<2, 10>::value, 8>::value;
	}
};