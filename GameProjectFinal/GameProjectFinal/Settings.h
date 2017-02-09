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


#define ONE_DEGREE 0.0174532925f


struct Settings : public Singleton<Settings>
{

	bool QUIT;


private:
	friend struct Singleton<Settings>;

	Settings() :
		QUIT{ false }
	{
	}



};