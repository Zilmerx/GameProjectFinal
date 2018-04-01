#include <algorithm>

#include "ResourceManager.h"
#include "Debug.h"
#include "Settings.h"
#include "Direct3D.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	Reset();
}

void ResourceManager::Make(std::string fileName)
{
	Model2D* model = new Model2D{ D3D11_USAGE::D3D11_USAGE_DEFAULT };
	if (!model)
	{
		Debug::Crash("Could not create model" + fileName);
	}

	if (!model->Initialize(fileName))
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