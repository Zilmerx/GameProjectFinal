
#include "ContextMenu.h"
#include "ContextWorld.h"

#include "InputManager.h"
#include "ScreenSize.h"
#include "AStarPathfinding.h"

ContextWorld::ContextWorld(Graphics* parent) :
	BaseContext{ parent }
{
}

ContextWorld::~ContextWorld()
{
}

void ContextWorld::InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	m_Manager->addHandler(OnPressEvent(Keys::KEY_O,
		[&]()
	{
		m_Parent->SwitchContext<ContextMenu>();
	}
	));

	m_Manager->addHandler(OnPressEvent(Keys::LBUTTON,
		[&]()
	{
		Point2D<size_t> GridPosition = m_Manager->GetGridCursorPos();

		static std::unique_ptr<MapTile>* begin;
		static std::unique_ptr<MapTile>* end;
		/*
		try
		{
			std::unique_ptr<MapTile>& tile = Get<MapTile>(GridPosition);
			std::unique_ptr<MapTile> newTile = std::make_unique<Stones>();

			auto pos = tile->GetPosition();
			newTile->SetPosition(pos.x, pos.y, pos.z);
			std::swap(*tile, *newTile.get());
		}
		catch (...)
		{

		}*/

		if (begin == nullptr)
		{
			try
			{
				begin = &Get<MapTile>(m_Manager->GetGridCursorPos());
			}
			catch (...)
			{
			}
		}
		else if (end == nullptr)
		{
			try
			{
				end = &Get<MapTile>(m_Manager->GetGridCursorPos());

				AStarPathfinding pathfinder{ &GetMap() };
				std::vector<MapTile*> path = pathfinder.FindPath(begin->get(), end->get());

				for (auto& tile : path)
				{
					std::unique_ptr<MapTile> newTile = std::make_unique<Stones>();

					auto pos = tile->GetPosition();
					newTile->SetPosition(pos.x, pos.y, pos.z);
					std::swap(*tile, *newTile.get());
				}
			}
			catch (...)
			{
			}
		}
	}));

	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");
	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");
	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/UNUSED_DEBUGE.tga");
	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/DEBUG_RED_SQUARE.tga");

	m_Map.SetMap("../GameProjectFinal/Resources/Maps/BitMaps/DebugMap.bmp");
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