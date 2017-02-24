#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"


////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextWorld : public BaseContext
{
	std::vector<std::unique_ptr<Object>>* m_Map;
	std::vector<std::unique_ptr<Object>>* m_Characters;

public:

	ContextWorld() :
		BaseContext{ 2 }
	{
		m_Map = &m_Objects[0];
		m_Characters = &m_Objects[1];
	}
	~ContextWorld() {}

	void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override;

};