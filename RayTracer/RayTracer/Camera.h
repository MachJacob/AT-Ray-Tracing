#pragma once
#include "Transform.h"
#include "Ray.h"

class Camera
{
public:
	Camera()
	{
		lowerLeft = Vector3(-2.0, 1.0, -1.0);
		horizontal = Vector3(4.0, 0.0, 0.0);
		vertical = Vector3(0.0, -2.0, 0.0);
		origin = Vector3(0.0, 0.0, 0.0);
	}
	Camera(float _vFoV, float _aspect)
	{
		float theta = _vFoV * 3.14159265358979323846 / 180;
		float halfHeight = tan(theta / 2);
		float halfWidth = _aspect * halfHeight;
		lowerLeft = Vector3(-halfWidth, -halfHeight, -1);
		horizontal = Vector3(2 * halfWidth, 0, 0);
		vertical = Vector3(0, 2 * halfWidth, 0);
		origin = Vector3(0, 0, 0);

	}
	Transform transform;
	Ray GetRay(float u, float v);
	
	Vector3 lowerLeft;
	Vector3 horizontal;
	Vector3 vertical;
	Vector3 origin;
};

