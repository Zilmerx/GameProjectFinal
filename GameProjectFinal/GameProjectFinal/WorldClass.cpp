
#include "RessourceManager.h"
#include "WorldClass.h"

WorldClass::WorldClass()
{

}



void WorldClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	RessourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");
	Model2DClass* model = RessourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");


	for (int y = -2; y < 2; ++y)
	{
		for (int x = -2; x < 2; ++x)
		{
			ObjectClass* const obj = new ObjectClass{ model };

			obj->SetPosition(x, y);

			obj->Initialize();

			m_Map.push_back(obj);
		}
	}

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