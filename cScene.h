#pragma once

#include "cData.h"
#include "Surface3d.h"
#include "Point.h"
#include "Camera.h"

class cScene
{
private:
	static const int SCENE_WIDTH = 100;
	static const int SCENE_DEPTH = 100;
	static const int SCENE_HEIGHT = 10;

	Surface3d surface;

	Shader lightingShader;

	Camera cam;

	Point sun;


public:
	cScene(void);
	virtual ~cScene(void);

	bool Init();

	void setLighting();

	void setCam(void);
	void moveCam(float x, float y, float z);
	void rotateCam(float rx, float ry, float rz);

	void Draw(cData *Data);
};
