#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>
#include <memory>
#include "Object.h"
#include "InputManager.h"
#include "Settings.h"
#include "ResourceManager.h"

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

	BaseContext(size_t ObjectVectorSize, Graphics* parent) :
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

	virtual void Render(Graphics& gfx)
	{

	}

	virtual void Shutdown()
	{

	}

	InputManager* GetInputManager()
	{
		return m_Manager;
	}

private:

	virtual void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) = 0;
};