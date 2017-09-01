#pragma once



class BaseModelManager
{
public:

	virtual void Render(ID3D11Device*, ID3D11DeviceContext*) = 0;

	virtual Model2D* getCurrentModel() const = 0;
};