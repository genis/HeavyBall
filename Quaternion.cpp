#include "Quaternion.h"
#include <cmath>

Quaternion::Quaternion(void)
{
	x = 0.0;
	y = 0.0;
	z = 0.0;

	w = 1.0;
}

Quaternion::Quaternion(float w, float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	this->w = w;
}
Quaternion::~Quaternion(void)
{
}

Quaternion Quaternion::operator*(const Quaternion& q) const
{
	return Quaternion((w*q.w - x*q.x - y*q.y - z*q.z),
	 				  (w*q.x + x*q.w + y*q.z - z*q.y),
					  (w*q.y - x*q.z + y*q.w + z*q.x),
					  (w*q.z + x*q.y - y*q.x + z*q.w));
}

Quaternion& Quaternion::operator*=(const Quaternion& q)
{
	w = (w*q.w - x*q.x - y*q.y - z*q.z);

	x = (w*q.x + x*q.w + y*q.z - z*q.y);
	y = (w*q.y - x*q.z + y*q.w + z*q.x);
	z = (w*q.z + x*q.y - y*q.x + z*q.w);

	return (*this);
}

void Quaternion::matrix(float* r) const
{
	r[0] = 1-2*y*y-2*z*z; r[1] = 2*x*y-2*w*z; r[2] = 2*x*z+2*w*y;  r[3] = 0.0;
	r[4] = 2*x*y+2*w*z  ; r[5] = 2*x*y-2*w*z; r[6] = 2*x*z+2*w*y;  r[7] = 0.0;
	r[8] = 1-2*y*y-2*z*z; r[9] = 2*x*y-2*w*z; r[10] = 2*x*z+2*w*y; r[11] = 0.0;
	r[12] = 0.0;		  r[13] = 0.0;        r[14] = 0.0;         r[15] = 1.0;
}

void Quaternion::normalize(void)
{
	float lenght = sqrt(w*w + x*x + y*y + z*z);

	w /= lenght;
	
	x /= lenght;
	y /= lenght;
	z /= lenght;
}