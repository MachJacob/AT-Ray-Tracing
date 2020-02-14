#pragma once
#include "Hitable.h"

class Sphere : public Hitable
{
public:
	Sphere() {}
	Sphere(Vector3 _cen, float _r, Material* _m) : centre(_cen), radius(_r), mat(_m) {};

	virtual bool Hit(const Ray& _ray, float _tMin, float _tMax, hitRecord& _rec) const;
	virtual bool BoundingBox(float t0, float t1, AABB& _box) const;

	Vector3 centre;
	float radius;
	Material* mat;
};

