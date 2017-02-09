#pragma once

#include "ByteTraits.h"
#include "ByteAmount.h"

constexpr ByteAmount operator"" _O(unsigned long long amount)
{
	return ByteAmount{ byte_traits<Byte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _Ko(unsigned long long amount)
{
	return ByteAmount{ byte_traits<KiloByte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _Mo(unsigned long long amount)
{
	return ByteAmount{ byte_traits<MegaByte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _Go(unsigned long long amount)
{
	return ByteAmount{ byte_traits<GigaByte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _To(unsigned long long amount)
{
	return ByteAmount{ byte_traits<TeraByte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _Po(unsigned long long amount)
{
	return ByteAmount{ byte_traits<PetaByte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _Eo(unsigned long long amount)
{
	return ByteAmount{ byte_traits<ExaByte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _Zo(unsigned long long amount)
{
	return ByteAmount{ byte_traits<ZetaByte>::to_neutral(amount) };
}

constexpr ByteAmount operator"" _Yo(unsigned long long amount)
{
	return ByteAmount{ byte_traits<YottaByte>::to_neutral(amount) };
}