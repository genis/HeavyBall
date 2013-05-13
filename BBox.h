#pragma once
#include "Boundary.h"
#include "Point.h"
#include "BCylinder.h"
#include "BSphere.h"

class BBox : public Boundary
{
public:
	BBox(void);
	~BBox(void);

	bool collides() const;
	//bool collides(const BBox& b) const;
	//bool collides(const BCylinder& b) const;
	//bool collides(const BSphere& b) const;

private:

	Point pmin;
	Point pmax;

};

