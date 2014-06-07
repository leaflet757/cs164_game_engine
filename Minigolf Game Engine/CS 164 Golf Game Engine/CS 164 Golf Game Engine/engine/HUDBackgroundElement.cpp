#include "HUDBackgroundElement.h"


HUDBackgroundElement::HUDBackgroundElement()
{
	backgroundColor.r = 6.0;
	backgroundColor.g = 3.0;
	backgroundColor.b = 0.0;

	width = 640;
	height = 30;
}


HUDBackgroundElement::~HUDBackgroundElement()
{
}

void HUDBackgroundElement::update(LevelManager* levelManager)
{
	// TODO: remove
	glBegin(GL_QUADS);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(0.0, 0.0);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(width, 0.0);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(width, height);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(0.0, height);
	glEnd();
}
