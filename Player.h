#pragma once
#include "Vector.h"
#include "Surface3d.h"
#include "FisicEngine.h"
#include "cData.h"

class Player
{
public:
	Player(void);
	~Player(void);
	void mou(Vector d);

private:
	Sphere* sphere;
	float push;
};

