#include "Timer.h"
	
Timer::Timer() {
	start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << duration.count() << std::endl;
}
