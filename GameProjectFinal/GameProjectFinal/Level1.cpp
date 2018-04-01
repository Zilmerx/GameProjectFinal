#include "Level1.h"
#include "Settings.h"
#include "World.h"


Level1::Level1()
{
}

void Level1::InitializeMap()
{
	ResourceManager::get().Make("../GameProjectFinal/Resources/Skins/stone01.tga");
	ResourceManager::get().Make("../GameProjectFinal/Resources/Skins/MT-GR-02.tga");
	ResourceManager::get().Make("../GameProjectFinal/Resources/Skins/UNUSED_DEBUGE.tga");
	ResourceManager::get().Make("../GameProjectFinal/Resources/Skins/DEBUG_RED_SQUARE.tga");

	Globals::get().world->m_Map.SetMap("../GameProjectFinal/Resources/Maps/DebugMap.bmp");
}

void Level1::InitializeCharacters()
{
	ResourceManager::get().Make("../GameProjectFinal/Resources/Skins/Perso1.tga");

	std::unique_ptr<PlayerMobile> mob = std::make_unique<PlayerMobile>();

	mob->SetPosition(5, 5.5);

	Globals::get().world->m_Characters.push_back(std::move(mob));
}