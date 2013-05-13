#pragma once
#include <vector>
#include <list>
#include "Vector.h"
#include "Surface3d.h"
#include "Sphere.h"
#include "Camera.h"
#include "Flag.h"
#include "PowerUp.h"

#define GRAVITY		9.8
//#define RADI		2
//#define MASSA		3
//#define FORCE		50 // Amb un angle de 60º no te prou força per avançar mes

class FisicEngine
{
	
public:
	FisicEngine(void);
	FisicEngine(Surface3d* surface, vector<Sphere*>* spheres, vector<Camera*>* cams, 
									list<Flag*>* flags, list<PowerUp*>* powerUps);

	~FisicEngine(void);

	void process(void);
	
	void addPowerUp(PowerUp* powerUp);
	void addFlag(Flag* flag);
	
private:
	Surface3d* surface;

	//i-th camera follows i-th sphere
	vector<Sphere*>* spheres;
	vector<Camera*>* cams;
	
	//this vector should only have one flag. the pourpouse of
	//a list here is a posible expancion where multiple
	//flags are allowed.
	list<Flag*>* flags;
	list<PowerUp*>* powerUps;

	void calculatePhisics(void);
	void moveCameras(void);
	void checkFlags(void);
	void checkPowerUps(void);

	Vector acceleracio(float M, float R, Vector position, Vector externalForce);
	
};

