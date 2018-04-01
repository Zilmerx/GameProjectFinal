#include "Game.h"
#include "Level1.h"

Game::Game()
{
	m_Context = new Level1;
}

bool Game::Initialize(HWND hwnd)
{
	Globals::get().game = this;
	m_Graphics.Initialize(hwnd);
	Globals::get().world = &m_World;
	m_Context->Initialize();
	Globals::get().camera->SetHandlers(m_Context->GetInputManager());

	return true;
}

void Game::Shutdown()
{
	m_Context->Shutdown();
	m_Graphics.Shutdown();
}

bool Game::Frame()
{
	m_Context->ProcessInputs();

	return m_Graphics.Render();
}