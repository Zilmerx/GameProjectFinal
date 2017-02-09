#pragma once

#include <ostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "ChronoSuffix.h"


template<size_t nTests, class duration_type = std::chrono::nanoseconds>
class TestTimer
{
public:
	using clock_type = std::chrono::high_resolution_clock;

private:
	using timepoint_type = std::chrono::time_point<clock_type>;
	using vector_type = std::vector<duration_type>;

	duration_type m_overhead;
	vector_type m_time_results;

	void(*m_func)(void);

public:
	TestTimer(void(*func)(void)) :
		m_func{ func }
	{
		m_overhead = getOverhead(1000);

		m_time_results.reserve(nTests);

		Test();
	}

	std::string Test()
	{
		m_time_results.clear();

		// Remplissage du tableau des durées des calculs.
		for (unsigned int i = 0; i < nTests; ++i)
		{
			auto start = clock_type::now();

			m_func();

			auto end = clock_type::now();

			m_time_results.push_back(std::chrono::abs(delta(start, end) - m_overhead));
		}

		return getString();
	}

	friend std::ostream& operator<<(std::ostream& os, const TestTimer& obj)
	{
		return os << Test();
	}

private:

	size_t getNTests() const
	{
		return nTests;
	}

	std::string getString() const
	{
		auto overheadstr = (readable(m_overhead.count()) + GetSuffix<duration_type>());
		auto moyennestr = (readable(Calculs::Moyenne(m_time_results).count())) + (GetSuffix<duration_type>());
		auto medianestr = (readable(Calculs::Mediane(m_time_results).count())) + (GetSuffix<duration_type>());
		auto modestr = (readable(Calculs::Mode(m_time_results).first.count())) + (GetSuffix<duration_type>());

		std::string str
		{
			  "Test de la fonction - " + std::to_string(getNTests()) + " tests" + '\n'
			+ "-------------------------------" + '\n'
			+ "Overhead: " + overheadstr + '\n'
			+ "Moyenne : " + moyennestr + '\n'
			+ "Mediane : " + medianestr + '\n'
			+ "Mode    : " + modestr
		};

		return str;
	}

	duration_type delta(timepoint_type start, timepoint_type end) const
	{
		return std::chrono::duration_cast<duration_type>(end - start);
	}

	duration_type getOverhead(unsigned int nbTests)
	{
		std::vector<duration_type> vec;
		vec.reserve(nTests);

		for (unsigned int i = 0; i < nbTests; ++i)
		{
			auto before = clock_type::now();
			auto after = clock_type::now();

			vec.push_back(delta(before, after));
		}

		return Calculs::Moyenne(vec);
	}
};