#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"

#include "Map.h"

#include "Grass.h"
#include "Stones.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextWorld : public BaseContext
{
	Map m_Map;
	std::vector<std::unique_ptr<Object>> m_Characters;

public:

	ContextWorld(Graphics* parent) :
		BaseContext{ 2 , parent }
	{
	}
	~ContextWorld() {}

	void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override;

	virtual void Render(Graphics& gfx) override;

	virtual void Shutdown() override;
};