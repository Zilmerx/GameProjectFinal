#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>
#include <memory>
#include "Object.h"
#include "InputManager.h"
#include "Settings.h"
#include "RessourceManager.h"

class Graphics;

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class BaseContext
{
protected:

	Graphics* m_Parent;
	InputManager* m_Manager;

public:

	std::vector<std::vector<std::unique_ptr<Object>>> m_Objects;

	BaseContext(size_t ObjectVectorSize, Graphics* parent) :
		m_Objects{ ObjectVectorSize },
		m_Manager{ nullptr },
		m_Parent{ parent }
	{}

	~BaseContext() {}
	
	void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
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

	void ProcessInputs()
	{
		m_Manager->CheckEvents();
	}

	void Shutdown()
	{
		for (auto& vec : m_Objects)
		{
			for (auto& ptr : vec)
			{
				ptr->Shutdown();
			}
		}
	}

private:

	virtual void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) = 0;
};