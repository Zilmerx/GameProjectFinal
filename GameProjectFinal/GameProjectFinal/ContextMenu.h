#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"

#include "MapTile.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextMenu : public BaseContext
{
	std::vector<std::unique_ptr<MapTile>> m_Map;
	std::vector<std::unique_ptr<Object>> m_Characters;

public:

	ContextMenu(Graphics* parent) :
		BaseContext{ 2 , parent }
	{
	}

	~ContextMenu() {}

	void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override;

	virtual void Render(Graphics& gfx) override;

	virtual void Shutdown() override;

};