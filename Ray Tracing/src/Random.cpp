#include "Random.h"

double_t Random::dbRand()
{
	return rand() / RAND_MAX;
}

double_t Random::dbNext()
{
	_uLastValueIndex++;
	if (_uLastValueIndex == _uNoiseSize) {
		_uLastValueIndex = 0;
	}
	return _arrdbRealValues.at(_uLastValueIndex);
}

double_t Random::dbNext(double_t dbLower, double_t dbUpper)
{
	return (dbNext() * dbUpper) + dbLower;
}

void Random::setNoiseSize(uint64_t uNoiseSize) {
	_uNoiseSize = uNoiseSize;
	_arruIntValues.resize(_uNoiseSize);
	_arrdbRealValues.resize(_uNoiseSize);
}

void Random::generateDoubleValues()
{
	for (auto i = 0; i < _uNoiseSize; i++) {
		_arrdbRealValues.at(i) = _distributionRealOne(_mt19937Generator);
	}
}

void Random::generateIntValues()
{
	for (auto i = 0; i < _uNoiseSize; i++) {
		_arruIntValues.at(i) = _distributionRealOne(_mt19937Generator) * UINT64_MAX;
	}
}
