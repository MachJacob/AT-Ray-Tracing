#include "Matrix4x4.h"
#include <iostream>

Matrix4x4::Matrix4x4() 
{
	// 4x4 matrix - column major
	//	0	4	8	12   
	//	1	5	9	13
	//	2	6	10	14
	//	3	7	11	15


	for (int i = 0; i < 16; i++) {
		matrixData[i] = 0.0f;
	}

	matrixData[0] = matrixData[5] = matrixData[10] = matrixData[15] = 1.0f;

}

Matrix4x4::Matrix4x4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
{
	// 4x4 matrix - column major
	//	0	4	8	12   
	//	1	5	9	13
	//	2	6	10	14
	//	3	7	11	15

	matrixData[0] = m0;
	matrixData[4] = m4;
	matrixData[8] = m8;
	matrixData[12] = m12;

	matrixData[1] = m1;
	matrixData[5] = m5;
	matrixData[9] = m9;
	matrixData[13] = m13;

	matrixData[2] = m2;
	matrixData[6] = m6;
	matrixData[10] = m10;
	matrixData[14] = m14;

	matrixData[3] = m3;
	matrixData[7] = m7;
	matrixData[11] = m11;
	matrixData[15] = m15;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& _m) const
{
	Matrix4x4 n;

	n.matrixData[0] = matrixData[0] + _m.matrixData[0];
	n.matrixData[4] = matrixData[4] + _m.matrixData[4];
	n.matrixData[8] = matrixData[8] + _m.matrixData[8];
	n.matrixData[12] = matrixData[12] + _m.matrixData[12];

	n.matrixData[1] = matrixData[1] + _m.matrixData[1];
	n.matrixData[5] = matrixData[5] + _m.matrixData[5];
	n.matrixData[9] = matrixData[9] + _m.matrixData[9];
	n.matrixData[13] = matrixData[13] + _m.matrixData[13];

	n.matrixData[2] = matrixData[2] + _m.matrixData[2];
	n.matrixData[6] = matrixData[6] + _m.matrixData[6];
	n.matrixData[10] = matrixData[10] + _m.matrixData[10];
	n.matrixData[14] = matrixData[14] + _m.matrixData[14];

	n.matrixData[3] = matrixData[3] + _m.matrixData[3];
	n.matrixData[7] = matrixData[7] + _m.matrixData[7];
	n.matrixData[11] = matrixData[11] + _m.matrixData[11];
	n.matrixData[15] = matrixData[15] + _m.matrixData[15];

	return n;
}

void Matrix4x4::operator+=(const Matrix4x4& _m)
{
	matrixData[0] += _m.matrixData[0];
	matrixData[4] += _m.matrixData[4];
	matrixData[8] += _m.matrixData[8];
	matrixData[12] += _m.matrixData[12];

	matrixData[1] += _m.matrixData[1];
	matrixData[5] += _m.matrixData[5];
	matrixData[9] += _m.matrixData[9];
	matrixData[13] += _m.matrixData[13];

	matrixData[2] += _m.matrixData[2];
	matrixData[6] += _m.matrixData[6];
	matrixData[10] += _m.matrixData[10];
	matrixData[14] += _m.matrixData[14];

	matrixData[3] += _m.matrixData[3];
	matrixData[7] += _m.matrixData[7];
	matrixData[11] += _m.matrixData[11];
	matrixData[15] += _m.matrixData[15];
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& _m) const
{
	Matrix4x4 n;

	n.matrixData[0] = matrixData[0] - _m.matrixData[0];
	n.matrixData[4] = matrixData[4] - _m.matrixData[4];
	n.matrixData[8] = matrixData[8] - _m.matrixData[8];
	n.matrixData[12] = matrixData[12] - _m.matrixData[12];

	n.matrixData[1] = matrixData[1] - _m.matrixData[1];
	n.matrixData[5] = matrixData[5] - _m.matrixData[5];
	n.matrixData[9] = matrixData[9] - _m.matrixData[9];
	n.matrixData[13] = matrixData[13] - _m.matrixData[13];

	n.matrixData[2] = matrixData[2] - _m.matrixData[2];
	n.matrixData[6] = matrixData[6] - _m.matrixData[6];
	n.matrixData[10] = matrixData[10] - _m.matrixData[10];
	n.matrixData[14] = matrixData[14] - _m.matrixData[14];

	n.matrixData[3] = matrixData[3] - _m.matrixData[3];
	n.matrixData[7] = matrixData[7] - _m.matrixData[7];
	n.matrixData[11] = matrixData[11] - _m.matrixData[11];
	n.matrixData[15] = matrixData[15] - _m.matrixData[15];

	return n;
}

