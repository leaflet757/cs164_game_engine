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
// TODO: Curent level

#define KEY_ESCAPE 27
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_Q 113
#define KEY_E 101

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
	levels = io->loadLevels(argc, argv);

	for (int i = 0; i < levels->size(); i++)
	{
		// add each tile to graphcis
	}

	// TODO: Initialize Actors
	Cube t;
	graphics->add(t);
	Cube a;
	a.setPosition(1, 0, 0);
	graphics->add(a);
	Cube s;
	s.setPosition(-1,0,0);
	graphics->add(s);
	Cube d;
	d.setPosition(0, -1, 0);
	graphics->add(d);
	Cube r;
	r.setPosition(0, 1, 0);
	graphics->add(r);
	Ball b;
	graphics->add(b);
	// TODO: initialize Keyboard

}

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
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	// initialize and run program
	initialize(argc, argv);
	glutDisplayFunc(update);						// register Display Function
	glutIdleFunc(update);						// register Idle Function
	glutKeyboardFunc(keyboard);						// register Keyboard Handler
	//TODO: glutReshap
	
	glutMainLoop();							// run GLUT mainloop
	
	//graphics.destroy()
	delete graphics;
	return 0;
}
