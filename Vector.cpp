#include "Vector.h"
#include <cmath>

Vector::Vector(void)
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::~Vector(void)
{
}

float Vector::lenght() 
{
	return sqrtf(x*x + y*y + z*z);
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(x+v.x, y+v.y, z+v.z);
}

Vector& Vector::operator+=(const Vector& v)
{
	x += v.x; 
	y += v.y; 
	z += v.z;

	return (*this);
}

Vector Vector::operator-(const Vector& v) const
{
	return Vector(x-v.x, y-v.y, z-v.z);
}

Vector& Vector::operator-=(const Vector& v)
{
	x -= v.x; 
	y -= v.y; 
	z -= v.z;

	return (*this);
}


Vector Vector::operator*(float s) const
{
	return Vector(x*s, y*s, z*s);
}

Vector& Vector::operator*=(float s)
{
	x *= s; 
	y *= s; 
	z *= s;

	return (*this);
}

Vector Vector::operator/(float s) const
{
	return Vector(x/s, y/s, z/s);
}

Vector& Vector::operator/=(float s)
{
	x /= s; 
	y /= s; 
	z /= s;

	return (*this);
}

void Vector::normalize()
{
	float l = lenght();

	x = x/l;
	y = y/l;
	z = z/l;
}

Vector Vector::crossProd(const Vector& v) const
{
	return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

float Vector::dotProd(const Vector& v) const
{
	return x*v.x + y*v.y + z*v.z;
}