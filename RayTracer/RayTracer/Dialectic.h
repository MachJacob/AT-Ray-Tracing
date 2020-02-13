#pragma once
#include "Material.h"

class Dialectic : public Material
{
public:
	Dialectic(float _ri) : refIdx(_ri) {}

	virtual bool Scatter(const Ray& _rIn, const hitRecord& _rec, Vector3& attenuation, Ray& scattered) const
	{
		Vector3 outNorm;
		Vector3 rInDir = _rIn.Direction();
		Vector3 reflected = Reflect(rInDir, _rec.normal);
		float niOverNt;
		attenuation = Vector3(1, 1, 1);

		float refProb;
		float cos;

		Vector3 refracted;
		if (rInDir.dot(_rec.normal) > 0)
		{
			outNorm = -_rec.normal;
			niOverNt = refIdx;
			cos = refIdx * rInDir.dot(_rec.normal) / rInDir.magnitude();
		}
		else
		{
			outNorm = _rec.normal;
			niOverNt = 1 / refIdx;
			cos = -rInDir.dot(_rec.normal) / rInDir.magnitude();
		}

		if (Refract(rInDir, outNorm, niOverNt, refracted))
		{
			refProb = Schlick(cos, refIdx);
		}
		else
		{
			refProb = 1;
		}

		if (RandomDouble() < refProb)
		{
			scattered = Ray(_rec.p, reflected);
		}
		else
		{
			scattered = Ray(_rec.p, refracted);
		}
		return true;
	}

	float refIdx;
};