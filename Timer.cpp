#include "Timer.h"
	
Timer::Timer()
	: m_Name("Unknown"), m_Unit(MeasurmentUnit::MILLISECONDS)
{
	m_Start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(const MeasurmentUnit& unit)
	: m_Name("Unknown"), m_Unit(unit)
{
	m_Start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(const char* name)
	: m_Name(name), m_Unit(MeasurmentUnit::MILLISECONDS)
{
	m_Start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(const char* name, const MeasurmentUnit& unit)
	: m_Name(name), m_Unit(unit)
{
	m_Start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	m_End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = m_End - m_Start;

	switch (m_Unit)
	{
	case MeasurmentUnit::MILLISECONDS:
		std::cout << "Function '" << m_Name << "' took: " << 1000 * duration.count() << " MS." << std::endl;
		break;
	case MeasurmentUnit::SECONDS:
		std::cout << "Function '" << m_Name << "' took: " << duration.count() << " seconds." << std::endl;
		break;
	case MeasurmentUnit::MINUTES:
		std::cout << "Function '" << m_Name << "' took: " << duration.count() / 60 << " minutes." << std::endl;
		break;
	}
}
