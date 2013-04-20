#pragma once
class Vector
{
public:
	float x;
	float y;
	float z;

	Vector();
	Vector(float x, float y, float z);
	~Vector(void);

	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);

	void normalize();

	Vector crossProd(const Vector& v) const;
	float dotProd(const Vector& v) const;
};


