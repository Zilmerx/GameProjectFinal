#pragma once

#include "BaseModelManager.h"


class StaticModelManager : public BaseModelManager
{

public:

	StaticModelManager(Model2D* model) :
		BaseModelManager{ model }
	{
	}

	StaticModelManager(const StaticModelManager& other) :
		BaseModelManager{ other }
	{
	}

	virtual Model2D* Render() override
	{
		m_Model->Render();
		return m_Model;
	}

	virtual void AddAnimation(duration_T duration, Model2D* model)
	{
	}

	virtual void OverrideAnimation(duration_T duration, Model2D* model)
	{
	}

	virtual void ToDefault()
	{
	}

	virtual Clonable* clone() const override
	{
		return new StaticModelManager(*this);
	}
};