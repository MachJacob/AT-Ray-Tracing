#pragma once
#include "Hitable.h"

class Material
{
public:
	virtual bool Scatter(const Ray& _rIn, const hitRecord& _rec, Vector3& attenuation, Ray& scattered) const = 0;

	Vector3 Reflect(Vector3& _v, const Vector3& _n) const
	{
		return _v - _n * (_v.dot(_n) * 2);
	}

	bool Refract(const Vector3& _v, const Vector3& _n, float niOverNt, Vector3& refracted) const
	{
		Vector3 uv = _v.normalised();
		float dt = uv.dot(_n);
		float discriminant = 1.0 - niOverNt * niOverNt * (1 - dt * dt);
		if (discriminant > 0)
		{
			refracted = ((uv - _n * dt) * niOverNt) - _n * std::sqrt(discriminant);
			return true;
		}
		else
			return false;
	}

	float Schlick(float _cos, float _refIdx) const
	{
		float r0 = (1 - _refIdx) / (1 + _refIdx);
		r0 = r0 * r0;
		return r0 + (1 - r0) * pow((1 - _cos), 5);
	}
};

