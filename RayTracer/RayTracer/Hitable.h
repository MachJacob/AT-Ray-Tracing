#pragma once
#include "Ray.h"

class Material;

struct hitRecord
{
	float t;
	Vector3 p;
	Vector3 normal;
};

class Hitable
{
public:
	virtual bool Hit(const Ray& _r, float _tMin, float _tMax, hitRecord& _rec) const = 0;
};

