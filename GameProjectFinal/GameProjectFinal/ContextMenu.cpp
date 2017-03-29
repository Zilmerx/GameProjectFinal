
#include "ContextMenu.h"
#include "ContextWorld.h"


ContextMenu::ContextMenu(Graphics* parent) :
	BaseContext{ parent }
{
}

ContextMenu::~ContextMenu()
{
}

void ContextMenu::InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	m_Manager->addHandler(OnPressEvent(Keys::KEY_P,
		[&]()
	{
		m_Parent->SwitchContext<ContextWorld>();
	}
	));

	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");
	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");

	for (int y = -3; y <= 3; y++) // -3 to 3, 7 values.
	{
		for (int x = -3; x <= 3; x++) // -3 to 3, 7 values.
		{
			std::unique_ptr<MapTile> obj;
			if (x % 2) // Is Even
			{
				obj = std::make_unique<Stones>(); // Stones
			}
			else       // Is Odd
			{
				obj = std::make_unique<Grass>(); // Grass
			}

			obj->SetGridPosition(x, y);

			obj->Initialize();

			m_Map.push_back(std::move(obj));
		}
	}
}

void ContextMenu::Render(Graphics& gfx)
{
	for (auto& tile : m_Map)
	{
		gfx.RenderObject(*tile);
	}
}

void ContextMenu::Shutdown()
{

}