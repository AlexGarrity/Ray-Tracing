#pragma once

#include <random>
#include <chrono>

class Random
{
public:
	double_t dbRand();
	double_t dbNext();
	double_t dbNext(double_t dbLower, double_t dbUpper);

	void setNoiseSize(uint64_t uNoiseSize);

	void generateDoubleValues();
	void generateIntValues();

private:
	std::uniform_real_distribution<double_t> _distributionRealOne = std::uniform_real_distribution<double_t>(0.0, 1.0);
	std::mt19937_64 _mt19937Generator;

	std::vector<uint64_t> _arruIntValues;
	std::vector<double_t> _arrdbRealValues;
	uint64_t _uLastValueIndex = 0;
	uint64_t _uNoiseSize = 10000;
};