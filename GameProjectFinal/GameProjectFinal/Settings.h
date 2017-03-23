#pragma once

#include "Singleton.h"

// Nom de la fenêtre.
#define WINDOWNAME L"PATATE"

#define FULLSCREEN		false
#define VSYNC_ENABLED	true
#define SCREEN_DEPTH	1000.0f
#define SCREEN_NEAR		0.1f

// If windowed then set it to 800x600 resolution.
/*
#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080
*/

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

#define PI 3.14159265358979323846264338327950288419716939937510582097494459
#define ONE_DEGREE 0.0174532925f

class SystemClass;
class Graphics;
class Direct3D;
class BaseContext;
class Camera;

struct Globals : public Singleton<Globals>
{
	bool Shutdown;

	SystemClass* system;
	Graphics* graphics;
	Direct3D* direct3d;
	BaseContext* context;
	Camera* camera;

private:
	friend struct Singleton<Globals>;

	Globals() :
		Shutdown{ false }
	{
	}

};