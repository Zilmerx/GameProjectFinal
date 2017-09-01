#pragma once

#include "BaseModelManager.h"


class StaticModelManager : public BaseModelManager
{

public:

	StaticModelManager(Model2D* model) :
		BaseModelManager{ model }
	{
	}

	virtual void Render(ID3D11Device* device, ID3D11DeviceContext* context) override
	{
		m_Model->Render(device, context);
	}

	virtual Model2D* getCurrentModel() const override
	{
		return m_Model;
	}
};