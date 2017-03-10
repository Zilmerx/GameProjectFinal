#include "HP.h"


HP::HP() :
	LimitedT{}
{
}

HP::HP(HP_T value) :
	LimitedT{ 0, value, value }
{
}

bool HP::IsInjured() const
{
	return GetPercentage() < GetInjuredCriticalPercentage();
}

bool HP::IsDead() const
{
	return GetValue() == GetMin();
}

constexpr double HP::GetInjuredCriticalPercentage()
{
	return 0.1;
}