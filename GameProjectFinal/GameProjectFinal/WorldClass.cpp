

#include "WorldClass.h"

WorldClass::WorldClass()
{
	for (int y = -1; y < 1; ++y)
	{
		for (int x = -1; x < 1; ++x)
		{
			ObjectClass* const obj = new ObjectClass;

			obj->SetPosition(x, y);

			m_Map.push_back(obj);
		}
	}
}



bool WorldClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename)
{
	bool result;

	for (auto& ptr : m_Map)
	{
		result = ptr->Initialize(device, deviceContext, filename);
		if (!result)
		{
			return result;
		}
	}

	return result;
}

void WorldClass::Shutdown()
{
	for (auto& ptr : m_Map)
	{
		ptr->Shutdown();
	}
}


WorldClass::~WorldClass()
{
	for (auto& ptr : m_Map)
	{
		delete ptr;
	}
}