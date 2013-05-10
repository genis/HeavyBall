#include "cGame.h"
#include "Globals.h"
#include "Vector.h"

cGame::cGame(void) {}
cGame::~cGame(void){}

bool cGame::Init()
{
	bool res=true;

	//Graphics initialization
	glClearColor(0.4f,0.6f,1.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,0.1,2000);
	glMatrixMode(GL_MODELVIEW);
	
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);

	glAlphaFunc(GL_GREATER, 0.05f);
	glEnable(GL_ALPHA_TEST);

	//Scene initialization
	res = Data.LoadImage(IMG_WALL,"wall.png",GL_RGBA);
	if(!res) return false;
	res = Data.LoadImage(IMG_FLOOR,"floor.png",GL_RGBA);
	if(!res) return false;
	res = Data.LoadImage(IMG_ROOF,"roof.png",GL_RGBA);
	if(!res) return false;
	glewInit();
	res = Scene.Init();
	
	return res;
}

bool cGame::Loop()
{
	bool res=true;

	res = Process();
	if(res) Render();

	return res;
}

void cGame::Finalize()
{
}

//Input
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	keys[key] = press;
}

void cGame::ReadMouse(int x, int y)
{
	dx = x;
}

//Process
bool cGame::Process()
{
	bool res=true;
	
	//Process Input
	if(keys[27])	res=false;	
	
	int t1, t2;

	t1 = glutGet(GLUT_ELAPSED_TIME);

	if (keys['q']) Scene.moveCam(0.0f, 0.0f, 1.0f);
	else if (keys['e']) Scene.moveCam(0.0f, 0.0f, -1.0f);

	if (keys['j']) Scene.rotateCam(0.0f, -1.0f, 0.0f);
	else if (keys['l']) Scene.rotateCam(0.0f, 1.0f, 0.0f);
	else if (keys['k']) Scene.rotateCam(1.0f, 0.0f, 0.0f);
	else if (keys['i']) Scene.rotateCam(-1.0f, 0.0f, 0.0f);
	
	if (keys['a']) Scene.moveSphere(Vector(-1.0f, 0.0f, 0.0f));
	else if (keys['d']) Scene.moveSphere(Vector(1.0f, 0.0f, 0.0f));
	if (keys['s']) Scene.moveSphere(Vector (0.0f, 0.0f, -1.0f));
	else if (keys['w']) Scene.moveSphere(Vector(0.0f, 0.0f, 1.0f));

	if (keys['g']) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (keys['h']) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (dx > SCREEN_WIDTH - 50) Scene.rotateCam(0.0, 1.0, 0.0);
	else if (dx < 50) Scene.rotateCam(0.0, -1.0, 0.0);
	
	do { t2 = glutGet(GLUT_ELAPSED_TIME);
	} while (t2 - t1 < 10); //el 10 es pot canviar x mes rapid o mes lent

	return res;
}

//Output
void cGame::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
//	player.render(&Data);

	Scene.setCam();
	Scene.Draw(&Data);

	glutSwapBuffers();
}
