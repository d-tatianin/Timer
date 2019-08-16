#pragma once

#include <stdio.h>
#include <iostream>
#include <chrono>

#define DEFAULT_AUTO_UNIT_GETTER_ TimeUnit::MILLISECONDS

namespace TimeUnit {

	enum Unit : int
	{
		AUTO = 0,
		NANOSECONDS, 
		MICROSECONDS, 
		MILLISECONDS, 
		SECONDS, 
		MINUTES
	};

	inline const char* UnitToString(Unit unit)
	{
		switch (unit)
		{
		case NANOSECONDS:
			return "nanoseconds";
		case MICROSECONDS:
			return "microseconds";
		case MILLISECONDS:
			return "milliseconds";
		case SECONDS:
			return "seconds";
		case MINUTES:
			return "minutes";
		default:
			return nullptr;
		}
	}
}

class Timer
{
private:
	typedef std::chrono::time_point<std::chrono::high_resolution_clock>
		high_precision_tp;
	typedef std::chrono::duration<double, std::nano>
		high_precision_dr;
private:
	high_precision_tp m_Start;
	high_precision_tp m_End;
	high_precision_dr m_Duration;
	double            m_PreciseDuration;
	TimeUnit::Unit    m_Unit;
	TimeUnit::Unit    m_AutoUnit;
	bool              m_ShowResult;
	const char*       m_Name;
public:
	Timer()
		: m_Name("Unnamed"), m_Unit(TimeUnit::AUTO), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(TimeUnit::Unit unit)
		: m_Name("Unnamed"), m_Unit(unit), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name)
		: m_Name(name), m_Unit(TimeUnit::AUTO), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name, bool scoped)
		: m_Name(name), m_Unit(TimeUnit::AUTO), m_ShowResult(scoped)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name, TimeUnit::Unit unit)
		: m_Name(name), m_Unit(unit), m_ShowResult(true)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	Timer(const char* name, TimeUnit::Unit unit, bool scoped)
		: m_Name(name), m_Unit(unit), m_ShowResult(scoped)
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	void Reset()
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	void PrintElapsed()
	{
		m_End = std::chrono::high_resolution_clock::now();
		PrintResult();
	}

	void PrintElapsedReset()
	{
		m_End = std::chrono::high_resolution_clock::now();
		PrintResult();
		m_Start = std::chrono::high_resolution_clock::now();
	}

	double GetElapsed()
	{
		m_End = std::chrono::high_resolution_clock::now();
		CalculateElapsed();

		return m_PreciseDuration;
	}

	double GetElapsedReset()
	{
		m_End = std::chrono::high_resolution_clock::now();
		CalculateElapsed();
		m_Start = std::chrono::high_resolution_clock::now();

		return m_PreciseDuration;
	}

	void SetTimeUnit(TimeUnit::Unit unit)
	{
		m_Unit = unit;
	}

	friend std::ostream& operator<<(std::ostream& stream, Timer& timer)
	{
		stream << timer.GetElapsed();

		return stream;
	}

	~Timer()
	{
		if(m_ShowResult)
			PrintElapsedReset();
	}
private:
	void PrintResult()
	{
		m_Duration = m_End - m_Start;
		m_PreciseDuration = m_Duration.count();

		if (m_Unit != TimeUnit::NANOSECONDS)
			ConvertTime();

		printf("Function \"%s\" took %f %s.\n",
			m_Name,
			m_PreciseDuration,
			m_Unit == TimeUnit::AUTO ?
			TimeUnit::UnitToString(m_AutoUnit) :
			TimeUnit::UnitToString(m_Unit));
	}

	void CalculateElapsed()
	{
		m_Duration = m_End - m_Start;
		m_PreciseDuration = m_Duration.count();

		if (m_Unit == TimeUnit::AUTO)
			ConvertTime(DEFAULT_AUTO_UNIT_GETTER_);
		else if (m_Unit != TimeUnit::NANOSECONDS)
			ConvertTime();
	}

	void ConvertTime(TimeUnit::Unit overrideUnit = TimeUnit::AUTO)
	{
		switch (overrideUnit == TimeUnit::AUTO ? m_Unit : overrideUnit)
		{
		case TimeUnit::AUTO:
			if (m_PreciseDuration >= 60000000000)
			{
				m_PreciseDuration /= 60000000000;
				m_AutoUnit = TimeUnit::MINUTES;
			}
			else if (m_PreciseDuration >= 1000000000)
			{
				m_PreciseDuration /= 1000000000;
				m_AutoUnit = TimeUnit::SECONDS;
			}
			else if (m_PreciseDuration >= 1000000)
			{
				m_PreciseDuration /= 1000000;
				m_AutoUnit = TimeUnit::MILLISECONDS;
			}
			else if (m_PreciseDuration >= 1000)
			{
				m_PreciseDuration /= 1000;
				m_AutoUnit = TimeUnit::MICROSECONDS;
			}
			else
				m_AutoUnit = TimeUnit::NANOSECONDS;
			break;
		case TimeUnit::MICROSECONDS:
			m_PreciseDuration /= 1000;
			break;
		case TimeUnit::MILLISECONDS:
			m_PreciseDuration /= 1000000;
			break;
		case TimeUnit::SECONDS:
			m_PreciseDuration /= 1000000000;
			break;
		case TimeUnit::MINUTES:
			m_PreciseDuration /= 60000000000;
			break;
		default:
			break;
		}
	}
};