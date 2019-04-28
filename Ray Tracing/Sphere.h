#pragma once

#include "Object.h"

class Sphere : public Object
{
public:
	Sphere() = default;
	Sphere(Vector3 vec3Centre, double_t dbRadius) : _vec3Centre(vec3Centre), _dbRadius(dbRadius) {};

	virtual bool bCheckHit(const Ray& r, double_t dbTMin, double_t dbTMax, Hit& hit) const
	{
		Vector3 oc = r.vec3Origin() - _vec3Centre;
		double_t a = dbDotProduct(r.vec3Direction(), r.vec3Direction());
		double_t b = 2.0 * dbDotProduct(oc, r.vec3Direction());
		double_t c = dbDotProduct(oc, oc) - (_dbRadius * _dbRadius);
		double_t descriminant = (b * b) - (4 * a * c);
		if (descriminant > 0) {
			double_t dbTemp = (-b - sqrt(descriminant)) / a;
			if (dbTemp < dbTMax && dbTemp > dbTMin) {
				hit.dbT = dbTemp;
				hit.vec3P = r.vec3GetPositionOnLine(hit.dbT);
				hit.vec3Normal = (hit.vec3P - _vec3Centre) / _dbRadius;
				return true;
			}
			dbTemp = (-b + sqrt(descriminant)) / a;
			if (dbTemp < dbTMax && dbTemp > dbTMin) {
				hit.dbT = dbTemp;
				hit.vec3P = r.vec3GetPositionOnLine(hit.dbT);
				hit.vec3Normal = (hit.vec3P - _vec3Centre);
				hit.vec3Normal /= _dbRadius;
				return true;
			}
		}
		return false;
	}
	
	Vector3 _vec3Centre;
	double_t _dbRadius;
};