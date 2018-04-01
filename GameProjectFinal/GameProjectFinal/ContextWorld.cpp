
#include "ContextMenu.h"
#include "ContextWorld.h"

#include "Debug.h"

#include "InputManager.h"
#include "ScreenSize.h"
#include "AStarPathfinding.h"

#include "Settings.h"
#include "Game.h"

ContextWorld::ContextWorld()
{
}

ContextWorld::~ContextWorld()
{
}

void ContextWorld::InitializeDef()
{
	Globals::get().camera->SetPosition(3.0, 3.0);

	InitializeControls();

	InitializeMap();

	InitializeCharacters();
}

void ContextWorld::InitializeControls()
{
	m_Manager.addHandler<OnPressEvent>(Keys::KEY_O,
		[&]()
	{
		Globals::get().game->SwitchContext<ContextMenu>();
	}
	);

	m_Manager.addHandler<OnPressEvent>(Keys::LBUTTON,
		[&]()
	{

	});
}

void ContextWorld::Shutdown()
{

}