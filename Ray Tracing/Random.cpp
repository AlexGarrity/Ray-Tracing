#include "Random.h"

Random& Random::get() {
	static Random r;
	return r;
}

double_t Random::dbRand()
{
	return rand() / RAND_MAX;
}

double_t Random::dbNext()
{
	return distributionOne(_mt19937Generator);
}

double_t Random::dbNext(double_t dbLower, double_t dbUpper)
{
	std::uniform_real_distribution<double_t> distribution(dbLower, dbUpper);
	return distribution(_mt19937Generator);
}
