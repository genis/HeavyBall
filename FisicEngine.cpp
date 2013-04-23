#include "FisicEngine.h"
#include <math.h>


FisicEngine::FisicEngine(void)
{
}


FisicEngine::~FisicEngine(void)
{
}

Vector FisicEngine::acceleracio(Vector grad)
{
	float angle = getAngle(grad); //Obtenim l'angle amb el pla
	float forceDown = MASSA * GRAVITY * sin(angle); //Calculem la for�a que fa cap avall
	grad.normalize(); //Agafem el vector unitari
	float finalForce = 0; //Calculem la for�a resultant de sumarli la que estem fent amb els botons
	Vector forces(grad.x * finalForce, 0, grad.z * finalForce); //Sumem la for�a final al vector unitari
	return forces;
}

float FisicEngine::getAngle(Vector grad)
{

}