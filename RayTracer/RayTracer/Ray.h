#pragma once
#include "Transform.h"
#include "Random.h"
class Ray
{
public:
	Ray();
	Ray(const Vector3& a, const Vector3& b);

	Vector3 Origin() const { return origin; }
	Vector3 Direction() const { return dir; }
	Vector3 PointAt(const float _t) const { return origin + dir * _t; }

	Vector3 origin;
	Vector3 dir;
};

