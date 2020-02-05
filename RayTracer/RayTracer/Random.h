#pragma once

#include <cstdlib>

inline double RandomDouble()
{
	return rand() / (RAND_MAX + 1.0);
}

Vector3 RandomUnitSphere()
{
	Vector3 p;
	do {
		p = Vector3(RandomDouble(), RandomDouble(), RandomDouble()) * 2.0 - Vector3(1, 1, 1);
	} while (p.magnitudeSquare() >= 1.0);
	return p;
}