#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"

#include "Map.h"
#include "CharacterContainer.h"
#include "PlayerMobile.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextWorld : public BaseContext
{
public:

	ContextWorld();

	~ContextWorld();

	void InitializeDef() override;

	void InitializeControls();

	//

	virtual void InitializeMap() = 0;

	virtual void InitializeCharacters() = 0;

	//

	virtual void Shutdown() override;
};