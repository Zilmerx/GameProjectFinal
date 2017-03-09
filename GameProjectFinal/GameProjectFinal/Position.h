#pragma once

#include "Point3D.h"
#include "Direct3D.h"

class Position : private Point3D<float>
{

public:
	Position()
	{
		SetPosition(0.0f, 0.0f, 0.0f);
	}

	Position(float XPos, float YPos, float ZPos = 0.0f)
	{
		SetPosition(XPos, YPos, ZPos);
	}

	void SetPosition(float XPos, float YPos, float ZPos = 0.0f)
	{
		x = XPos;
		y = YPos;
		z = ZPos;
	}

	void SetGridPosition(int XPos, int YPos, int ZPos = 0)
	{
		x = static_cast<float>(XPos);
		y = static_cast<float>(YPos);
		z = static_cast<float>(ZPos);
	}

	Point3D<float> GetPosition() const
	{
		return *this;
	}

	DirectX::XMMATRIX GetTranslationMatrix() const
	{
		return XMMatrixTranslation(x, y, z);
	}

};