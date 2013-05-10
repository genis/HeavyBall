#include "Player.h"
#include <cstdlib>

Player::Player(void)
{
	push = 0.0;
}

void Player::setPush(float push)
{
	this->push = push;
}

Player::~Player(void)
{
}

void Player::setRandomPowerUp(void) 
{
	powerUp = PowerUpType(rand()%PowerUpType::POWERUP_COUNT);
}

void Player::mou(Vector d)
{
	d.normalize();
	sphere->setExternalForce(d*push);
}

