#include "Ray.h"

Ray::Ray(const Vector3& vec3A, const Vector3& vec3B)
{
	_vec3A = vec3A;
	_vec3B = vec3B;
}

void Ray::setOrigin(const Vector3& vec3Origin)
{
	_vec3A = vec3Origin;
}

void Ray::setTarget(const Vector3& vec3Target)
{
	_vec3B = vec3Target;
}

Vector3 Ray::vec3Origin() const
{
	return _vec3A;
}

Vector3 Ray::vec3Direction() const
{
	return _vec3B;
}

Vector3 Ray::vec3GetPositionOnLine(double_t dbT) const
{
	return _vec3A + (_vec3B * dbT);
}
