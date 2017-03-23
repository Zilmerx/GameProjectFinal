
#include "MapTile.h"

MapTile::MapTile(Model2D* model) :
	Object(model)
{
}

double MapTile::cost()
{
	return 1;
}