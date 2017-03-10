#pragma once

#include "Point3D.h"
#include "Direct3D.h"

class Scale : private Point3D<float>
{

public:
	Scale();

	Scale(float XScale, float YScale, float ZScale);

	void SetScale(float XScale, float YScale, float ZScale = 0.0f);

	Point3D<float> GetScale() const;

	XMMATRIX GetScaleMatrix() const;
};