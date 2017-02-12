
#include "RessourceManager.h"
#include "WorldClass.h"

WorldClass::WorldClass()
{

}



void WorldClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	RessourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");
	Model2DClass* model1 = RessourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");

	RessourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");
	Model2DClass* model2 = RessourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");

	for (int y = -3; y <= 3; y++) // -3 to 3, 7 values.
	{
		for (int x = -3; x <= 3; x++) // -3 to 3, 7 values.
		{

			std::unique_ptr<ObjectClass> obj;
			if (x % 2 == 0) // Is Even
			{
				obj = std::make_unique<ObjectClass>(model1);
			}
			else            // Is Odd
			{
				obj = std::make_unique<ObjectClass>(model2);
			}

			obj->SetPosition(x, y);

			obj->Initialize();

			m_Map.push_back(std::move(obj));
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
}