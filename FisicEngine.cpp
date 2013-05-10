#include "FisicEngine.h"
#include <math.h>

typedef vector<Sphere*>::iterator VSit;

FisicEngine::FisicEngine(void)
{
}

FisicEngine::FisicEngine(Surface3d* surface, vector<Sphere*> spheres)
{
	this->surface = surface;
	this->spheres = spheres;
}

FisicEngine::~FisicEngine(void)
{
}

void FisicEngine::process(void)
{
	for (VSit it = spheres.begin(); it != spheres.end(); ++it) {
		Vector aux = acceleracio((*it)->getMass(), (*it)->getRadius(), (*it)->getPosition(), (*it)->getExternalForce());
		Vector newVel = (*it)->getVelocity() + aux; //calculem la nova velocitat a partir de l'anterior i l'acceleracio
		(*it)->setVelocity(newVel); //guardem la nova velocitat
		(*it)->move(newVel); //Movem l'esfera amb la nova velocitat
	}
}

Vector FisicEngine::acceleracio(float M, float R, Vector position, Vector externalForce)
{
	//a = (M*GRAVITY * sin(theta)) / M + I/R^2
	//I =(2*M * R^2) / 5
	Vector normal = (*surface).getNormal(position.x, position.z);

	float a = (M*GRAVITY * sin((*surface).getTheta(position.x, position.z))) / (M + (0.4*M));
	Vector g = Vector(normal.x, 0.0, normal.z) * a;
	externalForce /= M;

	return (g+externalForce);
}
