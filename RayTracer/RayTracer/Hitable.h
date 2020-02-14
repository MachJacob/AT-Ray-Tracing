#pragma once
#include "Ray.h"
#include "AABB.h"

class Material;

struct hitRecord
{
	float t;
	Vector3 p;
	Vector3 normal;
	Material* mat;
};

class Hitable
{
public:
	virtual bool Hit(const Ray& _r, float _tMin, float _tMax, hitRecord& _rec) const = 0;
	virtual bool BoundingBox(float t0, float t1, AABB& _box) const = 0;
};

