#pragma once

class BaseModelManager
{
protected:

	Model2D* m_Model;

public:

	BaseModelManager(Model2D* model) :
		m_Model{ model }
	{
	}

	virtual void Render(ID3D11Device*, ID3D11DeviceContext*) = 0;

	virtual Model2D* getCurrentModel() const = 0;
};