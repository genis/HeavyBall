#pragma once
#include "Globals.h"
#include "Point.h"
#include "Vector.h"
#include "Quaternion.h"

class Camera
{
private:
	Point p;
	Point vrp;

	float phi;
	float theta;
	float psi;

	Quaternion rotation;

	bool enabled;
public:
	Camera(void);
	Camera(Point pos, Point vrp, float rx, float ry, float rz);

	~Camera(void);

	void setUp(void) const;
	void setUpQ(void) const;

	void setVrp(Point vrp);
	void move(Vector t);
	void rotate(float x, float y, float z);

	void set(Point vrp, Point pos);

	void enable(void);
	void disable(void);

	bool isEnabled(void);
};

