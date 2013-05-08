#include "Player.h"


Player::Player(void)
{
	push = 0;
}


Player::~Player(void)
{
}

void Player::mou(Vector d)
{
	d.normalize();
	this->sphere->setExternalForce(d*push);
}

