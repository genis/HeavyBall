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
	void mou(Vector grad, Vector normal, unsigned char keys[256]);
	void render(cData *Data);

private:
	Vector posicio;
	FisicEngine fisic;


};

