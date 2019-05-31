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
public:
	Timer()
		: m_Name("Unknown"), m_Unit(MILLISECONDS)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(MeasurmentUnit unit)
		: m_Name("Unknown"), m_Unit(unit)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name)
		: m_Name(name), m_Unit(MILLISECONDS)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name, MeasurmentUnit unit)
		: m_Name(name), m_Unit(unit)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		m_End = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = m_End - m_Start;

		switch (m_Unit)
		{
		case MILLISECONDS:
			std::cout << "Function '" << m_Name << "' took: " << 1000 * duration.count() << " MS." << std::endl;
			break;
		case SECONDS:
			std::cout << "Function '" << m_Name << "' took: " << duration.count() << " seconds." << std::endl;
			break;
		case MINUTES:
			std::cout << "Function '" << m_Name << "' took: " << duration.count() / 60 << " minutes." << std::endl;
			break;
		}
	}
};