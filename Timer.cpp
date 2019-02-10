#include "Timer.h"
	
Timer::Timer()
	: name("Unknown"), unit(MeasurmentUnit::MILLISECONDS)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(MeasurmentUnit unit)
	: name("Unknown"), unit(unit)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(const char* name)
	: name(name), unit(MeasurmentUnit::MILLISECONDS)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(const char* name, MeasurmentUnit unit)
	: name(name), unit(unit)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	if(unit == MeasurmentUnit::MILLISECONDS)
		std::cout << "Function '" << name << "' took: " << 1000 * duration.count() << " MS." << std::endl;
	if (unit == MeasurmentUnit::SECONDS)
		std::cout << "Function '" << name << "' took: " << duration.count() << " seconds." << std::endl;
	if (unit == MeasurmentUnit::MINUTES)
		std::cout << "Function '" << name << "' took: " << duration.count() / 60 << " minutes." << std::endl;
}
