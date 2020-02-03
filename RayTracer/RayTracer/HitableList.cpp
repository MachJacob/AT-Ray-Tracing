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