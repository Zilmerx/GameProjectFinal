
#include "FrameTime.h"

FrameTime::FrameTime() :
	last{ clock::now() }
{
}

float FrameTime::update()
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

float FrameTime::get_fps()
{
	return fps.count();
}