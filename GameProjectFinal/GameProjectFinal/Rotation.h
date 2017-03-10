#pragma once

#include "Point3D.h"
#include "Direct3D.h"

class Rotation : private Point3D<float>
{

public:
	Rotation();

	Rotation(float xRot, float yRot, float zRot);

	void SetRotation(float xRot, float yRot, float zRot);

	Point3D<float> GetRotation() const;

	XMMATRIX GetRotationMatrix() const;

};