#pragma once
#include "Hitable.h"

class BVHNode : public Hitable
{
public:
	BVHNode() {}
	BVHNode(Hitable** l, int n, float time0, float time1);

	virtual bool Hit(const Ray& _r, float _tMin, float _tMax, hitRecord& _rec) const;
	virtual bool BoundingBox(float t0, float t1, AABB& b) const;

	Hitable* left;
	Hitable* right;
	AABB box;
};

