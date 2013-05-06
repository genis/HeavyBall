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

	float lenght();

	Vector operator+(const Vector& v) const;
	Vector& operator+=(const Vector& v);

	Vector operator-(const Vector& v) const;
	Vector& operator-=(const Vector& v);

	Vector operator*(float s) const;
	Vector& operator*=(float s);

	Vector operator/(float s) const;
	Vector& operator/=(float s);
	
	void normalize();

	Vector crossProd(const Vector& v) const;
	float dotProd(const Vector& v) const;	
};


