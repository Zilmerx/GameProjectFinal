
#include "MapTile.h"

MapTile::MapTile(Model2D* model) :
	Object(MOVETYPE::STATIC, model)
{
}

double MapTile::cost()
{
	return 1;
}