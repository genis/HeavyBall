#include "cScene.h"
#include "Globals.h"
#include <ctime>

cScene::cScene(void) {}
cScene::~cScene(void)
{
	lightingShader.deleteShader();
}

bool cScene::Init()
{
	surface.generate(SCENE_WIDTH, SCENE_DEPTH, SCENE_HEIGHT, SCENE_WIDTH/6,time(0));
	lightingShader = Shader("./shaders/fragmentLighting.vert", NULL, "./shaders/fragmentLighting.frag");
	lightingShader.printLog();
	return true;
}

void cScene::setLighting()
{

}

void cScene::setCam()
{
	gluLookAt(50, 100, -200, 0, 0, 0, 0, 1, 0);
}

void cScene::Draw(cData *Data)
{
	
	glTranslatef(-float(SCENE_WIDTH/2), 0.0f, -float(SCENE_DEPTH/2));
	glColor3f(0.0f, 1.0f, 0.0f);
	lightingShader.enable();
	surface.draw();
	lightingShader.disable();
}