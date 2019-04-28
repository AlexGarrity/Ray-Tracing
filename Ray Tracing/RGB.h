#pragma once

#include <cstdint>
#include <cmath>
#include <iostream>

class RGB
{
public:
	RGB()
	{
		_dbR = 0.0;
		_dbG = 0.0;
		_dbB = 0.0;
		_iR = 0;
		_iG = 0;
		_iB = 0;
	};
	RGB(double_t dbR, double_t dbG, double_t dbB)
	{
		_dbR = dbR;
		_dbG = dbG;
		_dbB = dbB;

		recalculateIntegers();
	}

	void recalculateIntegers() {
		_iR = uint64_t(_dbR * 255.99);
		_iG = uint64_t(_dbG * 255.99);
		_iB = uint64_t(_dbB * 255.99);
	}

	inline double_t dbR() { return _dbR; }
	inline double_t dbG() { return _dbG; }
	inline double_t dbB() { return _dbB; }
	inline uint64_t uR() { return _iR; }
	inline uint64_t uG() { return _iG; }
	inline uint64_t uB() { return _iB; }

	inline RGB& operator+=(const RGB& v2);
	inline RGB& operator-=(const RGB& v2);
	inline RGB& operator*=(const RGB& v2);
	inline RGB& operator/=(const RGB& v2);
	inline RGB& operator*=(const double_t scalar);
	inline RGB& operator/=(const double_t scalar);

	double_t _dbR = 0.0, _dbG = 0.0, _dbB = 0.0;
	uint64_t _iR = 0, _iG = 0, _iB = 0;
};


inline RGB& RGB::operator+=(const RGB& v2) {
	_dbR += v2._dbR;
	_dbG += v2._dbG;
	_dbB += v2._dbB;
	return *this;
}
inline RGB& RGB::operator-=(const RGB& v2) {
	_dbR -= v2._dbR;
	_dbG -= v2._dbG;
	_dbB -= v2._dbB;
	return *this;
}
inline RGB& RGB::operator*=(const RGB& v2) {
	_dbR *= v2._dbR;
	_dbG *= v2._dbG;
	_dbB *= v2._dbB;
	return *this;
}
inline RGB& RGB::operator/=(const RGB& v2) {
	_dbR /= v2._dbR;
	_dbG /= v2._dbG;
	_dbB /= v2._dbB;
	return *this;
}
inline RGB& RGB::operator*=(const double_t scalar) {
	_dbR *= scalar;
	_dbG *= scalar;
	_dbB *= scalar;
	return *this;
}
inline RGB& RGB::operator/=(const double_t scalar) {
	double_t dbK = 1.0 / scalar;
	_dbR *= dbK;
	_dbG *= dbK;
	_dbB *= dbK;
	return *this;
}

inline RGB operator+(const RGB& v1, const RGB& v2) {
	return RGB(
		v1._dbR + v2._dbR,
		v1._dbG + v2._dbG,
		v1._dbB + v2._dbB
	);
}

inline RGB operator-(const RGB & v1, const RGB & v2) {
	return RGB(
		v1._dbR - v2._dbR,
		v1._dbG - v2._dbG,
		v1._dbB - v2._dbB
	);
}

inline RGB operator*(const RGB & v1, const RGB & v2) {
	return RGB(
		v1._dbR * v2._dbR,
		v1._dbG * v2._dbG,
		v1._dbB * v2._dbB
	);
}

inline RGB operator/(const RGB & v1, const RGB & v2) {
	return RGB(
		v1._dbR / v2._dbR,
		v1._dbG / v2._dbG,
		v1._dbB / v2._dbB
	);
}

inline RGB operator*(const RGB & v, double_t dbScalar) {
	return RGB(
		v._dbR * dbScalar,
		v._dbG * dbScalar,
		v._dbB * dbScalar
	);
}

inline RGB operator/(RGB& v, double_t dbScalar) {
	return RGB(
		v._dbR / dbScalar,
		v._dbG / dbScalar,
		v._dbB / dbScalar
	);
}

inline std::istream& operator>>(std::istream& is, RGB& r) {
	is >> r._iR >> r._iG >> r._iB;
	return is;
}

inline std::ostream& operator<<(std::ostream& os, RGB& r) {
	os << r.uR() << " " << r.uG() << " " << r.uB();
	return os;
}

