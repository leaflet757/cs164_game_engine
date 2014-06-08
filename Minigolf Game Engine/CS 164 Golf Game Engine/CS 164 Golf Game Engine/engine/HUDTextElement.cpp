#include "HUDTextElement.h"


HUDTextElement::HUDTextElement()
{
	text = "";
}

HUDTextElement::HUDTextElement(float x, float y)
{
	position.x = x;
	position.y = y;
}

HUDTextElement::~HUDTextElement()
{
}

void HUDTextElement::update(LevelManager* levelManager)
{
	if (hasDynamicElements)
	{
		int level = levelManager->getLevelNumber();
		text = "Course: " + std::to_string(levelManager->getLevelNumber());
	}

	glColor3f(0.0f, 0.0f, 255.0f);//needs to be called before RasterPos
	glRasterPos2i(position.x, position.y);
	void * font = GLUT_BITMAP_9_BY_15;

	for (std::string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	} 
}

void HUDTextElement::setText(std::string str)
{
	text = str;
}