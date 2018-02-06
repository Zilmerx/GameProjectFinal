#include <algorithm>

#include "ResourceManager.h"
#include "Debug.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	Reset();
}

void ResourceManager::Make(ID3D11Device* device, ID3D11DeviceContext* deviceContext, std::string fileName)
{
	Model2D* model = new Model2D{ D3D11_USAGE::D3D11_USAGE_DEFAULT };
	if (!model)
	{
		Debug::Crash("Could not create model" + fileName);
	}

	if (!model->Initialize(device, deviceContext, fileName))
	{
		Debug::Crash("Could not initialize model" + fileName);
	}

	m_Map.emplace(std::make_pair(fileName, model));
}

Model2D* ResourceManager::Get(std::string fileName) const
{
	Model2D* model = std::find_if(m_Map.begin(), m_Map.end(), [&](std::pair<std::string, Model2D*> pair)->bool {
		return fileName == pair.second->GetName();
	})->second;

	return model;
}

void ResourceManager::Reset()
{
	for (auto val : m_Map)
	{
		val.second->Shutdown();
		delete val.second;
	}
	m_Map.clear();
}