
#include "BaseContext.h"

#include "SystemClass.h"
#include "ResourceManager.h"
#include "Settings.h"


BaseContext::BaseContext()
{
}

BaseContext::~BaseContext() 
{
}

void BaseContext::Initialize()
{
	ResourceManager::get().Reset();

	m_Manager.addHandler<OnPressEvent>(Keys::ESCAPE,
		[]()
	{
		Globals::get().Shutdown = true;
	}
	);

	InitializeDef();
}

void BaseContext::ProcessInputs()
{
	m_Manager.checkEvents();
}

void BaseContext::Shutdown()
{
}

InputManager& BaseContext::GetInputManager()
{
	return m_Manager;
}