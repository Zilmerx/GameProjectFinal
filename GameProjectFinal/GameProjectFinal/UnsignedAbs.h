#pragma once

template< typename T >
T UnsignedAbs(const T& lhs, const T& rhs) {
	return lhs>rhs ? lhs - rhs : rhs - lhs;
}