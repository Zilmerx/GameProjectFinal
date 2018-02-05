

#include "Systemclass.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int)
{
	std::unique_ptr<SystemClass> System = std::make_unique<SystemClass>();

	// Create the system object.
	if (!System)
	{
		return 0;
	}

	// Initialize and run the system object.
	if (System->Initialize())
	{
		System->Run();
	}

	// Shutdown and release the system object.
	System->Shutdown();

	return 0;
}