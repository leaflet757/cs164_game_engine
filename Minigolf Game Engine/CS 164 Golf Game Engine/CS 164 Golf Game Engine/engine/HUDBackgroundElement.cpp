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
	glBegin(GL_QUADS);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(position.x, position.y);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(width + position.x, position.y);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(width + position.x, height + position.y);
	glColor3f(backgroundColor.r, backgroundColor.g, backgroundColor.b);
	glVertex2f(position.x, height + position.y);
	glEnd();
}

void HUDBackgroundElement::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}