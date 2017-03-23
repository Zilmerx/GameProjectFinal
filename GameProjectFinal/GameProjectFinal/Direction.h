#pragma once

#include "Position.h"


enum class VerticalDirection
{
	NONE	= 0,
	UP		= 1,
	DOWN	= -1
};

enum class HorizontalDirection
{
	NONE	= 0,
	LEFT	= -1,
	RIGHT	= 1
};

struct Direction
{
	VerticalDirection m_vertical;
	HorizontalDirection m_horizontal;

	Direction() :
		m_vertical{ VerticalDirection::NONE },
		m_horizontal{ HorizontalDirection::NONE }
	{
	}

	Direction(const Direction& other) :
		m_vertical{ other.m_vertical },
		m_horizontal{ other.m_horizontal }
	{
	}

	Direction(const Position& from, const Position& to)
	{
		const auto fromPos = from.GetPosition();
		const auto toPos = to.GetPosition();

		// Horizontal.
		if (fromPos.x < toPos.x)
		{
			m_horizontal = HorizontalDirection::RIGHT;
		}
		else if (fromPos.x > toPos.x)
		{
			m_horizontal = HorizontalDirection::LEFT;
		}
		else
		{
			m_horizontal = HorizontalDirection::NONE;
		}

		// Vertical.
		if (fromPos.y < toPos.y)
		{
			m_vertical = VerticalDirection::UP;
		}
		else if (fromPos.y > toPos.y)
		{
			m_vertical = VerticalDirection::DOWN;
		}
		else
		{
			m_vertical = VerticalDirection::NONE;
		}
	}

	bool isDiagonal() const
	{
		return m_horizontal != HorizontalDirection::NONE 
			&& m_vertical != VerticalDirection::NONE;
	}

	bool isNull()
	{
		return m_horizontal == HorizontalDirection::NONE
			&& m_vertical == VerticalDirection::NONE;
	}

	bool isOnAxis()
	{
		return (m_horizontal == HorizontalDirection::NONE)
			 ^ (m_vertical == VerticalDirection::NONE);
	}

	Direction& Direction::operator=(const Direction& other)
	{
		if (this != &other)
		{
			m_vertical = other.m_vertical;
			m_horizontal = other.m_horizontal;
		}
		return *this;
	}

	operator Point3D<int>()
	{
		Point3D<int> point;

		point.x = (int)m_horizontal;
		point.y = (int)m_vertical;

		return point;
	}
};