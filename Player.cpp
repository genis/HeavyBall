#include "Player.h"


Player::Player(void)
{
	posicio.x = 0;
	posicio.y = 0;
	posicio.z = 0;
}


Player::~Player(void)
{
}

void Player::mou(Vector grad, Vector normal, unsigned char keys[256])
{
	/*Vector aux = fisic.acceleracio(grad, normal, keys);
	posicio.x -= aux.x;
	posicio.y -= aux.y;
	posicio.z -= aux.z;*/
}

void Player::render(cData *Data)
{
	glPushMatrix();
    glTranslatef(posicio.x, posicio.y, posicio.z);
    glutSolidSphere(0.1,100,100);
    glPopMatrix();
}
