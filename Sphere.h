#pragma once
#include "Vector.h"
#include "Point.h"
#include "Quaternion.h"

class Sphere
{
private:
	float mass;
	float radius;

	Vector externalForce;

	float phi;
	float theta;
	float psi;

	Vector T;
	Vector V; //velocitat

	//float alpha; //angular acceleration.
	Quaternion alpha; //angular acceleration.

public:
	Sphere(void);
	Sphere(float radius, float mass);
	~Sphere(void);

	Point getPosition(void);

	float getMass(void);
	float getRadius(void);
	Vector getExternalForce(void);
	Vector getVelocity(void);

	void setSphere(Point p, float rx, float ry, float rz);
	void setExternalForce(Vector F);
	void setVelocity(Vector v);

	void move(Vector t);
	void rotate(float r);

	void draw();
};

