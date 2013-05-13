#include "cScene.h"
#include "Globals.h"
#include <ctime>
#include <iostream>

cScene::cScene(void) 
{
}
cScene::~cScene(void)
{

	for (int i = 0; i < spheres.size(); ++i) {
		delete spheres[i];
		delete cams[i];
	}

	for (list<Flag*>::iterator it = flags.begin(); it != flags.end(); ++it) {
		delete (*it);
	}

	for (list<PowerUp*>::iterator it = powerUps.begin(); it != powerUps.end(); ++it) {
		delete (*it);
	}
}

bool cScene::Init(int numPlayers)
{
	surface.generate(SCENE_WIDTH, SCENE_DEPTH, SCENE_HEIGHT, P, time(0));
	
	// load shaders
	shaderManager.loadShader("CountorShader", "./shaders/fragmentLighting.vert", NULL, "./shaders/fragmentLighting.frag");

	// load models


	for (int i = 0; i < numPlayers; ++i) {
		spheres.push_back(new Sphere());
		cams.push_back(new Camera());
	}
	
	flags = list<Flag*>();
	powerUps = list<PowerUp*>();

	//setup PhisicsEngine
	phisicsEngine = FisicEngine(&surface, &spheres, &cams, &flags, &powerUps);

	return true;
}

void cScene::setLighting()
{
	GLfloat lightPos[4] = {-100.0f, 100.0f, -100.0f, 1.0f};
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
	Point p = spheres[0]->getPosition();
	p += (t*0.2);

	p.y = surface.getHeight(p.x, p.z);
	spheres[0]->setSphere(p, 0.0, 0.0, 0.0);
	//cam.move(Vector(t));
	//cam.setVrp(p);

}

void cScene::process(void)
{


}

void cScene::Draw(cData *Data)
{
	setLighting();

	Shader* s = shaderManager.getShader("CountorShader");
	s->enable();

	glPushMatrix();
		surface.draw();
		for (int i = 0; i < spheres.size(); ++i) spheres[0]->draw();
	glPopMatrix();

	s->disable();
}