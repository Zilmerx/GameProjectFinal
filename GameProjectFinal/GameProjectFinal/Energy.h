#pragma once

#include "LimitedT.h"

using Energy_T = unsigned int;

class Energy : public LimitedT<unsigned int>
{
public:

	Energy();

	Energy(Energy_T value);
};