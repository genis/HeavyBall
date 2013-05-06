#pragma once
#include "Vector.h"
#include "Point.h"

class Sphere
{
private:
	float phi;
	float theta;
	float psi;

	Vector T;

public:
	Sphere(void);
	~Sphere(void);

	Point getPos();

	void setSphere(Point p, float rx, float ry, float rz);
	void move(Vector t);
	void rotate(float r);

	void draw();
};

