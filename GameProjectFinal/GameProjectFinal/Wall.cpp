
#include "Wall.h"

Wall::Wall() :
	MapTile(ResourceManager::get().Get("../GameProjectFinal/Resources/Skins/MT-GR-02.tga"))
{
}

double Wall::cost()
{
	return 1000;
}