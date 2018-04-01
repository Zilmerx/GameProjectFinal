#pragma once

#include "InputManager.h"
#include "Graphics.h"
#include "World.h"


class Game
{
	InputManager m_Inputs;
	Graphics m_Graphics;
	World m_World;
	BaseContext* m_Context;

public:

	Game();

	bool Initialize(HWND);
	void Shutdown();

	bool Frame();

	template<class ContextType>
	bool SwitchContext()
	{
		m_Context->Shutdown();

		delete m_Context;

		m_Context = new ContextType{};
		if (!m_Context)
		{
			return false;
		}

		// Initialize the model object.
		m_Context->Initialize();
		Globals::get().context = m_Context;

		Globals::get().camera->SetHandlers(m_Context->GetInputManager());

		return true;
	}
};