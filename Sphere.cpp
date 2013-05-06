#include "Sphere.h"
#include "gl/glut.h"

Sphere::Sphere(void)
{
}

Sphere::~Sphere(void)
{
}

Point Sphere::getPos()
{
	return T;
}

void Sphere::setSphere(Point p, float rx, float ry, float rz) 
{
	T = p;
	
	phi = rx;
	theta = ry;
	psi = rz;
}

void Sphere::move(Vector t)
{
	T += t;
}

void Sphere::draw(void)
{
	glPushMatrix();
		glTranslatef(T.x, T.y, T.z);
		
		glRotatef(psi, 0.0f, 0.0f, 1.0f);
		glRotatef(phi, 1.0f, 0.0f, 0.0f);
		glRotatef(theta, 0.0f, 1.0f, 0.0f);

		glColor3f(1.0, 1.0, 1.0);
		
		GLUquadricObj *q = gluNewQuadric();
		gluSphere(q, 0.5, 16,16);
		gluDeleteQuadric(q);
	glPopMatrix();
}