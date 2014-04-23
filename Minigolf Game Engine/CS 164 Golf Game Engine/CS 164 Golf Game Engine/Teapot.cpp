#include "Teapot.h"


Teapot::Teapot()
{
	
}


Teapot::~Teapot()
{
}

void Teapot::draw()
{
	// TEAPOT!!!!!!!!!!!!!!
	// Push and pop the current matrix stack. 
	// This causes that translations and rotations on this matrix wont influence others.

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, 0);
	glRotatef(90, 0, 1, 0);

	// Draw the teapot
	glutSolidTeapot(1);
	glPopMatrix();
	//!!!!!!!!!!!!!!!!!!!!!!
}