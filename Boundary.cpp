#include "Boundary.h"


Boundary::Boundary(void)
{
}

Boundary::~Boundary(void)
{
}

/*
Boundary::BoundaryType Boundary::getBoundaryType(void) const
{
	return bType;
}
*/
/*
bool Boundary::collides(const Boundary& tb)
{
	BoundaryType tbType = tb.getBoundaryType();

	switch(bType) {
		case  BOX:
			if (tbType == BOX) return boxCollison(tb);
			else if (tbType == CYLINDER) return boxCylinderCollision(tb);
			else if (tbType == SPHERE) return boxSphereCollision(tb);
			break;
		case CYLINDER:
			if (tbType == BOX) return tb.boxCylinderCollision(*(this));
			else if (tbType == CYLINDER) return cylinderCollision(tb);
			else if (tbType == SPHERE) return cylinderSphereCollision(tb);
			break;
		case SPHERE:
			if (tbType == BOX) return tb.boxSphereCollision(*(this));
			else if (tbType == CYLINDER) tb.cylinderSphereCollision(*(this));
			else if (tbType == SPHERE) sphereCollision(tb);
			break;
		default: return false; 
	}
}*/