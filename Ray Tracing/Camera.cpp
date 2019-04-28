#include "Camera.h"



Camera::Camera()
{
	_vec3LowerLeft = Vector3(-8.0, -4.5, -1.0);
	_vec3HorizontalLength = Vector3(16.0, 0.0, 0.0);
	_vec3VerticalLength = Vector3(0.0, 9.0, 0.0);
	_vec3Origin = Vector3(0.0, 0.0, 0.0);
}

Ray Camera::rayGenerateRay(double_t dbHorizontal, double_t dbVertical)
{
	return Ray(_vec3Origin, _vec3LowerLeft + ((_vec3HorizontalLength * dbHorizontal) + (_vec3VerticalLength * dbVertical)) - _vec3Origin);
}