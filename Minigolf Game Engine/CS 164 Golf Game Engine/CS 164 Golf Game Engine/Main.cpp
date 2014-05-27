// CS 164 Golf Game Engine
// Leif Myer
// Jonah Nobleza

#include <stdio.h>
#include <iostream>
#include <vector>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL\GL.h>		   // Open Graphics Library (OpenGL) header
#include <GL\glut.h>       // The GL Utility Toolkit (GLUT) Header

#include "engine\Graphics.h"
#include "engine\IOManager.h"
#include "engine\Ticker.h"
#include "engine\Physics.h"
#include "Level.h"

#include "Camera.h"
#include "Cube.h"
#include "Ball.h"

Graphics* graphics;
IOManager* io;
Ticker* ticker;
Physics* physics;

Ball *ball;
float theta;
Tee *tee;
Cup *cup;

Camera camera;

std::vector<Level> *levels;
Level* currentLevel = nullptr;

#define KEY_ESCAPE 27
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_Q 113
#define KEY_E 101
#define KEY_B 98
#define	KEY_SPACE 32
#define KEY_N 110

void cupCheck(float delta)
{
	std::vector<glm::vec3> & v = tee->getVertices();
	float minx1 = min(v[0].x, v[1].x);
	float minx2 = min(v[2].x, v[3].x);
	float minx = min(minx1, minx2);
	float minz1 = min(v[0].z, v[1].z);
	float minz2 = min(v[2].z, v[3].z);
	float minz = min(minz1, minz2);

	float maxx1 = max(v[0].x, v[1].x);
	float maxx2 = max(v[2].x, v[3].x);
	float maxx = max(maxx1, maxx2);
	float maxz1 = max(v[0].z, v[1].z);
	float maxz2 = max(v[2].z, v[3].z);
	float maxz = max(minz1, minz2);

	glm::vec3 & pos = ball->getPosition();
	if (pos.x < maxx && pos.x > minx &&
		pos.z < maxz && pos.z > minz)
	{
		std::cout << "cup hit" << std::endl;
	}
}

int prevTime = 0;
void update()
{
	// Find the time between frames
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = currentTime - prevTime;
	float delta = deltaTime / 1000.0;
	prevTime = currentTime;

	graphics->clear();

	camera.update(delta);
	ticker->update(delta);
	cupCheck(delta);
	physics->update(delta);
	graphics->update(delta);
}

void createTestLevel()
{
	Tile *t = new Tile();
	t->addVert(-1.0, 0.0, 1.0);
	t->addVert(-1.0, 0.0, -1.0);
	t->addVert(1.0, 0.0, -1.0);
	t->addVert(1.0, 0.0, 1.0);
	t->tileID = 0;
	t->neighborID.push_back(1);
	graphics->add(t);
	physics->add(t);
	Wall *w = new Wall();
	w->setPosition(0, 0, 1);
	graphics->add(w);
	physics->add(w);
	Wall *w2 = new Wall();
	w2->setPosition(1, 0, 0);
	w2->setRotation(0, 90, 0);
	graphics->add(w2);
	physics->add(w2);
	Wall *w3 = new Wall();
	w3->setPosition(0, 0, 0);
	w3->setPosition(-1, 0, 0);
	w3->setRotation(0, 90, 0);
	graphics->add(w3);
	physics->add(w3);
	Tile *p = new Tile();
	p->addVert(-1.0, 0.0, 1.0);
	p->addVert(-1.0, 0.0, -1.0);
	p->addVert(1.0, 0.0, -1.0);
	p->addVert(1.0, 0.0, 1.0);
	p->tileID = 1;
	p->setPosition(0, 0, -2);
	graphics->add(p);
	physics->add(p);
	Tile *q = new Tile();
	q->addVert(-1.0, 0.0, 1.0);
	q->addVert(-1.0, 0.0, -1.0);
	q->addVert(1.0, 0.0, -1.0);
	q->addVert(1.0, 0.0, 1.0);
	q->setPosition(-2, 0, -2);
	q->tileID = 2;
	graphics->add(q);
	physics->add(q);
	Wall *w4 = new Wall();
	w4->setPosition(2, 0, -1);
	graphics->add(w4);
	physics->add(w4);
	Wall *w5 = new Wall();
	w5->setPosition(3, 0, -2);
	w5->setRotation(0, 90, 0);
	graphics->add(w5);
	physics->add(w5);
	Wall *w6 = new Wall();
	w6->setPosition(0, 0, 0);
	w6->setPosition(2, 0, -3);
	graphics->add(w6);
	physics->add(w6);
	Tile *r = new Tile();
	r->addVert(-1.0, 0.0, 1.0);
	r->addVert(-1.0, 0.0, -1.0);
	r->addVert(1.0, 0.0, -1.0);
	r->addVert(1.0, 0.0, 1.0);
	r->setPosition(2, 0, -2);
	r->tileID = 3;
	graphics->add(r);
	physics->add(r);
	Wall *w7 = new Wall();
	w7->setPosition(-2, 0, -1);
	graphics->add(w7);
	physics->add(w7);
	Wall *w8 = new Wall();
	w8->setPosition(-3, 0, -2);
	w8->setRotation(0, 90, 0);
	graphics->add(w8);
	physics->add(w8);
	Wall *w9 = new Wall();
	w9->setPosition(0, 0, 0);
	w9->setPosition(-2, 0, -3);
	graphics->add(w9);
	physics->add(w9);
	Wall *w10 = new Wall();
	w10->setPosition(0, 0, -3);
	graphics->add(w10);
	physics->add(w10);
	Tee *tee = new Tee();
	tee->setPosition(0, 0.001, 0);
	graphics->add(tee);
	physics->add(tee);
	Cup *cup = new Cup();
	cup->setPosition(-2, 0.0001, -2);
	graphics->add(cup);
	physics->add(cup);
	currentLevel = new Level();
}

