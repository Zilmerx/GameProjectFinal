
#include "BaseContext.h"

#include "SystemClass.h"
#include "ResourceManager.h"
#include "Settings.h"


BaseContext::BaseContext(Graphics* parent) :
	m_Manager{ },
	m_Parent{ parent }
{
}

BaseContext::~BaseContext() 
{
}

void BaseContext::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	ResourceManager::get().Reset();

	m_Manager.addHandler<OnPressEvent>(Keys::ESCAPE,
		[]()
	{
		Globals::get().Shutdown = true;
	}
	);

	InitializeDef(device, deviceContext);
}

void BaseContext::ProcessInputs()
{
	m_Manager.checkEvents();
}

void BaseContext::Render(Graphics& gfx)
{
}

void BaseContext::Shutdown()
{
}

InputManager& BaseContext::GetInputManager()
{
	return m_Manager;
}