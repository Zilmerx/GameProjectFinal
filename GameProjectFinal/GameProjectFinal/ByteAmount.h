#pragma once

#include <array>
#include <utility>

class ByteAmount
{
	unsigned int _amount;

public:

	constexpr ByteAmount(unsigned int amount);

	constexpr ByteAmount(const ByteAmount& byte_amount);

	constexpr unsigned int amount() const;


	// OPERATOR OVERLOADS

	// ASSIGNMENT

	ByteAmount& operator=(const ByteAmount& other);

	ByteAmount& operator=(ByteAmount&& other);

	// MODIFICATION

	ByteAmount& operator++();

	ByteAmount operator++(int);

	ByteAmount& operator--();

	ByteAmount operator--(int);

	ByteAmount& operator+=(const ByteAmount& rhs);

	friend ByteAmount operator+(ByteAmount lhs, const ByteAmount& rhs);

	ByteAmount& operator-=(const ByteAmount& rhs);

	friend ByteAmount operator-(ByteAmount lhs, const ByteAmount& rhs);

	ByteAmount& operator*=(const ByteAmount& rhs);

	friend ByteAmount operator*(ByteAmount lhs, const ByteAmount& rhs);

	ByteAmount& operator/=(const ByteAmount& rhs);

	friend ByteAmount operator/(ByteAmount lhs, const ByteAmount& rhs);

	// COMPARISON

	constexpr bool operator< (const ByteAmount& rhs) const { return _amount < rhs._amount; }
	constexpr bool operator> (const ByteAmount& rhs) const { return !(this->operator<(rhs)); }
	constexpr bool operator<=(const ByteAmount& rhs) const { return !(*this > rhs); }
	constexpr bool operator>=(const ByteAmount& rhs) const { return !(*this < rhs); }

	constexpr bool operator==(const ByteAmount& rhs) const { return _amount == rhs._amount; }
	constexpr bool operator!=(const ByteAmount& rhs) const { return !(*this == rhs); }

	constexpr operator unsigned int() const;
};
