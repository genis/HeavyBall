#include "FisicEngine.h"
#include <math.h>


FisicEngine::FisicEngine(void)
{
}


FisicEngine::~FisicEngine(void)
{
}

Vector FisicEngine::acceleracio(Vector normal, float theta, Vector F, float M, float R, float mu)
{
	//a = (M*GRAVITY * sin(theta)) / M + I/R^2
	//I =(2*M * R^2) / 5

	float a = (M*GRAVITY * sin(theta)) / (M + (0.4*M));
	Vector g = Vector(normal.x, 0.0, normal.z) * a;
	Vector f = Vector();

	return (g+f);
}
