#pragma once

#include "Singleton.h"
#include <chrono>

class FrameTime : public Singleton<FrameTime>
{
	friend struct Singleton<FrameTime>;

	FrameTime() :
		last{ clock::now() }
	{
	}

	using clock = std::chrono::high_resolution_clock;
private:
	std::chrono::time_point<clock> last;
	std::chrono::duration<float> fps;
public:

	float update()
	{
		using namespace std::chrono;
		time_point<clock> now = clock::now();

		duration<float> diff_fps = now - last;

		if (diff_fps > seconds(1))
		{
			diff_fps = duration<float>(1.0f / 60.0f);
		}

		fps = diff_fps;
		last = now;

		return fps.count();
	}

	float get_fps()
	{
		return fps.count();
	}
};