void Matrix4x4::operator-=(const Matrix4x4& _m)
{
	matrixData[0] -= _m.matrixData[0];
	matrixData[4] -= _m.matrixData[4];
	matrixData[8] -= _m.matrixData[8];
	matrixData[12] -= _m.matrixData[12];

	matrixData[1] -= _m.matrixData[1];
	matrixData[5] -= _m.matrixData[5];
	matrixData[9] -= _m.matrixData[9];
	matrixData[13] -= _m.matrixData[13];

	matrixData[2] -= _m.matrixData[2];
	matrixData[6] -= _m.matrixData[6];
	matrixData[10] -= _m.matrixData[10];
	matrixData[14] -= _m.matrixData[14];

	matrixData[3] -= _m.matrixData[3];
	matrixData[7] -= _m.matrixData[7];
	matrixData[11] -= _m.matrixData[11];
	matrixData[15] -= _m.matrixData[15];
}

Matrix4x4 Matrix4x4::operator*(const float& _s) const
{
	Matrix4x4 n;

	n.matrixData[0] = matrixData[0] * _s;
	n.matrixData[4] = matrixData[4] * _s;
	n.matrixData[8] = matrixData[8] * _s;
	n.matrixData[12] = matrixData[12] * _s;

	n.matrixData[1] = matrixData[1] * _s;
	n.matrixData[5] = matrixData[5] * _s;
	n.matrixData[9] = matrixData[9] * _s;
	n.matrixData[13] = matrixData[13] * _s;

	n.matrixData[2] = matrixData[2] * _s;
	n.matrixData[6] = matrixData[6] * _s;
	n.matrixData[10] = matrixData[10] * _s;
	n.matrixData[14] = matrixData[14] * _s;

	n.matrixData[3] = matrixData[3] * _s;
	n.matrixData[7] = matrixData[7] * _s;
	n.matrixData[11] = matrixData[11] * _s;
	n.matrixData[15] = matrixData[15] * _s;

	return n;
}

void Matrix4x4::operator*=(const float& _s)
{
	matrixData[0] *= _s;
	matrixData[4] *= _s;
	matrixData[8] *= _s;
	matrixData[12] *= _s;

	matrixData[1] *= _s;
	matrixData[5] *= _s;
	matrixData[9] *= _s;
	matrixData[13] *= _s;

	matrixData[2] *= _s;
	matrixData[6] *= _s;
	matrixData[10] *= _s;
	matrixData[14] *= _s;

	matrixData[3] *= _s;
	matrixData[7] *= _s;
	matrixData[11] *= _s;
	matrixData[15] *= _s;
}

void Matrix4x4::SetTranspose(const Matrix4x4& _m)
{
	//	0	4	8	12   
	//	1	5	9	13
	//	2	6	10	14
	//	3	7	11	15

	//4x4 transpose
	//	0	1	2	3   
	//	4	5	6	7
	//	8	9	10	11
	//	12	13	14	15
	matrixData[0] = _m.matrixData[0];
	matrixData[4] = _m.matrixData[1];
	matrixData[8] = _m.matrixData[2];
	matrixData[12] = _m.matrixData[3];

	matrixData[1] = _m.matrixData[4];
	matrixData[5] = _m.matrixData[5];
	matrixData[9] = _m.matrixData[6];
	matrixData[13] = _m.matrixData[7];

	matrixData[2] = _m.matrixData[8];
	matrixData[6] = _m.matrixData[9];
	matrixData[10] = _m.matrixData[10];
	matrixData[14] = _m.matrixData[11];

	matrixData[3] = _m.matrixData[12];
	matrixData[7] = _m.matrixData[13];
	matrixData[11] = _m.matrixData[14];
	matrixData[15] = _m.matrixData[15];
}

Matrix4x4 Matrix4x4::GetTranspose(const Matrix4x4& _m)
{
	Matrix4x4 result;
	result.SetTranspose(_m);
	return result;
}

void Matrix4x4::Print() 
{
	std::cout << "[" << matrixData[0] << "," << matrixData[4] << "," << matrixData[8] << "," << matrixData[12] << "," << std::endl;
	std::cout << "[" << matrixData[1] << "," << matrixData[5] << "," << matrixData[9] << "," << matrixData[13] << "," << std::endl;
	std::cout << "[" << matrixData[2] << "," << matrixData[6] << "," << matrixData[10] << "," << matrixData[14] << "," << std::endl;
	std::cout << "[" << matrixData[3] << "," << matrixData[7] << "," << matrixData[11] << "," << matrixData[15] << "," << std::endl;
}
