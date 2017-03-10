#pragma once

#include "Point3D.h"
#include "Direct3D.h"

class Position : private Point3D<float>
{

public:
	Position();

	Position(float XPos, float YPos, float ZPos = 0.0f);

	void SetPosition(float XPos, float YPos, float ZPos = 0.0f);

	void SetGridPosition(int XPos, int YPos, int ZPos = 0);

	Point3D<float> GetPosition() const;

	DirectX::XMMATRIX GetTranslationMatrix() const;

};