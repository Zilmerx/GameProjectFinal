
#include "Rotation.h"

Rotation::Rotation()
{
	SetRotation(0.0f, 0.0f, 0.0f);
}

Rotation::Rotation(float xRot, float yRot, float zRot)
{
	SetRotation(xRot, yRot, zRot);
}

void Rotation::SetRotation(float xRot, float yRot, float zRot)
{
	x = xRot;
	y = yRot;
	z = zRot;
}

Point3D<float> Rotation::GetRotation() const
{
	return *this;
}

XMMATRIX Rotation::GetRotationMatrix() const
{
	return XMMatrixRotationRollPitchYaw(x, y, z);
}