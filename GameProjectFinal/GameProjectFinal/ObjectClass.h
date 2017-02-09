#pragma once

#include "Model2DClass.h"
#include "Position.h"
#include "TileSize.h"

class ObjectClass
{
	Point2D<float> m_Position;
	float m_Rotation;
	Point2D<float> m_Scale;

	Model2DClass* m_Model;

public:

	ObjectClass();
	ObjectClass(const ObjectClass& other);
	~ObjectClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*);
	void Shutdown();
	void Render(ID3D11Device*, ID3D11DeviceContext*);

	XMMATRIX GetTranslationMatrix()
	{
		return XMMatrixTranslation(
			m_Position.x, 
			m_Position.y, 
			0.0f);
	}

	XMMATRIX GetRotationMatrix()
	{
		return XMMatrixRotationRollPitchYaw(
			0.0f,
			0.0f,
			m_Rotation);
	}

	XMMATRIX GetScaleMatrix()
	{
		return XMMatrixScaling(
			m_Scale.x, 
			m_Scale.y, 
			1.0f);
	}

	Model2DClass* GetModel()
	{
		return m_Model;
	}

	void SetSize(TileSize XTileAmount = 1.0f, TileSize YTileAmount = 1.0f)
	{
		m_Scale.x = XTileAmount.GetSize();
		m_Scale.y = YTileAmount.GetSize();
	}

	void SetPosition(int XPos,int YPos)
	{
		m_Position.x = XPos;
		m_Position.y = YPos;
	}
};