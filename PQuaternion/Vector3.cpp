#include "Vector3.h"

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator^(const Vector3& v)
{
	Vector3 _v;
	_v.x = (y * v.z - z * v.y);
	_v.y = (z * v.x - x * v.z);
	_v.z = (x * v.y - y * v.x);
	return _v;
}

float Vector3::operator*(const Vector3& v)
{
	return x*v.x + y*v.y + z*v.z;
}

Vector3 Vector3::operator*(const float s)
{
	Vector3 _v;
	_v.x = this->x * s;
	_v.y = this->y * s;
	_v.z = this->z * s;
	return _v;
}


Vector3 Vector3::operator+(const Vector3& v)
{
	Vector3 _v;
	_v.x = this->x+v.x;
	_v.y = this->y+v.y;
	_v.z = this->z+v.z;
	return _v;
}

void Vector3::Normalize()
{
	float mag = sqrtf(x * x + y * y + z * z);
	x = x / mag;
	y = y / mag;
	z = z / mag;
}

char* Vector3::to_string()
{
	sprintf_s(buffer, "%.2f, %.2f, %.2f", x, y, z);
	return buffer;
}