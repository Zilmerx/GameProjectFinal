#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"


////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextMenu : public BaseContext
{
	std::vector<std::unique_ptr<Object>>* m_Map;
	std::vector<std::unique_ptr<Object>>* m_Characters;

public:

	ContextMenu(Graphics* parent) :
		BaseContext{ 2 , parent }
	{
		m_Map = &m_Objects[0];
		m_Characters = &m_Objects[1];
	}
	~ContextMenu() {}

	void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override;

};