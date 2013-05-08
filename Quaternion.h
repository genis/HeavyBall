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
	Quaternion(float w, Vector axis);
	~Quaternion(void);

	Quaternion operator*(const Quaternion& q) const;

	void matrix(float* r) const;

	void normalize(void);
};

