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
	gluPerspective(45.0,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,0.1,200);
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
	res = Scene.Init(1);

	start = false;
	
	return res;
}

bool cGame::Loop()
{
	bool res=true;

	int t1, t2;
	t1 = glutGet(GLUT_ELAPSED_TIME);

	res = Process();
	if(res) Render();

	do { t2 = glutGet(GLUT_ELAPSED_TIME);
	} while (t2 - t1 < 10); //el 10 es pot canviar x mes rapid o mes lent
	
	return res;
}

void cGame::Finalize()
{
}

//Input
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	keys[key] = press;
	if((keys['a'] || keys['s'] || keys['d'] || keys['w']) && !start) start = true;
}

void cGame::ReadMouse(int x, int y)
{
	newX = x;
	newY = y;
}

//Process
bool cGame::Process()
{
	bool res=true;
	
	//Process Input
	if(keys[27])	res=false;	
	
	if (keys['q']) Scene.moveCam(0.0f, 0.0f, 1.0f);
	else if (keys['e']) Scene.moveCam(0.0f, 0.0f, -1.0f);

	if (keys['j']) Scene.rotateCam(0.0f, -1.0f, 0.0f);
	else if (keys['l']) Scene.rotateCam(0.0f, 1.0f, 0.0f);
	else if (keys['k']) Scene.rotateCam(1.0f, 0.0f, 0.0f);
	else if (keys['i']) Scene.rotateCam(-1.0f, 0.0f, 0.0f);
	
	Vector aux(0.0f, 0.0f, 0.0f);
	if (keys['s']) aux += Vector(0.0f, 0.0f, -0.2f);
	else if (keys['w']) aux += Vector(0.0f, 0.0f, 0.2f);
	if (keys['a']) aux += Vector(0.2f, 0.0f, 0.0f);
	else if (keys['d']) aux += Vector(-0.2f, 0.0f, 0.0f);


	if (keys['g']) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (keys['h']) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (newX > oldX) Scene.rotateCam(0.0, 1.0, 0.0);
	else if (newX < oldX) Scene.rotateCam(0.0, -1.0, 0.0);
	oldX = newX;

	if (newY > oldY) Scene.rotateCam(1.0, 0.0, 0.0);
	else if (newY < oldY) Scene.rotateCam(-1.0, 0.0, 0.0);
	oldY = newY;

	if(newY < 80 || newY > SCREEN_HEIGHT - 80 || newX < 80 || newX > SCREEN_WIDTH - 80) { 
		glutWarpPointer(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
	}

	if(keys['a'] || keys['s'] || keys['d'] || keys['w']){
	Scene.moveSphere(aux);
	Scene.process();
	}
	return res;
}

//Output
void cGame::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Scene.setCam();
	Scene.Draw(&Data);

	glutSwapBuffers();
}
