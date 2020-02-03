#pragma once
#include <cmath>

typedef struct Vector3
{
	Vector3() : x(0), y(0), z(0) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	float x;
	float y;
	float z;

	//basic operations
	void operator+=(const Vector3& _v) { x += _v.x, y += _v.y, z += _v.z; }
	Vector3 operator+(const Vector3& _v) const { return Vector3(x + _v.x, y + _v.y, z + _v.z); }
	void operator-=(const Vector3& _v) { x -= _v.x, y -= _v.y, z -= _v.z; }
	Vector3 operator-(const Vector3& _v) const { return Vector3(x - _v.x, y - _v.y, z - _v.z); }
	void operator*=(const float _s) { x *= _s, y *= _s, z *= _s; }
	Vector3 operator*(const float _s) { return Vector3(x * _s, y * _s, z * _s); }
	Vector3 operator*(const float _s) const { return Vector3(x * _s, y * _s, z * _s); }
	void operator/=(const float _s) { x /= _s, y /= _s, z /= _s; }
	Vector3 operator/(const float _s) { return Vector3(x / _s, y / _s, z / _s); }

	//dot product
	float operator*(const Vector3& _v) { return x * _v.x + y * _v.y + z * _v.z; }
	float dot(const Vector3& _v) { return x * _v.x + y * _v.y + z * _v.z; }

	//cross product
	Vector3 cross(const Vector3& _v) { return Vector3(y * _v.z - z * _v.y,
													z * _v.x - x * _v.z, 
													x * _v.y - y * _v.x); }
	void operator%=(const Vector3& _v) { *this = cross(_v); }
	Vector3 operator%(const Vector3& _v) {return Vector3(y * _v.z - z * _v.y,
													z * _v.x - x * _v.z, 
													x * _v.y - y * _v.x);}

	//magnitude
	float magnitude() { return std::sqrt(x * x + y * y + z * z); }
	float magnitude() const { return std::sqrt(x * x + y * y + z * z); }

	//normalise
	void normalise() {float mag = magnitude();
					if (mag > 0.0f) { x = x * (1 / mag), y = y * (1 / mag), z = z * (1 / mag); }}
	Vector3 normalised() const {
		float mag = magnitude();
		if (mag > 0.0f) { return Vector3(x * (1 / mag), y * (1 / mag), z * (1 / mag)); }
	}
};