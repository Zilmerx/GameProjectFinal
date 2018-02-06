#pragma once

#include <vector>
#include <memory>

#include "Mobile.h"

class CharacterContainer : public std::vector<std::unique_ptr<Mobile>>
{
	
public:

	std::unique_ptr<Mobile>& Get(Point2D<unsigned int> point)
	{
		for (std::unique_ptr<Mobile>& mob : *this)
		{
			if (point == mob->GetGridPosition())
			{
				return mob;
			}
		}

		return std::unique_ptr<Mobile>(nullptr);
	}
};