#pragma once

//////////////
// INCLUDES //
//////////////
#include <map>
#include <algorithm>

#include "MyDebug.h"
#include "Model2D.h"
#include "Singleton.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ResourceManager : public Singleton<ResourceManager>
{
	friend struct Singleton<ResourceManager>;

	std::map<char*, Model2D*> m_Map;

	ResourceManager();
	~ResourceManager();

public:

	void Make(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* fileName);
	Model2D* Get(char* fileName) const;
	void Reset();

};