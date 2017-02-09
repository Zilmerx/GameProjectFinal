#pragma once

#include <utility>
#include "Settings.h"

class TileSize
{
public:

	using value_type = float;

private:

	value_type _amount;

public:

	constexpr TileSize(value_type amount) :
		_amount{ amount }
	{
	}

	constexpr TileSize(const TileSize& byte_amount) :
		_amount{ byte_amount._amount }
	{
	}

	value_type GetTileAmount() const
	{
		return _amount;
	}

	value_type GetSize() const
	{
		return _amount;
	}

	// OPERATOR OVERLOADS

	// ASSIGNMENT

	TileSize& operator=(const TileSize& other)
	{
		if (this != &other)
		{
			_amount = other._amount;
		}
		return *this;
	}

	TileSize& operator=(TileSize&& other)
	{
		_amount = std::exchange(other._amount, 0);
		return *this;
	}

	// MODIFICATION

	TileSize& operator++()
	{
		_amount = _amount + 1;
		return *this;
	}

	TileSize operator++(int)
	{
		TileSize tmp(*this);
		operator++();
		return tmp;
	}

	TileSize& operator--()
	{
		_amount = _amount - 1;
		return *this;
	}

	TileSize operator--(int)
	{
		TileSize tmp(*this);
		operator--();
		return tmp;
	}

	TileSize& operator+=(const TileSize& rhs)
	{
		_amount = _amount + rhs._amount;
		return *this;
	}

	friend TileSize operator+(TileSize lhs, const TileSize& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	TileSize& operator-=(const TileSize& rhs)
	{
		_amount = _amount - rhs._amount;
		return *this;
	}

	friend TileSize operator-(TileSize lhs, const TileSize& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	TileSize& operator*=(const TileSize& rhs)
	{
		_amount = _amount * rhs._amount;
		return *this;
	}

	friend TileSize operator*(TileSize lhs, const TileSize& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	TileSize& operator/=(const TileSize& rhs)
	{
		_amount = _amount / rhs._amount;
		return *this;
	}

	friend TileSize operator/(TileSize lhs, const TileSize& rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	// COMPARISON

	constexpr bool operator< (const TileSize& rhs) { return _amount < rhs._amount; }
	constexpr bool operator> (const TileSize& rhs) { return !(this->operator<(rhs)); }
	constexpr bool operator<=(const TileSize& rhs) { return !(*this > rhs); }
	constexpr bool operator>=(const TileSize& rhs) { return !(*this < rhs); }

	constexpr bool operator==(const TileSize& rhs) { return this->_amount == rhs._amount; }
	constexpr bool operator!=(const TileSize& rhs) { return !(*this == rhs); }


	constexpr operator value_type() const
	{
		return _amount;
	}
};