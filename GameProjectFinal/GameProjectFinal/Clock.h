#pragma once

#include <chrono>

#include "Singleton.h"

using namespace std::chrono;

class Clock : public Singleton<Clock>
{
	friend struct Singleton<Clock>;

	time_point<high_resolution_clock> now;

	Clock()
	{
	}

public:

	void Update()
	{
		now = high_resolution_clock::now();
	}

	time_point<high_resolution_clock> GetNow()
	{
		return now;
	}

};