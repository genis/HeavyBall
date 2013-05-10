#include "Sphere.h"
#include "gl/glut.h"

Sphere::Sphere(void)
{
	radius = 1.0;
	mass = 0;

	externalForce = Vector(0.0, 0.0, 0.0);
}

Sphere::Sphere(float radius,  float mass)
{
	this->radius = radius;
	this->mass = mass;

	externalForce = Vector(0.0, 0.0, 0.0);
}

Sphere::~Sphere(void)
{
}

float Sphere::getRadius(void)
{
	return radius;
}

float Sphere::getMass(void)
{
	return mass;
}

Point Sphere::getPosition(void)
{
	return T;
}

Vector Sphere::getExternalForce(void)
{
	return externalForce;
}

Vector Sphere::getVelocity(void)
{
	return V;
}

void Sphere::setSphere(Point p, float rx, float ry, float rz) 
{
	T = p;
	
	phi = rx;
	theta = ry;
	psi = rz;
}

void Sphere::setExternalForce(Vector F) 
{
	externalForce = F;
}

void Sphere::setVelocity(Vector v)
{
	V = v;
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
		gluSphere(q, radius, 16,16);
		gluDeleteQuadric(q);
	glPopMatrix();
}