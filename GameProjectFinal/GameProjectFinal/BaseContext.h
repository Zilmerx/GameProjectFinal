#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>
#include <memory>

#include "Graphics.h"
#include "InputManager.h"

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

	BaseContext(Graphics* parent);

	~BaseContext();
	
	void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext);

	void ProcessInputs();

	virtual void Render(Graphics& gfx);

	virtual void Shutdown();

	InputManager* GetInputManager();

private:

	virtual void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) = 0;
};