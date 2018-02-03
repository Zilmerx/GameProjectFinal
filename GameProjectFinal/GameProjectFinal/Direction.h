#pragma once

#include "Point2D.h"


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

	Direction(const Point2D<int>& from, const Point2D<int>& to)
	{
		// Horizontal.
		if (from.x < to.x)
		{
			m_horizontal = HorizontalDirection::RIGHT;
		}
		else if (from.x > to.x)
		{
			m_horizontal = HorizontalDirection::LEFT;
		}
		else
		{
			m_horizontal = HorizontalDirection::NONE;
		}

		// Vertical.
		if (from.y < to.y)
		{
			m_vertical = VerticalDirection::UP;
		}
		else if (from.y > to.y)
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

	operator Point2D<int>() const
	{
		Point2D<int> point;

		point.x = (int)m_horizontal;
		point.y = (int)m_vertical;

		return point;
	}
};