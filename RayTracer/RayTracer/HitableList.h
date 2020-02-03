#pragma once
#include "Hitable.h"

class HitableList : public Hitable
{
public:
	HitableList() {}
	HitableList(Hitable** l, int n) { list = l; listSize = n; }

	virtual bool Hit(const Ray& _ray, float _tMin, float _tMax, hitRecord& _rec) const;

	Hitable** list;
	int listSize;
};

