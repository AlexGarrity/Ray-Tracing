#pragma once

#include <random>
#include <chrono>

class Random
{
public:
	static Random& get();

	double_t dbRand();
	double_t dbNext();
	double_t dbNext(double_t dbLower, double_t dbUpper);

private:
	std::uniform_real_distribution<double_t> distributionOne = std::uniform_real_distribution<double_t>(0.0, 1.0);
	std::mt19937_64 _mt19937Generator;
};