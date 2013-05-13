#pragma once
#include "Vector.h"
#include "Surface3d.h"
#include "FisicEngine.h"
#include "cData.h"
#include "Camera.h"

class Player
{
public:
	Player(void);
	~Player(void);
	void setPush(float push);
	void setRandomPowerUp(void);

	void mou(Vector d);

private:

	enum PowerUpType {SPEED, TELE, POWERUP_COUNT}; 
	
	Sphere* sphere;
	Camera* cam;

	PowerUpType powerUp;

	float push;

	int team;

};

