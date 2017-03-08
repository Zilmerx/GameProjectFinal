
#include "ContextMenu.h"
#include "ContextWorld.h"

#include "MouseManager.h"
#include "ScreenSize.h"

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
		Point2D<int> click = MouseManager::GetClientCursorPos();

		XMFLOAT3 cam = Globals::get().camera->GetPosition();
		cam.z = std::abs(cam.z);

		// Y part of the function is OK.
		int ScreenHeight = ScreenSize::get().height;
		auto HeightRatio = ScreenSize::get().HeightRatio();
		click.y = ScreenHeight - click.y;

		auto ScreenPercentY = (double)click.y / (double)ScreenHeight;

		auto YCorrection = -((cam.z * HeightRatio) / 2.0);

		auto GridPosY = ScreenPercentY * cam.z * HeightRatio;

		GridPosY = std::round(GridPosY + cam.y + YCorrection);


		// X part of the function is not.
		int ScreenWidth = ScreenSize::get().width;
		auto WidthRatio = ScreenSize::get().WidthRatio();

		auto ScreenPercentX = (double)click.x / (double)ScreenWidth;

		auto XCorrection = -((cam.z * WidthRatio) / 2.0);

		auto GridPosX = ScreenPercentX * cam.z * WidthRatio;

		GridPosX = std::round(GridPosX + cam.x + XCorrection);

		//

		Point2D<int> GridPosition{ (int)GridPosX, (int)GridPosY };

		try
		{
			std::unique_ptr<MapTile>& tile = Get<MapTile>(Point2D<size_t>(GridPosition.x, GridPosition.y));
			std::unique_ptr<MapTile> newTile = std::make_unique<Stones>();

			auto pos = tile->GetPosition();
			newTile->SetPosition(pos.x, pos.y, pos.z);
			tile.swap(newTile);
		}
		catch (OutOfBoundsException)
		{
		}
	}
	));

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