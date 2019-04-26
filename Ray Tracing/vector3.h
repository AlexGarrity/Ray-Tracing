#pragma once

#include <cstdlib>
#include <cstdint>
#include <cmath>

namespace vector {

	/*
	Superclass which all variants of vector3 inherit from
	Defines some virtual functions with implentations
	*/
	class Vector {
	public:
		Vector() = default;
		Vector(const Vector& v);
		Vector(double_t dbA, double_t dbB, double_t dbC, double_t dbD);

		virtual inline Vector& operator+();
		virtual inline Vector& operator-();
		virtual inline double_t operator[](uint32_t i) const;
		virtual inline double_t operator[](uint32_t i);

		virtual inline Vector& operator+=(const Vector& v2);
		virtual inline Vector& operator-=(const Vector& v2);
		virtual inline Vector& operator*=(const Vector& v2);
		virtual inline Vector& operator*=(const double_t scalar);
		virtual inline Vector& operator/=(const Vector& v2);
		virtual inline Vector& operator/=(const double_t scalar);

		virtual inline friend Vector operator+(const Vector& v1, const Vector& v2);
		virtual inline friend Vector operator-(const Vector& v1, const Vector& v2);
		virtual inline friend Vector operator*(const Vector& v1, const Vector& v2);
		virtual inline friend Vector operator*(const Vector& v1, const double_t scalar);
		virtual inline friend Vector operator/(const Vector& v1, const Vector& v2);
		virtual inline friend Vector operator/(const Vector& v1, const double_t scalar);

	protected:
		double_t _arrdbValues[4] = {0.0, 0.0, 0.0, 0.0};
	};

	class C_Vector3 : public Vector {
		C_Vector3() = default;
		C_Vector3(double_t dbX, double_t dbY, double_t dbZ);
		C_Vector3(const Vector& v);

		inline double_t dbX();
		inline double_t dbY();
		inline double_t dbZ();

		inline double_t dbLength() const;
		inline double_t dbDotProduct(const C_Vector3& v1, const C_Vector3& v2);
		inline C_Vector3 vec3UnitVector(C_Vector3 &v);
		inline C_Vector3 vec3CrossProduct(const C_Vector3& v1, const C_Vector3& v2);
	};

	class C_RGBA : public Vector {
	public:
		C_RGBA(double_t dbR, double_t dbG, double_t dbB, double_t dbA);

		inline double_t dbR() const;
		inline double_t dbG() const;
		inline double_t dbB() const;
		inline double_t dbA() const;
	};

	class C_RGB : public C_RGBA {
	public:
		C_RGB(double_t dbR, double_t dbG, double_t dbB);
	};


}

