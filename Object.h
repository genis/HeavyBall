#pragma once
#include "Model.h"
#include "Vector.h"
#include "Point.h"
#include "Boundary.h"
#include "Shader.h"
#include "Quaternion.h"

class Object
{
public:
	enum CollisionDetectorType{SPHERE, CILINDER, BOX};

	Object(void);
	Object(Model* model);
	virtual ~Object(void);

	void setPosition(const Point& p);
	void setRotation(const Quaternion& q);
	
	void translate(const Vector& t);
	void rotate(const Quaternion& q);

	bool collides(const Object& o) const;
	
	Boundary* getBoundary(void) const;

	void draw(void) const;

protected:
	Model* model;
private:
	Vector translation;
	Quaternion rotation;

	//Boundaries are in worldspace
	Boundary* b;
};

