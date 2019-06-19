#pragma once

#include <stdio.h>
#include <chrono>

class Timer
{
public:
	enum MeasurmentUnit
	{
		MILLISECONDS = 0, SECONDS, MINUTES
	};
private:
	const char* m_Name;
	MeasurmentUnit m_Unit;
	std::chrono::time_point<std::chrono::steady_clock> m_Start;
	std::chrono::time_point<std::chrono::steady_clock> m_End;
	std::chrono::duration<float> m_Duration;
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
			case MILLISECONDS:
				printf("Function \"%s\" took: %f ms.\n", m_Name, 1000.0f * m_Duration.count());
				break;
			case SECONDS:
				printf("Function \"%s\" took: %f seconds.\n", m_Name, m_Duration.count());
				break;
			case MINUTES:
				printf("Function \"%s\" took: %f minutes.\n", m_Name, m_Duration.count());
				break;
		}

		m_Start = std::chrono::high_resolution_clock::now();
	}

	float ResetAndGetTime()
	{
		m_End = std::chrono::high_resolution_clock::now();
		m_Duration = m_End - m_Start;

		m_Start = std::chrono::high_resolution_clock::now();

		switch (m_Unit)
		{
			case MILLISECONDS: return 1000.0f * m_Duration.count();
			case SECONDS:      return m_Duration.count();
			case MINUTES:      return m_Duration.count() / 60.0f;
		}

		return -1.0f;
	}

	float GetTime()
	{
		m_End = std::chrono::high_resolution_clock::now();
		m_Duration = m_End - m_Start;
		return m_Duration.count();
	}

	~Timer()
	{
		if(m_ShowResult)
			ResetAndShowResult();
	}
};