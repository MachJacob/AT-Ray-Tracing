#pragma once
#include "Hitable.h"

class Material
{
public:
	virtual bool Scatter(const Ray& _rIn, const hitRecord& _rec, Vector3& attenuation, Ray& scattered) const = 0;
};

