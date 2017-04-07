
#include "InputManager.h"

#include "ScreenSize.h"
#include "Settings.h"
#include "SystemClass.h"


void InputManager::removeHandler(std::shared_ptr<InputEvent>& handler)
{
	Keys key = handler->getKey();

	for (auto i = m_Handlers[key].begin(); i != m_Handlers[key].end(); ++i)
	{
		if (*&*i == handler)
		{
			m_Handlers[key].erase(i); break;
		}
	}
}

void InputManager::clearHandlers()
{
	m_KeysToUpdate.clear();

	for (auto& vec : m_Handlers)
	{
		vec.clear();
	}
}

void InputManager::checkEvents()
{
	bool oldState;
	SHORT newVal;
	bool newState;

	for (Keys key : m_KeysToUpdate)
	{
		oldState = getKeyState(key);

		newVal = GetAsyncKeyState(key);
		newState = keyIsActive(newVal);

		if (oldState == false
			&& newState == true) // OnPress event.
		{
			for (auto& handler : m_Handlers[key])
			{
				handler->OnPress();
			}

			m_KeyStates[key] = newState;
		}
		else if (oldState == true
			&& newState == false) // OnRelease event.
		{
			for (auto& handler : m_Handlers[key])
			{
				handler->OnRelease();
			}

			m_KeyStates[key] = newState;
		}
		else if (oldState == true
			  && newState == true) // OnHold
		{
			for (auto& handler : m_Handlers[key])
			{
				handler->OnHold();
			}
		}
	}
}


bool InputManager::keyIsActive(SHORT keyState)
{
	return ((1 << 16) & keyState) != 0;
}

bool InputManager::getKeyState(Keys key)
{
	return m_KeyStates[key];
}

Point2D<int> InputManager::GetGlobalCursorPos()
{
	POINT p;
	if (GetCursorPos(&p))
	{
		return Point2D<int>{p.x, p.y};
	}
	else
	{
		return Point2D<int>{-1, -1};
	}
}

Point2D<int> InputManager::GetClientCursorPos()
{
	POINT p;
	if (GetCursorPos(&p))
	{
		if (ScreenToClient(Globals::get().system->GetHWND(), &p))
		{
			return Point2D<int>{p.x, p.y};
		}
	}

	return Point2D<int>{-1, -1};
}

Point2D<int> InputManager::GetGridCursorPos()
{
	Point2D<int> click = GetClientCursorPos();

	XMFLOAT3 cam = Globals::get().camera->GetPosition();
	cam.z = std::abs(cam.z);

	double ScreenHeight = (double)ScreenSize::get().height;
	double ScreenWidth = (double)ScreenSize::get().width;
	click.y = ScreenSize::get().height - click.y;

	constexpr double radian = 45.0 / 180 * PI;

	/*

	PI * (sqrt( h^2 + (tan(45) * h)^2)
	---------------------------
	180 / 45.0
	--------------------------------------
	tan(45) * h

	*/

	const double ratio = (PI * ((std::sqrt(std::pow(cam.z, 2) + std::pow(std::tan(radian) * cam.z, 2))) / (180.0 / 45.0))) / (std::tan(radian) * cam.z);

	const double gridHeight = cam.z * ratio * (ScreenHeight / ScreenWidth);
	const double gridWidth = cam.z * ratio;

	auto GridPosX = ((double)click.x * gridWidth) / ScreenWidth;
	auto GridPosY = ((double)click.y * gridHeight) / ScreenHeight;

	GridPosX -= (gridWidth / 2.0);
	GridPosY -= (gridHeight / 2.0);

	GridPosX += cam.x + 0.5;
	GridPosY += cam.y + 0.5;

	return Point2D<int>{ (int)GridPosX, (int)GridPosY };
}

InputManager::InputManager()
{
	std::fill_n(m_KeyStates, (int)KeyStatesSize, false);
}