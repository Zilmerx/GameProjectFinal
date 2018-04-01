
#include "ContextMenu.h"
#include "Level1.h"
#include "Singleton.h"
#include "Settings.h"
#include "Game.h"
#include "World.h"

ContextMenu::ContextMenu() :
	BaseContext{ }
{
}

ContextMenu::~ContextMenu()
{
}

void ContextMenu::InitializeDef()
{
	//Globals::get().camera->SetPosition(3.0, 3.0);

	m_Manager.addHandler<OnPressEvent>(Keys::KEY_P,
		[&]()
	{
		Globals::get().game->SwitchContext<Level1>();
	}
	);
}

void ContextMenu::Shutdown()
{

}