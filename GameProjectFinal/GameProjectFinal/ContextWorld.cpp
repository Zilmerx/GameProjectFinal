

#include "ContextWorld.h"
#include "Graphics.h"

void ContextWorld::InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	m_Manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_O>(
		[this](SHORT)
	{
		m_Parent->SwitchContext<ContextMenu>();
	}
	));

	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");
	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");
	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/UNUSED_DEBUGE.tga");

	m_Map.SetMap("../GameProjectFinal/Resources/Maps/BitMaps/map01.bmp");

	/*
	for (int y = -3; y <= 3; y++) // -3 to 3, 7 values.
	{
		for (int x = -3; x <= 3; x++) // -3 to 3, 7 values.
		{
			std::unique_ptr<MapTile> obj;
			if (x % 2) // Is Even
			{
				obj = std::make_unique<MapTile>(Stones()); // Stones
			}
			else       // Is Odd
			{
				obj = std::make_unique<MapTile>(Grass()); // Grass
			}

			obj->SetPosition(x, y);

			obj->Initialize();

			m_Map.push_back(std::move(obj));
		}
	}*/
}

void ContextWorld::Render(Graphics& gfx)
{
	for (auto& tile : m_Map)
	{
		gfx.RenderObject(*tile);
	}

	for (auto& character : m_Characters)
	{
		gfx.RenderObject(*character);
	}
}

void ContextWorld::Shutdown()
{

}