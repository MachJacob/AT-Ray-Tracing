#pragma once
#include "Hitable.h"

class Sphere : public Hitable
{
public:
	Sphere() {}
	Sphere(Vector3 _cen, float _r) : centre(_cen), radius(_r) {};

	virtual bool Hit(const Ray& _ray, float _tMin, float _tMax, hitRecord& _rec) const;

	Vector3 centre;
	float radius;
};

