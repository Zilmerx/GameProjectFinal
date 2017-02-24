#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>
#include <memory>
#include "Object.h"


////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class BaseContext
{
public:

	std::vector<std::vector<std::unique_ptr<Object>>> m_Objects;

	BaseContext(size_t ObjectVectorSize) :
		m_Objects{ ObjectVectorSize }
	{}

	~BaseContext() {}

	virtual void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext) = 0;

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
};