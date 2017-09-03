
#include "MapTile.h"

MapTile::MapTile(Model2D* model) :
	Object(MOVETYPE::DYNAMIC, model)
{
}

double MapTile::cost()
{
	return 1;
}