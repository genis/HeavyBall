#include "FisicEngine.h"
#include <math.h>


FisicEngine::FisicEngine(void)
{
}


FisicEngine::~FisicEngine(void)
{
}

Vector FisicEngine::acceleracio(Vector grad, Vector normal, unsigned char keys[256])
{
	float angle = getAngle(grad, normal); //Obtenim l'angle amb el pla
	float forceDown = MASSA * GRAVITY * sin(angle); //Calculem la força que fa cap avall
	grad.normalize(); //Agafem el vector unitari
	Vector forceButtons(0,0,0);
	if (keys['s']) {
		if (keys['a']){
			forceButtons.x += 15;
			forceButtons.z += 15;
		}
		else if (keys['d']){
			forceButtons.x -= 15;
			forceButtons.z += 15;
		}
		else 
			forceButtons.z += 30;
	}
	if (keys['w']) {
		if (keys['a']){
			forceButtons.x += 15;
			forceButtons.z -= 15;
		}
		else if (keys['d']){
			forceButtons.x -= 15;
			forceButtons.z -= 15;
		}
		else 
			forceButtons.z -= 30;
	}
	if (keys['a']) forceButtons.x += 15;
	else if (keys['d']) forceButtons.x -= 15;
	
	float finalForce = 0; //Calculem la força resultant de sumarli la que estem fent amb els botons
	Vector forces(grad.x * forceDown - forceButtons.x, 
		grad.y * forceDown - forceButtons.y, 
		grad.z * forceDown - forceButtons.z); //Sumem la força final al vector unitari
	return forces;
}

float FisicEngine::getAngle(Vector grad, Vector normal)
{
	float length = sqrt(grad.x*grad.x + grad.y*grad.y + grad.z*grad.z) + 
		sqrt(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
	return acosf(grad.dotProd(normal)/length);
}