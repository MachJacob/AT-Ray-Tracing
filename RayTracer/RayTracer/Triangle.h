#pragma once
#include "Hitable.h"
class Triangle : public Hitable
{
	Triangle(Vector3 v0, Vector3 v1, Vector3 v2)
	{
		points[0] = v0; points[1] = v1; points[2] = v2;
	}
	virtual bool Hit(const Ray& _r, float _tMin, float _tMax, hitRecord& _rec) const;
	virtual bool BoundingBox(float t0, float t1, AABB& _box) const;

	Vector3 points[3];
};

