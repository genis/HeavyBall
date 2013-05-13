#pragma once

#include <list>
#include "cData.h"
#include "Surface3d.h"
#include "Point.h"
#include "Camera.h"
#include "Sphere.h"
#include "Player.h"
#include "Flag.h"
#include "PowerUp.h"
#include "FisicEngine.h"
#include "ShaderManager.h"
#include "ModelManager.h"

class cScene
{
private:
	static const int SCENE_WIDTH = 200;
	static const int SCENE_DEPTH = 200;
	static const int SCENE_HEIGHT = 10;
	static const int P = 20;

	Surface3d surface;

	ShaderManager shaderManager;
	ModelManager modelManager; 

	vector<Camera*> cams;
	vector<Sphere*> spheres;
	vector<Player*> players;

	list<PowerUp*> powerUps;
	list<Flag*> flags;

	FisicEngine phisicsEngine;

	Camera cam;

	Sphere s;

public:
	cScene(void);
	virtual ~cScene(void);

	bool Init(int numPlayers);

	void setLighting();

	void setCam(void);
	void moveCam(float x, float y, float z);
	void rotateCam(float rx, float ry, float rz);

	void moveSphere(Vector t);

	void process(void);

	void Draw(cData *Data);
};
