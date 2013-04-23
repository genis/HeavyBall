#pragma once
#include "Vector.h"

#define GRAVITY		9.8
#define RADI		2
#define MASSA		3
#define FORCE		50 // Amb un angle de 60� no te prou for�a per avan�ar mes

class FisicEngine
{
public:
	FisicEngine(void);
	~FisicEngine(void);

	Vector acceleracio(Vector grad);
	
private:
	float getAngle(Vector grad);

};

