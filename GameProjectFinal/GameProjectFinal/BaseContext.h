#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>
#include <memory>

#include "InputManager.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class BaseContext
{
protected:

	InputManager m_Manager;

public:

	BaseContext();

	~BaseContext();
	
	void Initialize();

	void ProcessInputs();

	virtual void Shutdown();

	InputManager& GetInputManager();

private:

	virtual void InitializeDef() = 0;
};