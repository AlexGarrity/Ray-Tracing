#include "vector3.h"

namespace vector {
	Vector::Vector(const Vector& v)
	{
		_arrdbValues[0] = v[0];
		_arrdbValues[1] = v[1];
		_arrdbValues[2] = v[2];
		_arrdbValues[3] = v[3];
	}
	Vector::Vector(double_t dbA = 0, double_t dbB = 0, double_t dbC = 0, double_t dbD = 0)
	{
		_arrdbValues[0] = dbA;
		_arrdbValues[1] = dbB;
		_arrdbValues[2] = dbC;
		_arrdbValues[3] = dbD;
	}

	Vector& Vector::operator+()
	{
		return *this;
	}

	Vector& Vector::operator-()
	{
		return Vector(
			-_arrdbValues[0],
			-_arrdbValues[1],
			-_arrdbValues[2],
			-_arrdbValues[3]
		);
	}

	double_t Vector::operator[](uint32_t i) const
	{
		return _arrdbValues[i];
	}

	double_t Vector::operator[](uint32_t i)
	{
		return _arrdbValues[i];
	}

	Vector& Vector::operator+=(const Vector & v2)
	{
		for (auto i = 0; i < 4; i++) {
			_arrdbValues[i] += v2[i];
		}
		return *this;
	}

	Vector& Vector::operator-=(const Vector & v2)
	{
		for (auto i = 0; i < 4; i++) {
			_arrdbValues[i] -= v2[i];
		}
		return *this;
	}

	Vector& Vector::operator*=(const Vector & v2)
	{
		for (auto i = 0; i < 4; i++) {
			_arrdbValues[i] *= v2[i];
		}
		return *this;
	}

	 Vector& Vector::operator*=(const double_t scalar)
	{
		for (auto i = 0; i < 4; i++) {
			_arrdbValues[i] *= scalar;
		}
		return *this;
	}

	Vector& Vector::operator/=(const Vector & v2)
	{
		for (auto i = 0; i < 4; i++) {
			_arrdbValues[i] /= v2[i];
		}
		return *this;
	}

	Vector& Vector::operator/=(const double_t scalar)
	{
		for (auto i = 0; i < 4; i++) {
			_arrdbValues[i] /= scalar;
		}
		return *this;
	}

	Vector operator+(const Vector& v1, const Vector& v2)
	{
		return Vector(
			v1[0] + v2[0],
			v1[1] + v2[1],
			v1[2] + v2[2],
			v1[3] + v2[3]
		);
	}

	Vector operator-(const Vector& v1, const Vector& v2)
	{
		return Vector(
			v1[0] - v2[0],
			v1[1] - v2[1],
			v1[2] - v2[2],
			v1[3] - v2[3]
		);
	}

	Vector operator*(const Vector& v1, const Vector& v2)
	{
		return Vector(
			v1[0] * v2[0],
			v1[1] * v2[1],
			v1[2] * v2[2],
			v1[3] * v2[3]
		);
	}

	Vector operator*(const Vector& v1, const double_t scalar)
	{
		return Vector(
			v1[0] * scalar,
			v1[1] * scalar,
			v1[2] * scalar,
			v1[3] * scalar
		);
	}

	Vector operator/(const Vector& v1, const Vector& v2)
	{
		return Vector(
			v1[0] / v2[0],
			v1[1] / v2[1],
			v1[2] / v2[2],
			v1[3] / v2[3]
		);
	}

	Vector operator/(const Vector& v1, const double_t scalar)
	{
		return Vector(
			v1[0] / scalar,
			v1[1] / scalar,
			v1[2] / scalar,
			v1[3] / scalar
		);
	}


	C_Vector3::C_Vector3(const Vector& v) : Vector(v)
	{
	}

	inline double_t C_Vector3::dbX()
	{
		return _arrdbValues[1];
	}

	inline double_t C_Vector3::dbY()
	{
		return _arrdbValues[2];
	}

	inline double_t C_Vector3::dbZ()
	{
		return _arrdbValues[3];
	}

	inline double_t C_Vector3::dbLength() const
	{
		return sqrt(
			_arrdbValues[0] * _arrdbValues[0] +
			_arrdbValues[1] * _arrdbValues[1] +
			_arrdbValues[2] * _arrdbValues[2] +
			_arrdbValues[3] * _arrdbValues[3]
		);
	}

	inline double_t C_Vector3::dbDotProduct(const C_Vector3& v1, const C_Vector3& v2)
	{
		return double_t(
			(v1[0] * v2[0])
			+ (v1[1] * v2[1])
			+ (v1[2] * v2[2])
		);
	}

	inline C_Vector3 C_Vector3::vec3UnitVector(C_Vector3 &v)
	{
		return v / dbLength();
	}

	inline C_Vector3 C_Vector3::vec3CrossProduct(const C_Vector3& v1, const C_Vector3& v2)
	{
		return C_Vector3(
			((v1[1] * v2[2]) - (v1[2] * v2[1])),
			(-(v1[0] * v2[2]) - (v1[2] * v2[0])),
			((v1[1] * v2[1]) - (v1[1] * v2[0]))
		);
	}

	C_RGBA::C_RGBA(double_t dbR, double_t dbG, double_t dbB, double_t dbA)
		: Vector(dbR, dbB, dbG, dbA)
	{
	}

	double_t C_RGBA::dbR() const
	{
		return _arrdbValues[0];
	}

	double_t C_RGBA::dbG() const
	{
		return _arrdbValues[1];
	}

	double_t C_RGBA::dbB() const
	{
		return _arrdbValues[2];
	}

	double_t C_RGBA::dbA() const
	{
		return _arrdbValues[3];
	}

	C_RGB::C_RGB(double_t dbR, double_t dbG, double_t dbB)
		: C_RGBA(dbR, dbB, dbG, 1.0f)
	{
	}

};