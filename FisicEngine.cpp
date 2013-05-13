#include "FisicEngine.h"
#include <math.h>

typedef vector<Sphere*>::iterator VSit;
typedef	list<Flag*>::iterator LFit;
typedef list<PowerUp*>::iterator LPit;

FisicEngine::FisicEngine(void)
{
}

FisicEngine::FisicEngine(Surface3d* surface, vector<Sphere*>* spheres, vector<Camera*>* cams,
											 list<Flag*>* flags, list<PowerUp*>* powerUps)
{
	this->surface = surface;
	this->spheres = spheres;
	this->cams = cams;
	this->flags = flags;
	this->powerUps = powerUps;
}

FisicEngine::~FisicEngine(void)
{
}

void FisicEngine::calculatePhisics(void)
{
	for (VSit it = spheres->begin(); it != spheres->end(); ++it) {
		Vector aux = acceleracio((*it)->getMass(), (*it)->getRadius(), (*it)->getPosition(), (*it)->getExternalForce());
		Vector newVel = (*it)->getVelocity() + aux; //calculem la nova velocitat a partir de l'anterior i l'acceleracio
		(*it)->setVelocity(newVel); //guardem la nova velocitat
		(*it)->move(newVel); //Movem l'esfera amb la nova velocitat
	}	
}

void FisicEngine::moveCameras(void)
{
	//i-th camera follows i-th sphere 
	for (int i = 0; i < cams->size(); ++i) {
		if ((*cams)[i]->isEnabled()) {

		}
	}
}

void FisicEngine::checkFlags(void)
{
	for (LFit fit = flags->begin(); fit != flags->end(); ++fit) {
		for (VSit sit = spheres->begin(); sit != spheres->end(); ++sit) {
			if ((*fit)->collides(**sit)) {
				//update scores
				//kill flag
			}
		}
	}
}

void FisicEngine::checkPowerUps(void)
{
	for (LPit uit = powerUps->begin(); uit != powerUps->end(); ++uit) {
		for (VSit sit = spheres->begin(); sit != spheres->end(); ++sit) {
			if ((*uit)->collides(**sit)) {
				//update Object powerUp
				//kill powerUp
			}
		}
	}	
}

void FisicEngine::process(void)
{
	calculatePhisics();
	checkFlags();
	checkPowerUps();
	moveCameras();
}

Vector FisicEngine::acceleracio(float M, float R, Vector position, Vector externalForce)
{
	//a = (M*GRAVITY * sin(theta)) / M + I/R^2
	//I =(2*M * R^2) / 5
	Vector normal = surface->getNormal(position.x, position.z);

	float a = (M*GRAVITY * sin(surface->getTheta(position.x, position.z))) / (M + (0.4*M));
	Vector g = Vector(normal.x, 0.0, normal.z) * a;
	externalForce /= M;

	return (g + externalForce);
}
