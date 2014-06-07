#include "HUDElement.h"


HUDElement::HUDElement() :
position(0),
backgroundColor(0),
visible(true)
{
}


HUDElement::HUDElement(const HUDElement& copy) :
position(copy.position),
backgroundColor(copy.backgroundColor),
visible(copy.visible)
{
}

HUDElement::~HUDElement()
{
}

void HUDElement::hide()
{
	visible = false;
}

void HUDElement::show()
{
	visible = true;
}

HUDElement& HUDElement::operator=(const HUDElement& other)
{
	position = other.position;
	backgroundColor = other.backgroundColor;

	return *this;
}

void HUDElement::setBackgroundColor(float r, float g, float b)
{
	backgroundColor.r = r;
	backgroundColor.g = g;
	backgroundColor.b = b;
}