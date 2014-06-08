#include "HUDElement.h"


HUDElement::HUDElement() :
position(0),
backgroundColor(0),
visible(true),
hasDynamicElements(true)
{
}


HUDElement::HUDElement(const HUDElement& copy) :
position(copy.position),
backgroundColor(copy.backgroundColor),
visible(copy.visible),
hasDynamicElements(copy.hasDynamicElements)
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
	visible = other.visible;
	hasDynamicElements = other.hasDynamicElements;

	return *this;
}

void HUDElement::setBackgroundColor(float r, float g, float b)
{
	backgroundColor.r = r;
	backgroundColor.g = g;
	backgroundColor.b = b;
}

void HUDElement::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void HUDElement::setDynamicElements(bool state)
{
	hasDynamicElements = state;
}