void initialize(int argc, char **argv)
{
	theta = 0;

	graphics = new Graphics(argc, argv);

	//TODO: add option to change window Size
	graphics->createWindow();

	graphics->init();

	// Set-up camera
	camera = Camera(4, 2, 0, 0, 0, 0, 0, 1, 0);

	// Load Levels
	io = new IOManager();
	levels = io->loadLevels(argc, argv);
	
	tee = nullptr;
	cup = nullptr;
	for (auto & l = levels->begin(); l < levels->end(); ++l)
	{
		if (currentLevel == nullptr)
		{
			currentLevel = &(*l);
			for (auto & t : l->tilesStore)
			{
				graphics->add(&t);
			}
			for (auto & w : l->wallsStore)
			{
				graphics->add(&w);
			}
			tee = &(l->teeStore);
			cup = &(l->cupStore);
			graphics->add(tee);
			graphics->add(cup);
		}
	}

	// Set up ticker
	ticker = new Ticker();

	// Set up Physics
	physics = new Physics();

	ball = new Ball();
	for (Tile& t : currentLevel->tilesStore)
	{
		Tee& s = currentLevel->teeStore;
		if (t.tileID == s.tID)
		{
			ball->setTileLocation(t);
			ball->setPosition(s.x, s.y + ball->getRadius(), s.z);

			tee->setTileLocation(t);
			tee->setPosition(tee->x, tee->y+0.001, tee->z);

			cup->setTileLocation(t);
			cup->setPosition(cup->x, cup->y + 0.001, cup->z);
		}
	}
	graphics->add(ball);
	physics->add(ball);
	ticker->add(ball);

	// Debug
	//createTestLevel();

	

	
}

int mPrevx;
int mPrevy;
void keyboard(unsigned char key, int mousePositionX, int mousePositionY)
{
	switch (key)
	{
	case KEY_ESCAPE:
		exit(0);
		break;
	case KEY_A:
		std::cout << "A Key Pressed" << std::endl;
		camera.leftMove();
		break;
	case KEY_S:
		std::cout << "S Key Pressed" << std::endl;
		camera.backward();
		break;
	case KEY_D:
		std::cout << "D Key Pressed" << std::endl;
		camera.rightMove();
		break;
	case KEY_W:
		std::cout << "W Key Pressed" << std::endl;
		camera.forward();
		break;
	case KEY_Q:
		std::cout << "Q Key Pressed" << std::endl;
		camera.upMove();
		break;
	case KEY_E:
		std::cout << "E Key Pressed" << std::endl;
		camera.downMove();
		break;
	case KEY_B:
		// previous level if there is one
		
		ball->_isCollisionObject = true;
		std::cout << "B Key Pressed" << std::endl;
		break;
	case KEY_N:
		// next Level
		ball->_isCollisionObject = false;
		std::cout << "N Key Pressed" << std::endl;
		break;
	case 'j':
		theta += 0.05;
		ball->setDirection(sin(theta), 0, -cos(theta));
		std::cout << "J key pressed" << std::endl;
		break;
	case 'k':
		theta -= 0.05;
		ball->setDirection(sin(theta), 0, -cos(theta));
		std::cout << "K key pressed" << std::endl;
		break;
	case 'l':
		ball->power += 0.05;
		std::cout << "L key pressed" << std::endl;
		break;
	case 'm':
		if (ball->power > 0) ball->power -= 0.05;
		std::cout << "M key pressed" << std::endl;
		break;
	case KEY_SPACE: 
	{
		glm::vec3& d = ball->getDirection();
		ball->setVelocity(ball->power * d.x, 0, ball->power * d.z);
		std::cout << "SPACE key pressed" << std::endl;
		break;
	}
	case '1':
		//default view
		std::cout << "1 Key Pressed" << std::endl;
		camera.setPosition(4,2,0);
		camera.setLookAt(0,0,0);
		break;
	case '2':
		//close-up on ball (still needs following logic)
		std::cout << "2 Key Pressed" << std::endl;
		camera.followBall(ball[0].getPosition().x, ball[0].getPosition().y, ball[0].getPosition().z);
		break;
	case '3':
		//top-down
		std::cout << "3 Key Pressed" << std::endl;
		camera.setPosition(1.5,4,0);
		camera.setLookAt(0,0,0);
		break;
	default:
		break;
	}
	
}

bool isDown = false;
void mouse_event(int button, int state, int x, int y)
{
	printf("Right button down \n");
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		isDown = true;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		isDown = false;
	}
}

void mouse_motion(int x, int y)
{
	if (isDown)
	{
		if (x < mPrevx)
		{
			// left
			//camera.tilt(0.1, false, false, true, false);
		}
		if (x > mPrevx)
		{
			// right
			//camera.tilt(0.1, false, false, false, true);
		}
		if (y < mPrevy)
		{
			// down
			camera.tilt(0.1, true, false, false, false);
		}
		if (y > mPrevy)
		{
			// up
			camera.tilt(0.1, false, true, false, false);
		}
	}
	mPrevx = x;
	mPrevy = y;
}

int main(int argc, char **argv)
{
	// initialize and run program

	initialize(argc, argv);
	glutDisplayFunc(update);						// register Display Function
	glutIdleFunc(update);						// register Idle Function
	glutKeyboardFunc(keyboard);						// register Keyboard Handler
	glutMouseFunc(mouse_event);
	glutMotionFunc(mouse_motion);
	
	//TODO: glutReshap
	
	glutMainLoop();							// run GLUT mainloop
	
	delete graphics;
	return 0;
}
