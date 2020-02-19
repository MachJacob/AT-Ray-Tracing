#include "Triangle.h"

bool Triangle::Hit(const Ray& _r, float _tMin, float _tMax, hitRecord& _rec) const
{
	return false;
}

bool Triangle::BoundingBox(float t0, float t1, AABB& _box) const
{
	return false;
}
