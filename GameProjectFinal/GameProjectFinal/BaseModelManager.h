#pragma once

#include <chrono>

#include "Clonable.h"

class BaseModelManager : public Clonable
{
public:

	using duration_T = std::chrono::duration<float>;

protected:

	Model2D* m_Model;

public:

	BaseModelManager(Model2D* model) :
		m_Model{ model }
	{
	}

	BaseModelManager(const BaseModelManager& other) :
		m_Model{ other.m_Model }
	{
	}

	virtual Model2D* Render(ID3D11Device*, ID3D11DeviceContext*) = 0;

	virtual void AddAnimation(duration_T duration, Model2D* model) = 0;

	virtual void OverrideAnimation(duration_T duration, Model2D* model) = 0;

	virtual void ToDefault() = 0;
};