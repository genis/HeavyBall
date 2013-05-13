
#pragma once
/*
#include "BBox.h"
#include "BCylinder.h"
#include "BSphere.h"
*/

class Boundary
{
public:
	//enum BoundaryType{CYLINDER, SPHERE, BOX};

	Boundary(void);
	virtual ~Boundary(void);

	//BoundaryType getBoundaryType(void) const;

	virtual bool collides() = 0;
	//virtual bool collides(const Boundary& b) = 0;
	//virtual bool collides(const BBox& b) = 0;
	//virtual bool collides(const BCylinder& b) = 0;
	//virtual bool collides(const BSphere& b) = 0;
	
private:

	//BoundaryType bType;
	/*
	bool boxCollison(const Boundary& b) const;
	bool boxCylinderCollision(const Boundary& b) const;
	bool boxSphereCollision(const Boundary& b) const;

	bool cylinderCollision(const Boundary& b) const;
	bool cylinderSphereCollision(const Boundary& b) const;
	
	bool sphereCollision(const Boundary& b) const;
	*/
};

