#include "BVH.h"
#include <iostream>

int BoxXCompare(const void* a, const void* b)
{
	AABB boxLeft, boxRight;
	Hitable* ah = *(Hitable * *)a;
	Hitable* bh = *(Hitable * *)b;
	if (!ah->BoundingBox(0, 0, boxLeft) || !bh->BoundingBox(0, 0, boxRight))
	{
		std::cerr << "no bounding box in bvh_node constructor\n";
	}
	if (boxLeft.Min().x - boxRight.Min().x < 0.0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int BoxYCompare(const void* a, const void* b)
{
	AABB boxLeft, boxRight;
	Hitable* ah = *(Hitable * *)a;
	Hitable* bh = *(Hitable * *)b;
	if (!ah->BoundingBox(0, 0, boxLeft) || !bh->BoundingBox(0, 0, boxRight))
	{
		std::cerr << "no bounding box in bvh_node constructor\n";
	}
	if (boxLeft.Min().y - boxRight.Min().y < 0.0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int BoxZCompare(const void* a, const void* b)
{
	AABB boxLeft, boxRight;
	Hitable* ah = *(Hitable * *)a;
	Hitable* bh = *(Hitable * *)b;
	if (!ah->BoundingBox(0, 0, boxLeft) || !bh->BoundingBox(0, 0, boxRight))
	{
		std::cerr << "no bounding box in bvh_node constructor\n";
	}
	if (boxLeft.Min().z - boxRight.Min().z < 0.0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

BVHNode::BVHNode(Hitable** l, int n, float time0, float time1)
{
	int axis = int(3 * RandomDouble());

	if (axis == 0)
	{
		qsort(l, n, sizeof(Hitable*), BoxXCompare);
	}
	else if (axis == 1)
	{
		qsort(l, n, sizeof(Hitable*), BoxYCompare);
	}
	else
	{
		qsort(l, n, sizeof(Hitable*), BoxZCompare);
	}

	if (n == 1)
	{
		left = right = l[0];
	}
	else if (n == 2)
	{
		left = l[0];
		right = l[1];
	}
	else
	{
		left = new BVHNode(l, n / 2, time0, time1);
		right = new BVHNode(l + (n / 2), n - (n / 2), time0, time1);
	}

	AABB boxLeft, boxRight;

	if (!left->BoundingBox(time0, time1, boxLeft) || 
		!right->BoundingBox(time0, time1, boxRight))
	{
		std::cerr << "no bounding box in bvh_node constructor\n";
	}

	box = AABB::SurroundingBox(boxLeft, boxRight);
}

bool BVHNode::BoundingBox(float t0, float t1, AABB& b) const
{
	b = box;
	return true;
}

bool BVHNode::Hit(const Ray& _r, float _tMin, float _tMax, hitRecord& _rec) const
{
	if (box.hit(_r, _tMin, _tMax))
	{
		hitRecord leftRec, rightRec;
		bool hitLeft = left->Hit(_r, _tMin, _tMax, leftRec);
		bool hitRight = right->Hit(_r, _tMin, _tMax, rightRec);
		if (hitLeft && hitRight)
		{
			if (leftRec.t < rightRec.t)
			{
				_rec = leftRec;
			}
			else
			{
				_rec = rightRec;
			}
			return true;
		}
		else if (hitLeft)
		{
			_rec = leftRec;
			return true;
		}
		else if (hitRight)
		{
			_rec = rightRec;
			return true;
		}
		else return false;
	}
	else return false;
}