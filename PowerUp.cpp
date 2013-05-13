#include "PowerUp.h"


PowerUp::PowerUp(void)
{
}

PowerUp::~PowerUp(void)
{
}

bool PowerUp::collides(const Object& o) const
{
	return false;
}

bool PowerUp::collidesPoint(const Point& p) const
{
	return false;
}