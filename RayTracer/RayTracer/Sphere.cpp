#include "Sphere.h"

bool Sphere::Hit(const Ray& _ray, float _tMin, float _tMax, hitRecord& _rec) const
{
	Vector3 oc = _ray.Origin() - centre;
	float a = _ray.Direction().dot(_ray.Direction());
	float b = oc.dot(_ray.Direction());
	float c = oc.dot(oc) - radius * radius;
	float discriminant = b * b - a * c;

	if (discriminant > 0)
	{
		float temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < _tMax && temp > _tMin)
		{
			_rec.t = temp;
			_rec.p = _ray.PointAt(_rec.t);
			_rec.normal = (_rec.p - centre) / radius;
			return true;
		}
		temp = (-b + sqrt(b * b - a * c) / a);
		if (temp < _tMax && temp > _tMin)
		{
			_rec.t = temp;
			_rec.p = _ray.PointAt(_rec.t);
			_rec.normal = (_rec.p - centre) / radius;
			return true;
		}
	}
	return false;
}