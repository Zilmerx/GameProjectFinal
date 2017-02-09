#pragma once

#include <string>
#include <chrono>
#include <type_traits>
#include <sstream>

template <typename T>
std::string GetSuffix()
{
	static_assert(false, "This type is not supported by this function.");
}

template<>
std::string GetSuffix<std::chrono::hours>()
{
	return "h";
}

template<>
std::string GetSuffix<std::chrono::minutes>()
{
	return "mins";
}

template<>
std::string GetSuffix<std::chrono::seconds>()
{
	return "secs";
}

template<>
std::string GetSuffix<std::chrono::milliseconds>()
{
	return "ms";
}

template<>
std::string GetSuffix<std::chrono::microseconds>()
{
	return "us";
}

template<>
std::string GetSuffix<std::chrono::nanoseconds>()
{
	return "ns";
}

// Transforme un long long en un string, et ajoute un ' à chaque millier.
template<class T, typename = std::enable_if<std::is_integral<T>::value>>
static std::string readable(T value)
{
	std::string number;
	std::stringstream strstream;

	strstream << value;
	strstream >> number;

	int counter = 0;
	for (int i = number.size(); i > 0; --i)
	{
		if (counter > 2)
		{
			counter = 0;
			number.insert(i, "'");
		}

		++counter;
	}

	return number;
}