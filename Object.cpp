#include "Object.h"

Object::Object(void)
{
}

Object::Object(Model* model)
{
	this->model = model;
}

Object::~Object(void)
{
}

void Object::setPosition(const Point& p)
{
	translation = p;
}

void Object::setRotation(const Quaternion& q)
{
	rotation = q;
}

void Object::translate(const Vector& v)
{
	translation += v;
}

void Object::rotate(const Quaternion& q)
{
	rotation *= q;
}

Boundary* Object::getBoundary(void) const
{
	return b;
}

bool Object::collides(const Object& o) const
{
	//return b->collides(*(o.getBoundary()));
	return b->collides();
}

void Object::draw(void) const
{
	glPushMatrix();
		//Rotate
		glTranslatef(translation.x, translation.y, translation.z);
	glPopMatrix();
}