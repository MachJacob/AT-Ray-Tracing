#pragma once
#include <math.h>

struct Vector4
{
	Vector4() : x(0), y(0), z(0), w(0) {}
	Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

	float x;
	float y;
	float z;
	float w;

	//basic operations
	void operator+=(const Vector4& _v) { x += _v.x, y += _v.y, z += _v.z, w += _v.w; }
	Vector4 operator+(const Vector4& _v) const { return Vector4(x + _v.x, y + _v.y, z + _v.z, w + _v.w); }
	void operator-=(const Vector4& _v) { x -= _v.x, y -= _v.y, z -= _v.z, w -= _v.w; }
	Vector4 operator-(const Vector4& _v) const { return Vector4(x - _v.x, y - _v.y, z - _v.z, w + _v.w); }
	void operator*=(const float _s) { x *= _s, y *= _s, z *= _s, w *= _s; }
	Vector4 operator*(const float _s) { return Vector4(x * _s, y * _s, z * _s, w * _s); }
	void operator/=(const float _s) { x /= _s, y /= _s, z /= _s, w /= _s; }
	Vector4 operator/(const float _s) { return Vector4(x / _s, y / _s, z / _s, w / _s); }

	//dot product
	float operator*(const Vector4& _v) { return x * _v.x + y * _v.y + z * _v.z + w * _v.w; }
	float dot(const Vector4& _v) { return x * _v.x + y * _v.y + z * _v.z + w * _v.w; }

	//magnitude
	float magnitude() { return std::sqrt(x * x + y * y + z * z + w * w); }

	//normalise
	void normalise() {
		float mag = magnitude();
		if (mag > 0.0f) { x = x * (1 / mag), y = y * (1 / mag), z = z * (1 / mag), w = w * (1 / mag); }
	}
};