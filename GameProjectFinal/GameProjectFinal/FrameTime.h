#pragma once

#include "Singleton.h"
#include <chrono>

class FrameTime : public Singleton<FrameTime>
{
	friend struct Singleton<FrameTime>;

	FrameTime();

	using clock = std::chrono::high_resolution_clock;
private:
	std::chrono::time_point<clock> last;
	std::chrono::duration<float> fps;
public:

	float update();

	float get_fps();
};