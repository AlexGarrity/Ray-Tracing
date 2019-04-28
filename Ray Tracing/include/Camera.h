#pragma once

#include "Vector3.h"
#include "Ray.h"

class Camera
{
public:
	Camera();
	
	Ray rayGenerateRay(double_t dbHorizontal, double_t dbVertical);

private:
	Vector3 _vec3LowerLeft;
	Vector3 _vec3Origin;
	Vector3 _vec3HorizontalLength;
	Vector3 _vec3VerticalLength;
};

