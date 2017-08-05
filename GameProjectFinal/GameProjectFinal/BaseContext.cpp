
#include "BaseContext.h"

#include "SystemClass.h"
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

	m_Manager->addHandler<OnPressEvent>(Keys::ESCAPE,
		[]()
	{
		Globals::get().Shutdown = true;
	}
	);

	InitializeDef(device, deviceContext);

	// ResourceManager::get().CleanDuplicates(); // Emplace function from std::map already checks for duplicates.
}

void BaseContext::ProcessInputs()
{
	m_Manager->checkEvents();
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