#include "HUDBackgroundElement.h"


HUDBackgroundElement::HUDBackgroundElement()
{
	backgroundColor.r = 1;
	backgroundColor.g = 0;
	backgroundColor.b = 0;
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
	glVertex2f(10.0f, 0.0);
	glVertex2f(10.0f, 10.0f);
	glVertex2f(0.0, 10.0f);
	glEnd();
}
