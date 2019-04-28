#include "Random.h"

double_t Random::dbRand()
{
	return rand() / RAND_MAX;
}

double_t Random::dbNext()
{
	_lastValueIndex++;
	if (_lastValueIndex == 1000) {
		_lastValueIndex = 0;
	}
	return _arrdbRealValues.at(_lastValueIndex);
}

double_t Random::dbNext(double_t dbLower, double_t dbUpper)
{
	return (dbNext() * dbUpper) + dbLower;
}

void Random::generateDoubleValues()
{
	for (auto i = 0; i < 1000; i++) {
		_arrdbRealValues.at(i) = _distributionRealOne(_mt19937Generator);
	}
}

void Random::generateIntValues()
{
	for (auto i = 0; i < 1000; i++) {
		_arruIntValues.at(i) = _distributionRealOne(_mt19937Generator) * UINT64_MAX;
	}
}
