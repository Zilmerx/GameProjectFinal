#pragma once

#include <array>
#include <utility>

class ByteAmount
{
	size_t _amount;

public:

	constexpr ByteAmount(size_t amount);

	constexpr ByteAmount(const ByteAmount& byte_amount);

	constexpr size_t amount() const;


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

	constexpr operator size_t() const;
};
