
#include "ByteAmount.h"

constexpr ByteAmount::ByteAmount(unsigned int amount) :
	_amount{ amount }
{
}

constexpr ByteAmount::ByteAmount(const ByteAmount& byte_amount) :
	_amount{ byte_amount._amount }
{
}

constexpr unsigned int ByteAmount::amount() const
{
	return _amount;
}


// OPERATOR OVERLOADS

// ASSIGNMENT

ByteAmount& ByteAmount::operator=(const ByteAmount& other)
{
	if (this != &other)
	{
		_amount = other._amount;
	}
	return *this;
}

ByteAmount& ByteAmount::operator=(ByteAmount&& other)
{
	_amount = std::exchange(other._amount, 0);
	return *this;
}

// MODIFICATION

ByteAmount& ByteAmount::operator++()
{
	_amount = _amount + 1;
	return *this;
}

ByteAmount ByteAmount::operator++(int)
{
	ByteAmount tmp(*this);
	operator++();
	return tmp;
}

ByteAmount& ByteAmount::operator--()
{
	_amount = _amount - 1;
	return *this;
}

ByteAmount ByteAmount::operator--(int)
{
	ByteAmount tmp(*this);
	operator--();
	return tmp;
}

ByteAmount& ByteAmount::operator+=(const ByteAmount& rhs)
{
	_amount = _amount + rhs._amount;
	return *this;
}

ByteAmount operator+(ByteAmount lhs, const ByteAmount& rhs)
{
	lhs += rhs;
	return lhs;
}

ByteAmount& ByteAmount::operator-=(const ByteAmount& rhs)
{
	_amount = _amount - rhs._amount;
	return *this;
}

ByteAmount operator-(ByteAmount lhs, const ByteAmount& rhs)
{
	lhs -= rhs;
	return lhs;
}

ByteAmount& ByteAmount::operator*=(const ByteAmount& rhs)
{
	_amount = _amount * rhs._amount;
	return *this;
}

ByteAmount operator*(ByteAmount lhs, const ByteAmount& rhs)
{
	lhs *= rhs;
	return lhs;
}

ByteAmount& ByteAmount::operator/=(const ByteAmount& rhs)
{
	_amount = _amount / rhs._amount;
	return *this;
}

ByteAmount operator/(ByteAmount lhs, const ByteAmount& rhs)
{
	lhs /= rhs;
	return lhs;
}

// COMPARISON

constexpr ByteAmount::operator unsigned int() const { return _amount; }
