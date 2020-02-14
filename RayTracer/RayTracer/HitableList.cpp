#include "HitableList.h"

bool HitableList::Hit(const Ray& _ray, float _tMin, float _tMax, hitRecord& _rec) const
{
	hitRecord tempRec;
	bool hitAnything = false;
	double closest = _tMax;
	for (int i = 0; i < listSize; i++)
	{
		if (list[i]->Hit(_ray, _tMin, closest, tempRec))
		{
			hitAnything = true;
			closest = tempRec.t;
			_rec = tempRec;
		}
	}
	return hitAnything;
}

bool HitableList::BoundingBox(float t0, float t1, AABB& _box) const
{
	if (listSize < 1)
	{
		return false;
	}

	AABB tempBox;
	bool firstTrue = list[0]->BoundingBox(t0, t1, tempBox);

	if (!firstTrue)
	{
		return false;
	}
	else
	{
		_box = tempBox;
	}
	for (int i = 1; i < listSize; i++)
	{
		if (list[i]->BoundingBox(t0, t1, tempBox))
		{
			_box = AABB::SurroundingBox(_box, tempBox);
		}
	}
}
