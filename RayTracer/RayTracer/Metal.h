#pragma once
#include "Material.h"

class Metal : public Material
{
public: 
	Metal(const Vector3& a, float f) : albedo(a) 
	{
		if (f < 1) fuzz = f; else fuzz = 1;
	}

	virtual bool Scatter(const Ray& _rIn, const hitRecord& _rec, Vector3& attenuation, Ray& scattered) const
	{
		Vector3 idk = _rIn.Direction();
		idk.normalise();
		Vector3 reflected = Reflect(idk, _rec.normal);
		scattered = Ray(_rec.p, reflected);
		attenuation = albedo;
		return (scattered.dir.dot(_rec.normal) > 0);
	}

	Vector3 Reflect(Vector3& _v, const Vector3& _n) const
	{
		return _v - _n * (_v.dot(_n) * 2);
	}

	Vector3 albedo;
	float fuzz;
};