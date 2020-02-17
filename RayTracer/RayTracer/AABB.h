#pragma once
#include "Ray.h"
#include <algorithm>

inline float FFMin(float a, float b) { return a < b ? a : b; }
inline float FFMax(float a, float b) { return a > b ? a : b; }

class AABB
{
public:
	AABB() {}
	AABB(const Vector3& a, const Vector3& b) { _min = a; _max = b; }

	Vector3 Min() const { return _min; }
	Vector3 Max() const { return _max; }

	inline bool hit(const Ray& r, float tMin, float tMax) const
	{
		for (int a = 0; a < 3; a++)
		{
			/*float t0 = FFMin((_min.Idx(a) - r.Origin().Idx(a)) / r.Direction().Idx(a),
							(_max.Idx(a) - r.Origin().Idx(a)) / r.Direction().Idx(a));
			float t1 = FFMax((_min.Idx(a) - r.Origin().Idx(a)) / r.Direction().Idx(a), 
							(_max.Idx(a) - r.Origin().Idx(a)) / r.Direction().Idx(a));

			tMin = FFMax(t0, tMin);
			tMax = FFMin(t1, tMax);*/

			//Andrew Kensler's "better" method
			float invD = 1 / r.Direction().Idx(a);
			float t0 = (_min.Idx(a) - r.Origin().Idx(a)) * invD;
			float t1 = (_max.Idx(a) - r.Origin().Idx(a)) * invD;

			if (invD < 0)
			{
				std::swap(t0, t1);
			}

			tMin = t0 > tMin ? t0 : tMin;
			tMax = t1 < tMax ? t1 : tMax;


			if (tMax <= tMin)
			{
				return false;
			}
		}
		return true;
	}

	static AABB SurroundingBox(AABB box0, AABB box1)
	{
		Vector3 small(FFMin(box0.Min().x, box1.Min().x),
					  FFMin(box0.Min().y, box1.Min().y),
					  FFMin(box0.Min().z, box1.Min().z));

		Vector3 big(FFMax(box0.Max().x, box1.Max().x),
					FFMax(box0.Max().y, box1.Max().y),
					FFMax(box0.Max().z, box1.Max().z));

		return AABB(small, big);
	}

	Vector3 _min;
	Vector3 _max;
};