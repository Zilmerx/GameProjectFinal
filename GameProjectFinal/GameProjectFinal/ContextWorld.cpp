
#include "ContextMenu.h"
#include "ContextWorld.h"

#include "Debug.h"

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
	m_Parent->SetCameraPosition(Position(3, 3));

	InitializeControls();

	InitializeMap(device, deviceContext);

	InitializeCharacters(device, deviceContext);
}

void ContextWorld::InitializeControls()
{
	m_Manager.addHandler<OnPressEvent>(Keys::KEY_O,
		[&]()
	{
		m_Parent->SwitchContext<ContextMenu>();
	}
	);

	m_Manager.addHandler<OnPressEvent>(Keys::LBUTTON,
		[&]()
	{

	});
}

void ContextWorld::Render(Graphics& gfx)
{
	// Render from front to the back.

	for (auto& character : m_Characters)
	{
		gfx.RenderObject(*character);
	}

	for (auto& tile : m_Map)
	{
		gfx.RenderObject(*tile);
	}
}

void ContextWorld::Shutdown()
{

}