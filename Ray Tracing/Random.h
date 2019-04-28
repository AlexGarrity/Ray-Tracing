#pragma once

#include <random>
#include <chrono>

class Random
{
public:
	double_t dbRand();
	double_t dbNext();
	double_t dbNext(double_t dbLower, double_t dbUpper);

	void generateDoubleValues();
	void generateIntValues();

private:
	std::uniform_real_distribution<double_t> _distributionRealOne = std::uniform_real_distribution<double_t>(0.0, 1.0);
	std::mt19937_64 _mt19937Generator;

	std::vector<uint64_t> _arruIntValues = std::vector<uint64_t>(1000);
	std::vector<double_t> _arrdbRealValues = std::vector<double_t>(1000);
	uint64_t _lastValueIndex = 0;
};