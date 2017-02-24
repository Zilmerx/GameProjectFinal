#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>
#include <Windows.h>
#include <algorithm>

#include "InputEventHandler.h"
#include "Singleton.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class InputManager
{
	// Vector of keys for which the values have to be updated in m_KeyValues.
	std::vector<Keys> m_KeysToUpdate;

	// Array of SHORTs holding the state of keys on last verification.
	#define KeyStatesSize Keys::ENUM_END
	SHORT m_KeyStates[KeyStatesSize];

	// Vector of callbacks when a key is triggered.
	std::vector<InputEventHandler> m_EventHandlers;

public:

	void AddHandler(InputEventHandler&& handler)
	{
		m_KeysToUpdate.push_back(handler.m_Key);
		m_EventHandlers.push_back(handler);
	}


	void RemoveHandler(InputEventHandler* handler)
	{
		for (std::vector<InputEventHandler>::iterator i = m_EventHandlers.begin(); i != m_EventHandlers.end(); ++i)
		{
			if (&*i == handler) 
			{ 
				m_EventHandlers.erase(i); break; 
			}
		}
	}

	void ClearHandlers()
	{
		m_KeysToUpdate.clear();
		m_EventHandlers.clear();
	}

	void CheckEvents()
	{
		UpdateKeyStates();
		ExecuteHandlers();
	}

	InputManager()
	{
		std::fill_n(m_KeyStates, (int)KeyStatesSize, 0);
	}

private:

	// Updates the state of the keys with the current info.
	void UpdateKeyStates()
	{
		for (const auto& key : m_KeysToUpdate)
		{
			m_KeyStates[key] = GetAsyncKeyState(key);
		}
	}

	// Executes the callbacks held by the handlers if the predicate allows so.
	void ExecuteHandlers() const
	{
		for (const auto& handler : m_EventHandlers)
		{
			handler.Handle(m_KeyStates[handler.m_Key]);
		}
	}
};