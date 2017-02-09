#pragma once

#include <array>
#include <utility>

class ByteAmount
{
	size_t _amount;

public:

	constexpr ByteAmount(size_t amount) :
		_amount{ amount }
	{
	}

	constexpr ByteAmount(const ByteAmount& byte_amount) :
		_amount{ byte_amount._amount }
	{
	}

	constexpr size_t amount() const
	{
		return _amount;
	}


	// OPERATOR OVERLOADS

	// ASSIGNMENT

	ByteAmount& operator=(const ByteAmount& other)
	{
		if (this != &other)
		{
			_amount = other._amount;
		}
		return *this;
	}

	ByteAmount& operator=(ByteAmount&& other)
	{
		_amount = std::exchange(other._amount, 0);
		return *this;
	}

	// MODIFICATION

	ByteAmount& operator++()
	{
		_amount = _amount + 1;
		return *this;
	}

	ByteAmount operator++(int)
	{
		ByteAmount tmp(*this);
		operator++();
		return tmp;
	}

	ByteAmount& operator--()
	{
		_amount = _amount - 1;
		return *this;
	}

	ByteAmount operator--(int)
	{
		ByteAmount tmp(*this);
		operator--();
		return tmp;
	}

	ByteAmount& operator+=(const ByteAmount& rhs)
	{
		_amount = _amount + rhs._amount;
		return *this;
	}

	friend ByteAmount operator+(ByteAmount lhs, const ByteAmount& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	ByteAmount& operator-=(const ByteAmount& rhs)
	{
		_amount = _amount - rhs._amount;
		return *this;
	}

	friend ByteAmount operator-(ByteAmount lhs, const ByteAmount& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	ByteAmount& operator*=(const ByteAmount& rhs)
	{
		_amount = _amount * rhs._amount;
		return *this;
	}

	friend ByteAmount operator*(ByteAmount lhs, const ByteAmount& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	ByteAmount& operator/=(const ByteAmount& rhs)
	{
		_amount = _amount / rhs._amount;
		return *this;
	}

	friend ByteAmount operator/(ByteAmount lhs, const ByteAmount& rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	// COMPARISON

	constexpr bool operator< (const ByteAmount& rhs) { return _amount < rhs._amount; }
	constexpr bool operator> (const ByteAmount& rhs) { return !(this->operator<(rhs)); }
	constexpr bool operator<=(const ByteAmount& rhs) { return !(*this > rhs); }
	constexpr bool operator>=(const ByteAmount& rhs) { return !(*this < rhs); }

	constexpr bool operator==(const ByteAmount& rhs) { return this->_amount == rhs._amount; }
	constexpr bool operator!=(const ByteAmount& rhs) { return !(*this == rhs); }

	constexpr operator size_t() const { return _amount; }
};
