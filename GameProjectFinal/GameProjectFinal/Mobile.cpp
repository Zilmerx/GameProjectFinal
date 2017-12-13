
#include "Mobile.h"
#include "ResourceManager.h"

Mobile::Mobile() :
	Object(MOVETYPE::DYNAMIC, ResourceManager::get().Get("../GameProjectFinal/Resources/Characters/Personnages/Perso1.tga"))
{
}