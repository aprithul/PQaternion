#include <stdio.h>
#include "Vector3.h"
#include "Quaternion.h"

int main()
{
	//Vector3 a{ 1,2,3 };
	//Vector3 b{ 4,5,6 };

	Quaternion p{ 1,2,3,4 };
	p.Normalize();
	//Quaternion q{ 4,5,6,7 };
	//q.Normalize();
	Vector3 v{ 5,1,5 };
	v.Normalize();

	auto res =  p * v;

	//printf("%.2f", res);
	//printf("%s\n", p.to_string());
	printf(res.to_string());

	return 0;
}