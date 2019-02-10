#pragma once
#include <iostream>
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> end;
	std::chrono::duration<float> duration;
public:
	Timer();
	~Timer();
};