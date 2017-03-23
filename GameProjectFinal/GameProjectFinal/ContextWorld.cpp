
#include "ContextMenu.h"
#include "ContextWorld.h"

#include "MouseManager.h"
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
	m_Manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_O>(
		[this](SHORT)
	{
		m_Parent->SwitchContext<ContextMenu>();
	}
	));

	m_Manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::LBUTTON>(
		[this](SHORT)
	{
		Point2D<size_t> GridPosition = MouseManager::get().GetGridCursorPos();

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
			begin = &Get<MapTile>(Point2D<size_t>(GridPosition.x, GridPosition.y));
		}
		else if (end == nullptr)
		{
			end = &Get<MapTile>(Point2D<size_t>(GridPosition.x, GridPosition.y));
		}
		else
		{
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