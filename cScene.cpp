#include "cScene.h"
#include "Globals.h"
#include <ctime>
#include <iostream>

cScene::cScene(void) 
{
}
cScene::~cScene(void)
{
	lightingShader.deleteShader(); 
}

bool cScene::Init()
{
	surface.generate(SCENE_WIDTH, SCENE_DEPTH, SCENE_HEIGHT, SCENE_WIDTH/P, time(0));
	lightingShader = Shader("./shaders/fragmentLighting.vert", NULL, "./shaders/fragmentLighting.frag");
	lightingShader.printLog();
	return true;
}

void cScene::setLighting()
{
	GLfloat lightPos[4] = {100.0f, 100.0f, 100.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

void cScene::setCam()
{
	//gluLookAt(50, 100, 100, 0, 0, 0, 0, -1, 0);
	cam.setUp();
}

void cScene::moveCam(float x, float y, float z)
{
	cam.move(Vector(x, y, z));
}

void cScene::rotateCam(float rx, float ry, float rz)
{
	cam.rotate(rx, ry, rz);
}

void cScene::moveSphere(Vector t)
{
	Point p = s.getPosition();
	p += (t*0.2);

	p.y = surface.getHeight(p.x, p.z);
	s.setSphere(p, 0.0, 0.0, 0.0);
	//cam.move(Vector(t));
	//cam.setVrp(p);

}

void cScene::Draw(cData *Data)
{
	setLighting();

	lightingShader.enable();
	
	glPushMatrix();
		glTranslatef(-float(SCENE_WIDTH/2), 0.0f, -float(SCENE_DEPTH/2));
		surface.draw();
		s.draw();
	glPopMatrix();

	lightingShader.disable();
}