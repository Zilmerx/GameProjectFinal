#pragma once

#include "Point3D.h"
#include "Direct3D.h"

class Rotation : private Point3D<float>
{

public:
	Rotation()
	{
		SetRotation(0.0f, 0.0f, 0.0f);
	}

	Rotation(float xRot, float yRot, float zRot)
	{
		SetRotation(xRot, yRot, zRot);
	}

	void SetRotation(float xRot, float yRot, float zRot)
	{
		x = xRot;
		y = yRot;
		z = zRot;
	}

	Point3D<float> GetRotation() const
	{
		return *this;
	}

	XMMATRIX GetRotationMatrix() const
	{
		return XMMatrixRotationRollPitchYaw(x, y, z);
	}
};