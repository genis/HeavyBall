#pragma once

#include "cData.h"
#include "Surface3d.h"
#include "Point.h"
#include "Camera.h"
#include "Sphere.h"
#include "Player.h"

class cScene
{
private:
	static const int SCENE_WIDTH = 100;
	static const int SCENE_DEPTH = 100;
	static const int SCENE_HEIGHT = 10;
	static const int P = 5;

	Surface3d surface;

	Shader lightingShader;

	vector<Camera> cams;
	vector<Player> players;

	Point sun;
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

	void Draw(cData *Data);
};
