#pragma once

#include "Ray.h"

struct Hit {
	double_t dbT;
	Vector3 vec3P;
	Vector3 vec3Normal;
};

class Object
{
public:
	virtual bool bCheckHit(const Ray& r, double_t dbTMin, double_t dbTMax, Hit& hit) const = 0;
};

