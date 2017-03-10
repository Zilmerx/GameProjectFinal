
#include "Energy.h"

Energy::Energy() :
	LimitedT{}
{
}

Energy::Energy(Energy_T value) :
	LimitedT{ 0, value, value }
{
}