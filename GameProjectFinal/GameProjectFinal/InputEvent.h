#pragma once

#include <functional>
#include "Keys.h"

class InputEvent
{
	std::function<void()> m_Func;
	Keys m_Key;


public:

	InputEvent(Keys key, std::function<void()> func) :
		m_Key{ key },
		m_Func{ func }
	{
	}

	void Execute()
	{
		m_Func();
	}

	Keys getKey()
	{
		return m_Key;
	}

};

class OnPressEvent : public InputEvent
{
public:

	OnPressEvent(Keys key, std::function<void()> func) :
		InputEvent(key, func)
	{
	}
};

class OnReleaseEvent : public InputEvent
{
public:

	OnReleaseEvent(Keys key, std::function<void()> func) :
		InputEvent(key,func)
	{
	}
};

class OnHoldEvent : public InputEvent
{
public:

	OnHoldEvent(Keys key, std::function<void()> func) :
		InputEvent(key, func)
	{
	}
};