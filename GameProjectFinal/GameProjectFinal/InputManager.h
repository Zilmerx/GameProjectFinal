#pragma once


#include <vector>
#include <Windows.h>

#include "Point2D.h"
#include "Keys.h"
#include "InputEvent.h"

class InputManager
{
	std::vector<Keys> m_KeysToUpdate;

	// Array of SHORTs holding the state of keys on last verification.
	#define KeyStatesSize Keys::ENUM_END

	bool m_KeyStates[KeyStatesSize];

	// Arrays of vectors.
	std::vector<OnPressEvent>	m_Press_Handlers[KeyStatesSize];
	std::vector<OnReleaseEvent> m_Release_Handlers[KeyStatesSize];
	std::vector<OnHoldEvent>	m_Hold_Handlers[KeyStatesSize];

public:

	void addHandler(OnPressEvent&& handler);

	void addHandler(OnReleaseEvent&& handler);

	void addHandler(OnHoldEvent&& handler);

	void removeHandler(OnPressEvent* handler);

	void removeHandler(OnReleaseEvent* handler);

	void removeHandler(OnHoldEvent* handler);

	void clearHandlers();

	void checkEvents();

	Point2D<int> GetGlobalCursorPos();

	Point2D<int> GetClientCursorPos();

	Point2D<int> GetGridCursorPos();
private:

	bool keyIsActive(SHORT keyState);

	bool getKeyState(Keys key);

	template<class T>
	void ExecuteHandlers(std::vector<T> vec[], Keys key)
	{
		std::vector<T>& handlerList = vec[key];

		for (auto handler : handlerList)
		{
			handler.Execute();
		}
	}

public:

	InputManager();

};