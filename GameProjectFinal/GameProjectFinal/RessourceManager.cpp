#include "RessourceManager.h"




ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	for (auto val : m_Map)
	{
		delete val.second;
	}
}

void ResourceManager::Make(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* fileName)
{
	Model2D* model = new Model2D{ D3D11_USAGE::D3D11_USAGE_DEFAULT };
	if (!model)
	{
		exit(0);
	}

	if (!model->Initialize(device, deviceContext, fileName))
	{
		exit(0);
	}

	m_Map.emplace(std::make_pair(fileName, model));
}

Model2D* ResourceManager::Get(char* fileName) const
{
	Model2D* model = std::find_if(m_Map.begin(), m_Map.end(), [&](std::pair<const char*, Model2D*> pair)->bool {
		return fileName == pair.second->GetName();
	})->second;

	return model;
}