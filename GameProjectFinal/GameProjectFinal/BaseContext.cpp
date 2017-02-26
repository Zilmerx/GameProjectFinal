
#include "BaseContext.h"

#include "ResourceManager.h"
#include "Settings.h"


BaseContext::BaseContext(Graphics* parent) :
	m_Manager{ nullptr },
	m_Parent{ parent }
{
}

BaseContext::~BaseContext() 
{
}

void BaseContext::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	ResourceManager::get().Reset();

	if (m_Manager == nullptr)
	{
		m_Manager = new InputManager{};
	}

	m_Manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::ESCAPE>(
		[](SHORT)
	{
		Settings::get().QUIT = true;
	}
	));

	InitializeDef(device, deviceContext);
}

void BaseContext::ProcessInputs()
{
	m_Manager->CheckEvents();
}

void BaseContext::Render(Graphics& gfx)
{
}

void BaseContext::Shutdown()
{
}

InputManager* BaseContext::GetInputManager()
{
	return m_Manager;
}