#pragma once

//////////////
// INCLUDES //
//////////////
#include "Model2D.h"
#include "Position.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Object
{
	Point3D<float> m_Position;
	Point3D<float> m_Rotation;
	Point3D<float> m_Scale;

	Model2D* m_Model;

public:

	Object(Model2D* model);
	Object(const Object& other);
	~Object();

	void Initialize();
	void Shutdown();
	void Render(ID3D11Device*, ID3D11DeviceContext*);

	XMMATRIX GetTranslationMatrix() const;
	XMMATRIX GetRotationMatrix() const;
	XMMATRIX GetScaleMatrix() const;
	Model2D* GetModel() const;

	void SetSize(float XScale, float YScale);
	void SetPosition(float XPos, float YPos, float ZPos = 0.0f);
	void SetGridPosition(int XPos, int YPos, int ZPos = 0);
	void SetRotation(float x, float y, float z);

	Point3D<float> GetSize() const;
	Point3D<float> GetRotation() const;
	Point3D<float> GetPosition() const;
};