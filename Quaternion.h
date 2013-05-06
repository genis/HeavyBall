#pragma once
class Quaternion
{
	float x;
	float y;
	float z;

	float w;

public:
	Quaternion(void);
	Quaternion(float w, float x, float y, float z);
	~Quaternion(void);

	Quaternion operator*(const Quaternion& q) const;
	Quaternion& operator*=(const Quaternion& q);
	
	void matrix(float* r) const;

	void normalize(void);
};

