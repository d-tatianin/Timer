#pragma once
#include <iostream>
#include <chrono>

class Timer
{
public:

	enum class MeasurmentUnit
	{
		MILLISECONDS = 0, SECONDS = 1, MINUTES = 2
	};

private:
	const char* m_Name;
	MeasurmentUnit m_Unit;
	std::chrono::time_point<std::chrono::steady_clock> m_Start;
	//Have to keep this as a member variable to improve the timer accuracy. 
	std::chrono::time_point<std::chrono::steady_clock> m_End;
public:
	Timer();
	Timer(const MeasurmentUnit& unit);
	Timer(const char* name);
	Timer(const char* name, const MeasurmentUnit& unit);
	~Timer();
};