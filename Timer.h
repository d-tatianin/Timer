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
	const char* name;
	MeasurmentUnit unit;
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> end;
	std::chrono::duration<float> duration;
public:
	Timer();
	Timer(MeasurmentUnit unit);
	Timer(const char* name);
	Timer(const char* name, MeasurmentUnit unit);
	~Timer();
};