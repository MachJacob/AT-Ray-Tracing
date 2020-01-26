#pragma once
#include <math.h>

class Matrix4x4
{
private:

public:

	float matrixData[16] = { 0.0f };

	Matrix4x4();
	Matrix4x4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15);

	//basic operations
	Matrix4x4 operator+(const Matrix4x4& _m) const;
	void operator+=(const Matrix4x4& _m);
	Matrix4x4 operator-(const Matrix4x4& _m) const;
	void operator-=(const Matrix4x4& _m);
	Matrix4x4 operator*(const float& _s) const;
	void operator*=(const float& _s);

	//transpose
	void SetTranspose(const Matrix4x4& _m);
	Matrix4x4 GetTranspose(const Matrix4x4& _m);

	void Print();
};