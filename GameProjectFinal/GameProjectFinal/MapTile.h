#pragma once

#include "Object.h"
#include "MovementCost.h"

class MapTile : public Object, public MovementCost
{
protected:

	MapTile(Model2D* model);

public:

	MapTile(const MapTile&) = default;

	virtual double cost() override;

	inline bool operator==(const MapTile& rhs) { return GetGridPosition() == rhs.GetGridPosition(); };

};