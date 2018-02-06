#pragma once

#include "ContextWorld.h"


class Level1 : public ContextWorld
{

public:

	Level1(Graphics* parent) :
		ContextWorld{ parent }
	{
	}

private:

	virtual void InitializeMap(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override
	{
		ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");
		ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");
		ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/UNUSED_DEBUGE.tga");
		ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/DEBUG_RED_SQUARE.tga");

		m_Map.SetMap("../GameProjectFinal/Resources/Maps/BitMaps/DebugMap.bmp");
	}

	virtual void InitializeCharacters(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override
	{
		ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Characters/Personnages/Perso1.tga");

		std::unique_ptr<PlayerMobile> mob = std::make_unique<PlayerMobile>();

		mob->SetPosition(5, 5.5);

		m_Characters.push_back(std::move(mob));
	}
};