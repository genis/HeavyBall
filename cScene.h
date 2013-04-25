#pragma once

#include "cData.h"
#include "Surface3d.h"
#include "Point.h"

class cScene
{
private:
	static const int SCENE_WIDTH = 100;
	static const int SCENE_DEPTH = 100;
	static const int SCENE_HEIGHT = 20;

	Surface3d surface;

	Shader lightingShader;

	Point sun;


public:
	cScene(void);
	virtual ~cScene(void);

	bool Init();

	void setLighting();

	void setCam();
	void Draw(cData *Data);
};
