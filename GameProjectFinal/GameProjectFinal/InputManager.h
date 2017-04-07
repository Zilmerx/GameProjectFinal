#pragma once


#include <vector>
#include <Windows.h>
#include <memory>

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
	std::vector<std::shared_ptr<InputEvent>> m_Handlers[KeyStatesSize];

public:


	template<class Handler, typename... Args>
	std::shared_ptr<Handler> InputManager::addHandler(Args&&... args)
	{
		std::shared_ptr<Handler> ptr{ std::make_unique<Handler>(std::forward<Args>(args)...) };

		Keys key = ptr->getKey();
		m_KeysToUpdate.push_back(key);
		m_Handlers[key].push_back(std::move(ptr));
		return ptr;
	}

	void removeHandler(std::shared_ptr<InputEvent>& handler);

	void clearHandlers();

	void checkEvents();

	Point2D<int> GetGlobalCursorPos();

	Point2D<int> GetClientCursorPos();

	Point2D<int> GetGridCursorPos();
private:

	bool keyIsActive(SHORT keyState);

	bool getKeyState(Keys key);

	void ExecuteHandlers(Keys key);

public:

	InputManager();

};