#include "Player.h"


Player::Player(void)
{
	push = 0.0;
}


Player::~Player(void)
{
}

void Player::mou(Vector d)
{
	d.normalize();
	sphere->setExternalForce(d*push);
}

