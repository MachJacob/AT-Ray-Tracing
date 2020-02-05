#pragma once
#include "Material.h"

class Lambertian : public Material
{
public:
	Lambertian(const Vector3& a) : albedo(a) {}
	virtual bool Scatter(const Ray& _rIn, const hitRecord* _rec, Vector3& attenuation, Ray& scattered) const
	{
		Vector3 target = _rec->p + _rec->normal + RandomUnitSphere();
		scattered = Ray(_rec->p, target - _rec->p);
		attenuation = albedo;
		return true;
	}

	Vector3 albedo;
};