#pragma once

#include <cstdint>
#include <cmath>
#include <iostream>

class Vector3
{
public:
	Vector3() = default;
	Vector3(const Vector3& v) {
		_arrdbValues[0] = v._arrdbValues[0];
		_arrdbValues[1] = v._arrdbValues[1];
		_arrdbValues[2] = v._arrdbValues[2];
	}
	Vector3(double_t dbX, double_t dbY, double_t dbZ) {
		_arrdbValues[0] = dbX;
		_arrdbValues[1] = dbY;
		_arrdbValues[2] = dbZ;
	}

	inline double_t dbX() const { 
		return _arrdbValues[0]; 
	}
	inline double_t dbY() const { 
		return _arrdbValues[1]; 
	}
	inline double_t dbZ() const { 
		return _arrdbValues[2]; 
	}
	inline const Vector3& operator+() const { 
		return *this;
	}
	inline Vector3 operator-() const { 
		return Vector3(-_arrdbValues[0], -_arrdbValues[1], -_arrdbValues[2]); 
	}
	inline double_t operator[](uint64_t u) const { 
		return _arrdbValues[u]; 
	}
	inline double_t& operator[](uint64_t u) { 
		return _arrdbValues[u]; 
	}

	inline Vector3& operator+=(const Vector3& v2);
	inline Vector3& operator-=(const Vector3& v2);
	inline Vector3& operator*=(const Vector3& v2);
	inline Vector3& operator/=(const Vector3& v2);
	inline Vector3& operator*=(const double_t scalar);
	inline Vector3& operator/=(const double_t scalar);

	inline double_t dbLength() const {
		return sqrt(
			dbSquareLength()
		);
	}

	inline double_t dbSquareLength() const {
		return _arrdbValues[0] * _arrdbValues[0] +
			_arrdbValues[1] * _arrdbValues[1] +
			_arrdbValues[2] * _arrdbValues[2];
	}

	inline void makeUnitVector();

	double_t _arrdbValues[3];
};


inline Vector3& Vector3::operator+=(const Vector3& v2) {
	_arrdbValues[0] += v2[0];
	_arrdbValues[1] += v2[1];
	_arrdbValues[2] += v2[2];
	return *this;
}
inline Vector3& Vector3::operator-=(const Vector3& v2) {
	_arrdbValues[0] -= v2[0];
	_arrdbValues[1] -= v2[1];
	_arrdbValues[2] -= v2[2];
	return *this;
}
inline Vector3& Vector3::operator*=(const Vector3& v2) {
	_arrdbValues[0] *= v2[0];
	_arrdbValues[1] *= v2[1];
	_arrdbValues[2] *= v2[2];
	return *this;
}
inline Vector3& Vector3::operator/=(const Vector3& v2) {
	_arrdbValues[0] /= v2[0];
	_arrdbValues[1] /= v2[1];
	_arrdbValues[2] /= v2[2];
	return *this;
}
inline Vector3& Vector3::operator*=(const double_t scalar) {
	_arrdbValues[0] *= scalar;
	_arrdbValues[1] *= scalar;
	_arrdbValues[2] *= scalar;
	return *this;
}
inline Vector3& Vector3::operator/=(const double_t scalar) {
	double_t dbK = 1.0 / scalar;
	_arrdbValues[0] *= dbK;
	_arrdbValues[1] *= dbK;
	_arrdbValues[2] *= dbK;
	return *this;
}

inline Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	return Vector3(
		v1._arrdbValues[0] + v2._arrdbValues[0],
		v1._arrdbValues[1] + v2._arrdbValues[1],
		v1._arrdbValues[2] + v2._arrdbValues[2]
	);
}

inline Vector3 operator-(const Vector3 & v1, const Vector3 & v2) {
	return Vector3(
		v1._arrdbValues[0] - v2._arrdbValues[0],
		v1._arrdbValues[1] - v2._arrdbValues[1],
		v1._arrdbValues[2] - v2._arrdbValues[2]
	);
}

inline Vector3 operator*(const Vector3 & v1, const Vector3 & v2) {
	return Vector3(
		v1._arrdbValues[0] * v2._arrdbValues[0],
		v1._arrdbValues[1] * v2._arrdbValues[1],
		v1._arrdbValues[2] * v2._arrdbValues[2]
	);
}

inline Vector3 operator/(const Vector3 & v1, const Vector3 & v2) {
	return Vector3(
		v1._arrdbValues[0] / v2._arrdbValues[0],
		v1._arrdbValues[1] / v2._arrdbValues[1],
		v1._arrdbValues[2] / v2._arrdbValues[2]
	);
}

inline Vector3 operator*(const Vector3 &v, const double_t dbScalar) {
	return Vector3(
		v._arrdbValues[0] * dbScalar,
		v._arrdbValues[1] * dbScalar,
		v._arrdbValues[2] * dbScalar
	);
}

inline Vector3 operator/(Vector3 v, const double_t dbScalar) {
	return Vector3(
		v[0] / dbScalar,
		v[1] / dbScalar,
		v[2] / dbScalar
	);
}

inline std::istream& operator>>(std::istream & is, Vector3 & v) {
	is >> v._arrdbValues[0] >> v._arrdbValues[1] >> v._arrdbValues[2];
	return is;
}

inline std::ostream& operator<<(std::ostream & os, const Vector3 & v) {
	os << v._arrdbValues[0] << " " << v._arrdbValues[1] << " " << v._arrdbValues[2];
	return os;
}

inline void Vector3::makeUnitVector() {
	double_t inverse = 1.0 / dbLength();
	_arrdbValues[0] *= inverse;
	_arrdbValues[1] *= inverse;
	_arrdbValues[2] *= inverse;
}

inline double_t dbDotProduct(const Vector3 & v1, const Vector3 & v2) {
	return v1._arrdbValues[0] * v2._arrdbValues[0] +
		v1._arrdbValues[1] * v2._arrdbValues[1] +
		v1._arrdbValues[2] * v2._arrdbValues[2];
}

inline Vector3 vec3CrossProduct(const Vector3 & v1, const Vector3 & v2) {
	return Vector3(
		((v1[1] * v2[2]) - (v1[2] * v2[1])),
		(-(v1[0] * v2[2]) - (v1[2] * v2[0])),
		((v1[0] * v2[1]) - (v1[1] * v2[0]))
	);
}

inline Vector3 vec3UnitVector(Vector3 v) {
	return v / v.dbLength();
}