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

public:

	ContextMenu(Graphics* parent);

	~ContextMenu();

	void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override;

	virtual void Render(Graphics& gfx) override;

	virtual void Shutdown() override;

};