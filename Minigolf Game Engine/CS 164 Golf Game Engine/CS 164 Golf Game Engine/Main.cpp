// CS 164 Golf Game Engine
// Leif Myer
// Jonah Nobleza

#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL\GL.h>		   // Open Graphics Library (OpenGL) header
#include <GL\glut.h>       // The GL Utility Toolkit (GLUT) Header
#include "engine\Graphics.h"

#include "Cube.h"
#include "Ball.h"

Graphics* graphics;

// What should be inlucded in this file:
// TODO: List of Levels
// TODO: Curent level
// TODO: Camera

#define KEY_ESCAPE 27

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
	//camera.update
	gluLookAt(4, 2, 0, 0, 0, 0, 0, 1, 0);
	//Ticker.update
	graphics->update(delta);
	//physics.update
}

void initialize()
{

	graphics->init();

	// TODO: load files

	// TODO: Initialize Actors
	Cube t;
	graphics->add(t);
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

	default:
		break;
	}
}

int main(int argc, char **argv)
{
	graphics = new Graphics(argc, argv);

	//TODO: add option to change window Size
	graphics->createWindow();

	// initialize and run program
	initialize();
	glutDisplayFunc(update);						// register Display Function
	glutIdleFunc(update);						// register Idle Function
	glutKeyboardFunc(keyboard);						// register Keyboard Handler
	//TODO: glutReshap
	//glutKeyboardFunc(keyboard.update);
	
	glutMainLoop();							// run GLUT mainloop
	
	//graphics.destroy()
	delete graphics;
	return 0;
}
