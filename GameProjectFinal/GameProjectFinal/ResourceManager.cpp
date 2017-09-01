#include <algorithm>

#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	Reset();
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

void ResourceManager::Reset()
{
	for (auto val : m_Map)
	{
		val.second->Shutdown();
		delete val.second;
	}
	m_Map.clear();
}

/*
void ResourceManager::CleanDuplicates()
{
	std::map<char*, Model2D*> temp;

	for (auto pair : m_Map)
	{
		char* fileName = pair.first;

		// Find if the pair from m_Map is in the temp map.
		auto treeIterator = std::find_if(temp.begin(), temp.end(), [&](std::pair<char*, Model2D*> pair)->bool {
			return fileName == pair.second->GetName();
		});



		// If the pair isnt in the new map, add it to the map.
		if (treeIterator == temp.end())
		{
			temp.emplace(pair);
		}
		// Otherwise don't do anything, pair is already in the new map.
		else
		{
		}
	}

	// Put the temporary map as the new map.
	m_Map.swap(temp);
}*/