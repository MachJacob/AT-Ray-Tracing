#include "Ray.h"

Ray::Ray()
{

}

Ray::Ray(const Vector3& a, const Vector3& b)
{
	origin = a;
	dir = b;
}
