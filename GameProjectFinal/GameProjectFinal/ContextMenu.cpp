
#include "RessourceManager.h"
#include "ContextMenu.h"
#include "Graphics.h"

void ContextMenu::InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	m_Manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_P>(
		[this](SHORT)
	{
		m_Parent->SwitchContext<ContextWorld>();
	}
	));

	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");
	Model2D* model2 = ResourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/stone01.tga");

	ResourceManager::get().Make(device, deviceContext, "../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");
	Model2D* model1 = ResourceManager::get().Get("../GameProjectFinal/Resources/Maps/Tiles/MT-GR-02.tga");

	/*
	for (float fy = -3.0f; fy <= 3.0f; fy += 0.5f) // -3 to 3, 7 values.
	{
	for (float fx = -3.0f; fx <= 3.0f; fx += 0.5f) // -3 to 3, 7 values.
	{
	int x = fx;
	int y = fy;

	std::unique_ptr<Object> obj;
	if (x % 2) // Is Even
	{
	obj = std::make_unique<Object>(model1); // Stones
	}
	else                // Is Odd
	{
	obj = std::make_unique<Object>(model2); // Grass
	}

	obj->SetPosition(x, y);

	obj->Initialize();

	m_Map.push_back(std::move(obj));
	}
	}*/


	for (int y = -3; y <= 3; y++) // -3 to 3, 7 values.
	{
		for (int x = -3; x <= 3; x++) // -3 to 3, 7 values.
		{
			std::unique_ptr<Object> obj;
			if (x % 2) // Is Even
			{
				obj = std::make_unique<Object>(model1); // Stones
			}
			else                // Is Odd
			{
				obj = std::make_unique<Object>(model2); // Grass
			}

			obj->SetPosition(x, y);

			obj->Initialize();

			m_Map->push_back(std::move(obj));
		}
	}
}