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
	glColor3f(0.0f, 0.0f, 255.0f);//needs to be called before RasterPos
	glRasterPos2i(position.x, position.y);
	std::string s = "Some text";
	void * font = GLUT_BITMAP_9_BY_15;

	for (std::string::iterator i = s.begin(); i != s.end(); ++i)
	{
		char c = *i;
		//this does nothing, color is fixed for Bitmaps when calling glRasterPos
		//glColor3f(1.0, 0.0, 1.0); 
		glutBitmapCharacter(font, c);
	} 
}

void HUDTextElement::setText(std::string str)
{
	text = str;
}