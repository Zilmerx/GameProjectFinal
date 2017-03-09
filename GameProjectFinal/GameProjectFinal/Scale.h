#pragma once

#include "Point3D.h"
#include "Direct3D.h"

class Scale : private Point3D<float>
{

public:
	Scale()
	{
		SetScale(1.0f, 1.0f, 1.0f);
	}

	Scale(float XScale, float YScale, float ZScale)
	{
		SetScale(XScale, YScale, ZScale);
	}

	void SetScale(float XScale, float YScale, float ZScale = 0.0f)
	{
		x = XScale;
		y = YScale;
		z = ZScale;
	}

	Point3D<float> GetScale() const
	{
		return *this;
	}

	XMMATRIX GetScaleMatrix() const
	{
		return XMMatrixScaling(x, y, z);
	}
};