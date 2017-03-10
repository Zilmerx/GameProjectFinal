
#include "Scale.h"

Scale::Scale()
{
	SetScale(1.0f, 1.0f, 1.0f);
}

Scale::Scale(float XScale, float YScale, float ZScale)
{
	SetScale(XScale, YScale, ZScale);
}

void Scale::SetScale(float XScale, float YScale, float ZScale)
{
	x = XScale;
	y = YScale;
	z = ZScale;
}

Point3D<float> Scale::GetScale() const
{
	return *this;
}

XMMATRIX Scale::GetScaleMatrix() const
{
	return XMMatrixScaling(x, y, z);
}