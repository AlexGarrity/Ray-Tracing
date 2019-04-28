#include "Timer.h"



Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::startTimer()
{
	start = std::chrono::steady_clock::now();
}

uint64_t Timer::stopTimer()
{
	end = std::chrono::steady_clock::now();
	return (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)).count();
}
