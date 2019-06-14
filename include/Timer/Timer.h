#pragma once

#include <iostream>
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
		std::chrono::duration<float> duration = m_End - m_Start;

		switch (m_Unit)
		{
			case MILLISECONDS:
				std::cout << "Function \"" << m_Name << "\" took: " << 1000 * duration.count() << " MS." << std::endl;
				break;
			case SECONDS:
				std::cout << "Function \"" << m_Name << "\" took: " << duration.count() << " seconds." << std::endl;
				break;
			case MINUTES:
				std::cout << "Function \"" << m_Name << "\" took: " << duration.count() / 60 << " minutes." << std::endl;
				break;
		}

		m_Start = std::chrono::high_resolution_clock::now();
	}

	double ResetAndReturnTime()
	{
		m_End = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = m_End - m_Start;

		m_Start = std::chrono::high_resolution_clock::now();

		switch (m_Unit)
		{
			case MILLISECONDS: return 1000 * duration.count();
			case SECONDS:      return duration.count();
			case MINUTES:      return duration.count() / 60;
		}
	}

	~Timer()
	{
		if(m_ShowResult)
			ResetAndShowResult();
	}
};