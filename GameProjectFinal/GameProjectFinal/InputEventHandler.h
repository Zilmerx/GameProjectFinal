#pragma once

#include <iostream>
#include <functional>

#include "Keys.h"


class InputEventHandler
{
public:

	const Keys m_Key;
	const std::function<bool(SHORT)> m_Predicate;
	const std::function<void(SHORT)> m_Handler;

	void Handle(SHORT keyState) const
	{
		if (m_Predicate(keyState))
		{
			m_Handler(keyState);
		}
	}

	template<Keys key>
	static InputEventHandler Gen_DefaultHandler(std::function<void(SHORT)>&& handler)
	{
		return InputEventHandler{ key, [](SHORT keyState) { return ((1 << 16) & keyState) != 0; }, std::move(handler) };
	}

private:

	InputEventHandler(Keys key, std::function<bool(SHORT)>&& predicate, std::function<void(SHORT)>&& handler) :
		m_Key{ key },
		m_Predicate{ predicate },
		m_Handler{ handler }
	{
	}
};