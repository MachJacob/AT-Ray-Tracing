#include "Camera.h"

Ray Camera::GetRay(float u, float v)
{
	return Ray(origin, lowerLeft + horizontal * u + vertical * v - origin);
}