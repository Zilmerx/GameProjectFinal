#pragma once

#include "Object.h"
#include "HP.h"
#include "Energy.h"

class Mobile : public Object
{
public:

	HP m_HP;
	Energy m_Energy;
	
protected:

	Mobile();
	Mobile(const Mobile& other) = default;
};