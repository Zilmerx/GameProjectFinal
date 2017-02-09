#pragma once

#include <random>
#include <chrono>

#include "Singleton.h"

class Random : public Singleton<Random>
{
	friend class Singleton<Random>;

	std::mt19937 rng;

protected:

	Random() :
		rng{ std::chrono::high_resolution_clock::now().time_since_epoch().count() }
	{
	}

public:

	template<class T>
	typename std::enable_if<std::is_integral<T>::value, T>::type Rand(T min, T max)
	{
		std::uniform_int_distribution<T> dist{ min, max };

		return dist(rng);
	}

	template<class T>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type Rand(T min, T max)
	{
		std::uniform_real_distribution<T> dist{ min, max };

		return dist(rng);
	}



};