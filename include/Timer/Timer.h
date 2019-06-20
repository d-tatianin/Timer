#pragma once

#include <stdio.h>
#include <chrono>

class Timer
{
public:
	enum MeasurmentUnit : int
	{
		NANOSECONDS = 0, MICROSECONDS, MILLISECONDS, SECONDS, MINUTES
	};
private:
	const char* m_Name;
	MeasurmentUnit m_Unit;
	std::chrono::time_point<std::chrono::steady_clock> m_Start;
	std::chrono::time_point<std::chrono::steady_clock> m_End;
	std::chrono::duration<double> m_Duration;
	bool m_ShowResult;
public:
	Timer()
		: m_Name("Unknown"), m_Unit(MILLISECONDS), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(MeasurmentUnit unit)
		: m_Name("Unknown"), m_Unit(unit), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name)
		: m_Name(name), m_Unit(MILLISECONDS), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name, bool printResultUponDestruction)
		: m_Name(name), m_Unit(MILLISECONDS), m_ShowResult(printResultUponDestruction)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name, MeasurmentUnit unit)
		: m_Name(name), m_Unit(unit), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name, MeasurmentUnit unit, bool printResultUponDestruction)
		: m_Name(name), m_Unit(unit), m_ShowResult(printResultUponDestruction)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	void Reset()
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	void ResetAndShowResult()
	{
		m_End = std::chrono::high_resolution_clock::now();
		m_Duration = m_End - m_Start;

		switch (m_Unit)
		{
			case NANOSECONDS:
				printf("Function \"%s\" took: %f nanoseconds.\n", m_Name, ConvertSecondsTo(m_Duration.count(), NANOSECONDS));
				break;
			case MICROSECONDS:
				printf("Function \"%s\" took: %f microseconds.\n", m_Name, ConvertSecondsTo(m_Duration.count(), MICROSECONDS));
				break;
			case MILLISECONDS:
				printf("Function \"%s\" took: %f ms.\n", m_Name, ConvertSecondsTo(m_Duration.count(), MILLISECONDS));
				break;
			case SECONDS:
				printf("Function \"%s\" took: %f seconds.\n", m_Name, m_Duration.count());
				break;
			case MINUTES:
				printf("Function \"%s\" took: %f minutes.\n", m_Name, ConvertSecondsTo(m_Duration.count(), MINUTES));
				break;
		}

		m_Start = std::chrono::high_resolution_clock::now();
	}

	double ResetAndGetTime()
	{
		m_End = std::chrono::high_resolution_clock::now();
		m_Duration = m_End - m_Start;

		m_Start = std::chrono::high_resolution_clock::now();

		return ConvertSecondsTo(m_Duration.count(), m_Unit);
	}

	double GetTime()
	{
		m_End = std::chrono::high_resolution_clock::now();
		m_Duration = m_End - m_Start;

		return ConvertSecondsTo(m_Duration.count(), m_Unit);
	}

	~Timer()
	{
		if(m_ShowResult)
			ResetAndShowResult();
	}
private:
	inline double ConvertSecondsTo(double seconds, MeasurmentUnit unit)
	{
		switch (unit)
		{
			case NANOSECONDS:  return 1000000000.0 * seconds;
			case MICROSECONDS: return 1000000.0 * seconds;
			case MILLISECONDS: return 1000.0 * seconds;
			case SECONDS:      return seconds;
			case MINUTES:      return seconds / 60.0;
		}

		return -1.0;
	}
};