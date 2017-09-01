#pragma once

#include "BaseModelManager.h"


class AnimatedModelManager : public BaseModelManager
{

public:

	AnimatedModelManager(Model2D* defaultModel) :
		BaseModelManager{ defaultModel }
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