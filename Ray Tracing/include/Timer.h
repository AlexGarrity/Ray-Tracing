#pragma once

#include <chrono>

class Timer
{
public:
	Timer();
	~Timer();

	void startTimer();
	uint64_t stopTimer();

private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
};

