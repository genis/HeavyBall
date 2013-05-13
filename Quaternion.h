#pragma once
#include "Vector.h"

class Quaternion
{
	float x;
	float y;
	float z;

	float w;

public:
	Quaternion(void);
	Quaternion(float w, float x, float y, float z);
	Quaternion(float w, const Vector& axis);
	Quaternion(float phi, float theta, float psi);

	~Quaternion(void);

	Quaternion operator*(const Quaternion& q) const;
	Quaternion& operator*=(const Quaternion& q);
	
	void matrix(float* r) const;

	void normalize(void);
};

