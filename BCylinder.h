#pragma once
#include "Boundary.h"
#include "Point.h"
#include "BBox.h"
#include "BSphere.h"

class BCylinder : public Boundary
{
public:
	BCylinder(void);
	~BCylinder(void);
	bool collides() const;
	//bool collides(const BBox& b) const;
	//bool collides(const BCylinder& b);
	//bool collides(const BSphere& b);

private:
	Point baseCenter;
	float radius;
	float height;
};

