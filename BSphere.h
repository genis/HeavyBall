#pragma once
#include "Boundary.h"
#include "Point.h"
#include "BBox.h"

class BSphere : public Boundary
{
public:
	BSphere(void);
	~BSphere(void); 

	//bool collides(const Boundary& b) const;
	bool collides() const;
	//bool collides(const BCylinder& b);
	//bool collides(const BSphere& b);

private:

	Point center;
	float radius;
};

