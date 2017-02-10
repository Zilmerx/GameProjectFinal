#pragma once

#include <vector>
#include "ObjectClass.h"

class WorldClass
{
public:
	std::vector<ObjectClass*> m_Map;

	WorldClass();
	~WorldClass();

	void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext);

	void Shutdown();

};