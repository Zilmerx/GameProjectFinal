#pragma once

#include "BaseModelManager.h"


class StaticModelManager : public BaseModelManager
{
	Model2D* m_Model;

public:

	StaticModelManager(Model2D* model) :
		m_Model{ model }
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