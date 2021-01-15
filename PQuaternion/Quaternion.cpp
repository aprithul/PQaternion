#include "Quaternion.h"

Quaternion::Quaternion()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}


Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Quaternion::Quaternion(Vector3& v, float s)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = s;
}


Quaternion Quaternion::operator*(const Quaternion& q) //grassman product
{
	
	Vector3 p_v{ x,y,z };
	Vector3 q_v{ q.x, q.y, q.z };
	float p_s = w;
	float q_s = q.w;

	Vector3 pq_v_0 = q_v * p_s;
	Vector3 pq_v_1 = p_v * q_s;
	Vector3 pq_v_2 = p_v ^ q_v;

	Vector3 pq_v = pq_v_0 + pq_v_1 + pq_v_2; // vector part of resulting quaternion
	float pq_s = p_s * q_s - (p_v * q_v);	// scaler part of resulting quaternion

	Quaternion pq{ pq_v, pq_s };

	return pq;
}

Vector3 Quaternion::operator*(const Vector3& v)
{
	Quaternion v_q{ v.x, v.y, v.z, 0.f };
	Quaternion rotated_v_q = ((*this * v_q) * this->Inv());
	Vector3 rotated_v{ rotated_v_q.x, rotated_v_q.y, rotated_v_q.z };
	return rotated_v;
}

void Quaternion::Normalize()
{
	float mag = sqrtf(x * x + y * y + z * z + w * w);
	x = x / mag;
	y = y / mag;
	z = z / mag;
	w = w / mag;
}

Quaternion Quaternion::Inv()
{
	Quaternion q;
	q.x = -x;
	q.y = -y;
	q.z = -z;
	q.w = w;
	return q;

}


char* Quaternion::to_string()
{
	sprintf_s(buffer, "%.2f, %.2f, %.2f, %.2f", x, y, z, w);
	return buffer;
}