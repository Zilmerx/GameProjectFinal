#pragma once

//////////////
// INCLUDES //
//////////////
#include <map>

#include "Model2D.h"
#include "Singleton.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ResourceManager : public Singleton<ResourceManager>
{
	friend struct Singleton<ResourceManager>;

	std::map<std::string, Model2D*> m_Map;

	ResourceManager();
	~ResourceManager();

public:

	void Make(ID3D11Device* device, ID3D11DeviceContext* deviceContext, std::string fileName);
	Model2D* Get(std::string fileName) const;
	void Reset();
};