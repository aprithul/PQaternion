#pragma once

#include "Vector3.h"
#include <math.h>

struct Quaternion
{
	float x, y, z, w;
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion(Vector3& v, float s);
	Quaternion operator*(const Quaternion& q);
	Vector3 operator*(const Vector3& v);
	void Normalize();
	Quaternion Inv();

	char buffer[64];
	char* to_string();

};