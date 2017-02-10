#pragma once

#include <map>
#include <algorithm>

#include "MyDebug.h"
#include "Model2DClass.h"
#include "Singleton.h"


class RessourceManager : public Singleton<RessourceManager>
{
	friend class Singleton<RessourceManager>;

	std::map<char*, Model2DClass*> m_Map;

	RessourceManager()
	{
	}

	~RessourceManager()
	{
		for (auto val : m_Map)
		{
			delete val.second;
		}
	}

public:

	void Make(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* fileName)
	{
		Model2DClass* model = new Model2DClass{ D3D11_USAGE::D3D11_USAGE_DEFAULT };
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

	Model2DClass* Get(char* fileName)
	{
		Model2DClass* model = std::find_if(m_Map.begin(), m_Map.end(), [&](std::pair<const char*, Model2DClass*> pair)->bool {
			return fileName == pair.second->GetName();
		})->second;

		return model;
	}


};