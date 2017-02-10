#pragma once

#include "Model2DClass.h"
#include "Position.h"

class ObjectClass
{
	Point3D<float> m_Position;
	Point3D<float> m_Rotation;
	Point3D<float> m_Scale;

	Model2DClass* m_Model;

public:

	ObjectClass(Model2DClass* model);
	ObjectClass(const ObjectClass& other);
	~ObjectClass();

	void Initialize();
	void Shutdown();
	void Render(ID3D11Device*, ID3D11DeviceContext*);

	XMMATRIX GetTranslationMatrix()
	{
		return XMMatrixTranslation(
			m_Position.x, 
			m_Position.y, 
			m_Position.z);
	}

	XMMATRIX GetRotationMatrix()
	{
		return XMMatrixRotationRollPitchYaw(
			m_Rotation.x,
			m_Rotation.y,
			m_Rotation.z);
	}

	XMMATRIX GetScaleMatrix()
	{
		return XMMatrixScaling(
			m_Scale.x, 
			m_Scale.y, 
			m_Scale.z);
	}

	Model2DClass* GetModel()
	{
		return m_Model;
	}

	void SetSize(float XScale, float YScale)
	{
		m_Scale.x = XScale;
		m_Scale.y = YScale;
	}

	void SetPosition(int XPos,int YPos, int ZPos = 0)
	{
		m_Position.x = XPos;
		m_Position.y = YPos;
		m_Position.z = ZPos;
	}

	void SetRotation(float x, float y, float z)
	{
		m_Rotation.x = x;
		m_Rotation.y = y;
		m_Rotation.z = z;
	}

	Point3D<float> GetSize()
	{
		return m_Scale;
	}

	Point3D<float> GetRotation()
	{
		return m_Rotation;
	}

	Point3D<float> GetPosition()
	{
		return m_Position;
	}
};