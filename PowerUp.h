#pragma once
#include "Object.h"
class PowerUp : public Object
{
public:
	PowerUp(void);
	~PowerUp(void);

	bool collides(const Object& o) const;
	bool collidesPoint(const Point& p) const;
};

