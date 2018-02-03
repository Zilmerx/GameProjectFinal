#pragma once

#include "Point3D.h"
#include "Direct3D.h"

class Position : private Point3D<float>
{

public:
	Position();

	Position(float XPos, float YPos, float ZPos = 0.0f);

	void SetPosition(float XPos, float YPos, float ZPos = 0.0f);

	void SetGridPosition(unsigned int XPos, unsigned int YPos, unsigned int ZPos = 0);

	Point3D<float> GetPosition() const;

	Point3D<unsigned int> GetGridPosition() const;

	DirectX::XMMATRIX GetTranslationMatrix() const;
	/*
	Position& operator+=(const Direction& rhs)
	{
		if (rhs.m_horizontal == HorizontalDirection::RIGHT)
		{
			x += 1;
		}
		else if (rhs.m_horizontal == HorizontalDirection::LEFT)
		{
			x -= 1;
		}

		if (rhs.m_vertical == VerticalDirection::UP)
		{
			y += 1;
		}
		else if (rhs.m_vertical == VerticalDirection::DOWN)
		{
			y -= 1;
		}

		return *this;
	}*/
};