#pragma once

#include <functional>
#include "Keys.h"

class InputEvent
{
	Keys m_key;

protected:
	InputEvent(Keys key) :
		m_key{ key }
	{
	}

public:

	virtual void OnPress() {}

	virtual void OnHold() {}

	virtual void OnRelease() {}

	Keys getKey()
	{
		return m_key;
	}

};

class OnPressEvent final : public InputEvent
{
	std::function<void()> m_Func;

public:
	OnPressEvent(Keys key, std::function<void()> func) :
		InputEvent(key),
		m_Func{ func }
	{
	}

	virtual void OnPress() override
	{
		m_Func();
	}
};

class OnReleaseEvent final : public InputEvent
{
	std::function<void()> m_Func;

public:
	OnReleaseEvent(Keys key, std::function<void()> func) :
		InputEvent(key),
		m_Func{ func }
	{
	}

	virtual void OnRelease() override
	{
		m_Func();
	}
};

class OnHoldEvent final : public InputEvent
{
	std::function<void()> m_Func;

public:
	OnHoldEvent(Keys key, std::function<void()> func) :
		InputEvent(key),
		m_Func{ func }
	{
	}

	virtual void OnHold() override
	{
		m_Func();
	}
};