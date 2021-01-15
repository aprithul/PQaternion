#pragma once

#include <stdio.h>
#include <math.h>

struct Vector3
{
	float x, y, z;
	char buffer[64];

	Vector3();
	Vector3(float x, float y, float z);

	Vector3 operator^(const Vector3& v);
	float operator*(const Vector3& v);
	Vector3 operator*(const float s);
	Vector3 operator+(const Vector3& v);

	void Normalize();

	char* to_string();
};