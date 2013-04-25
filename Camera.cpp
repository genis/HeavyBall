#include "Camera.h"


Camera::Camera(void)
{
	phi = 0.0f;
	theta = 0.0f;
	psi = 0.0f;
}


Camera::Camera(Point pos, Point vrp, float rx, float ry, float rz)
{
	p = pos;
	this->vrp = vrp;

	phi = rx;
	theta = ry;
	psi = rz;
}

Camera::~Camera(void)
{
}

void Camera::setUp(void) const
{
	glTranslatef(p.x, p.y, p.z);

	glRotatef(phi, 1.0f, 0.0f, 0.0f);
	glRotatef(theta, 0.0f, 1.0f, 0.0f);
	glRotatef(psi, 0.0f, 0.0f, 1.0f);

	glTranslatef(-vrp.x, -vrp.y, -vrp.z);
}

void Camera::setVrp(Point vrp)
{
	this->vrp = vrp; 
}

void Camera::move(Vector t)
{
	p += t;
}

void Camera::rotate(float rx, float ry, float rz)
{
	phi += rx;
	theta += ry;
	psi += rz;
}