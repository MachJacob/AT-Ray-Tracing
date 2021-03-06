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
			_rec.mat = mat;
			return true;
		}
		temp = (-b + sqrt(b * b - a * c) / a);
		if (temp < _tMax && temp > _tMin)
		{
			_rec.t = temp;
			_rec.p = _ray.PointAt(_rec.t);
			_rec.normal = (_rec.p - centre) / radius;
			_rec.mat = mat;
			return true;
		}
	}
	return false;
}

bool Sphere::BoundingBox(float t0, float t1, AABB& _box) const
{
	_box = AABB(centre - Vector3(radius, radius, radius), centre + Vector3(radius, radius, radius));
	return true;
}