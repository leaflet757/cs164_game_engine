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
#include "Level.h"

#include "Camera.h"
#include "Cube.h"
#include "Ball.h"

Graphics* graphics;
IOManager* io;
Camera camera;

// What should be inlucded in this file:
// TODO: List of Levels
std::vector<Level>* levels;
Level* currentLevel;

#define KEY_ESCAPE 27
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_Q 113
#define KEY_E 101
#define KEY_B 98
#define KEY_N 110

int prevTime = 0;
void update()
{
	// Find the time between frames
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = currentTime - prevTime;
	float delta = deltaTime / 1000.0;
	prevTime = currentTime;

	graphics->clear();
	// TODO:
	camera.update(delta);
	//gluLookAt(4, 2, 0, 0, 0, 0, 0, 1, 0);
	//Ticker.update
	graphics->update(delta);
	//physics.update
}

void createTestLevel()
{
	Tile t;
	t.addVert(-1.0, 0.0, 1.0);
	t.addVert(-1.0, 0.0, -1.0);
	t.addVert(1.0, 0.0, -1.0);
	t.addVert(1.0, 0.0, 1.0);
	t.tileID = 0;
	t.neighbors.push_back(1);
	//graphics->add(t);
	Wall w;
	w.setPosition(0, 0, 1);
	//graphics->add(w);
	Wall w2;
	w2.setPosition(1, 0, 0);
	w2.setRotation(0, 90, 0);
	//graphics->add(w2);
	Wall w3;
	w3.setPosition(0, 0, 0);
	w3.setPosition(-1, 0, 0);
	w3.setRotation(0, 90, 0);
	//graphics->add(w3);
	Tile p;
	p.addVert(-1.0, 0.0, 1.0);
	p.addVert(-1.0, 0.0, -1.0);
	p.addVert(1.0, 0.0, -1.0);
	p.addVert(1.0, 0.0, 1.0);
	p.tileID = 1;
	p.setPosition(0, 0, -2);
	//graphics->add(p);
	Tile q;
	q.addVert(-1.0, 0.0, 1.0);
	q.addVert(-1.0, 0.0, -1.0);
	q.addVert(1.0, 0.0, -1.0);
	q.addVert(1.0, 0.0, 1.0);
	q.setPosition(-2, 0, -2);
	q.tileID = 2;
	//graphics->add(q);
	Wall w4;
	w4.setPosition(2, 0, -1);
	//graphics->add(w4);
	Wall w5;
	w5.setPosition(3, 0, -2);
	w5.setRotation(0, 90, 0);
	//graphics->add(w5);
	Wall w6;
	w6.setPosition(0, 0, 0);
	w6.setPosition(2, 0, -3);
	//graphics->add(w6);
	Tile r;
	r.addVert(-1.0, 0.0, 1.0);
	r.addVert(-1.0, 0.0, -1.0);
	r.addVert(1.0, 0.0, -1.0);
	r.addVert(1.0, 0.0, 1.0);
	r.setPosition(2, 0, -2);
	r.tileID = 3;
	//graphics->add(r);
	Wall w7;
	w7.setPosition(-2, 0, -1);
	//graphics->add(w7);
	Wall w8;
	w8.setPosition(-3, 0, -2);
	w8.setRotation(0, 90, 0);
	//graphics->add(w8);
	Wall w9;
	w9.setPosition(0, 0, 0);
	w9.setPosition(-2, 0, -3);
	//graphics->add(w9);
	Wall w10;
	w10.setPosition(0, 0, -3);
	//graphics->add(w10);
	Tee tee;
	tee.setPosition(0, 0.001, 0);
	//graphics->add(tee);
	Cup cup;
	cup.setPosition(-2, 0.0001, -2);
	//graphics->add(cup);
	currentLevel = new Level();
	currentLevel->addTile(t);
	currentLevel->addTile(p);
	currentLevel->addTile(q);
	currentLevel->addTile(r);
	currentLevel->setCup(cup);
	currentLevel->setTee(tee);
	currentLevel->addWall(w);
	currentLevel->addWall(w2);
	currentLevel->addWall(w3);
	currentLevel->addWall(w4);
	currentLevel->addWall(w5);
	currentLevel->addWall(w6);
	currentLevel->addWall(w7);
	currentLevel->addWall(w8);
	currentLevel->addWall(w9);
	currentLevel->addWall(w10);
}

void initialize(int argc, char **argv)
{
	graphics = new Graphics(argc, argv);

	//TODO: add option to change window Size
	graphics->createWindow();

	graphics->init();

	// Set-up camera
	camera = Camera(4, 2, 0, 0, 0, 0, 0, 1, 0);

	// Load Levels
	io = new IOManager();
	//levels = io->loadLevels(argc, argv);

	Ball ball;
	graphics->add(ball);

	// Debug
	createTestLevel();
	
	// TODO: initialize Keyboard

}

int mPrevx;
int mPrevy;
void keyboard(unsigned char key, int mousePositionX, int mousePositionY)
{
	// TODO: we will probably want our own input manager but this is ok for now
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
		graphics->remove(currentLevel->cupStore);
		graphics->remove(currentLevel->teeStore);
		for (Tile& i : currentLevel->tilesStore)
		{
			graphics->remove(i);
		}
		for (Wall& i : currentLevel->wallsStore)
		{
			graphics->remove(i);
		}
		break;
	case KEY_N:
		// next Level
		std::cout << "Next Level" << std::endl;
		graphics->add(currentLevel->cupStore);
		graphics->add(currentLevel->teeStore);
		for (Tile& i : currentLevel->tilesStore)
		{
			graphics->add(i);
		}
		for (Wall& i : currentLevel->wallsStore)
		{
			graphics->add(i);
		}
		break;
	default:
		break;
	}
}

void mouse_event(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		mPrevx = x;
		mPrevy = y;
		printf("Right button down \n");
		if (x < mPrevx)
		{
			// left
		}
		if (x > mPrevx)
		{
			// right
		}
		if (y < mPrevy)
		{
			// down
		}
		if (y > mPrevy)
		{
			// up
		}
		mPrevx = x;
		mPrevy = y;
	}
}

int main(int argc, char **argv)
{
	// initialize and run program
	initialize(argc, argv);
	glutDisplayFunc(update);						// register Display Function
	glutIdleFunc(update);						// register Idle Function
	glutKeyboardFunc(keyboard);						// register Keyboard Handler
	glutMouseFunc(mouse_event);
	//TODO: glutReshap
	
	glutMainLoop();							// run GLUT mainloop
	
	//graphics.destroy()
	delete graphics;
	return 0;
}
