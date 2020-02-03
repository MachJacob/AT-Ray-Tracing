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
	Transform transform;
	Ray GetRay(float u, float v);
	
	Vector3 lowerLeft;
	Vector3 horizontal;
	Vector3 vertical;
	Vector3 origin;
};

