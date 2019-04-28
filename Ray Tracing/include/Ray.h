#pragma once

#include "Vector3.h"

class Ray
{
public:
	Ray() = default;
	Ray(const Vector3 &vec3A, const Vector3 &vec3B);

	void setOrigin(const Vector3 &vec3Origin);
	void setTarget(const Vector3& vec3Target);

	Vector3 vec3Origin() const;
	Vector3 vec3Direction() const;
	Vector3 vec3GetPositionOnLine(double_t dbT) const;

private:
	Vector3 _vec3A;
	Vector3 _vec3B;
};

