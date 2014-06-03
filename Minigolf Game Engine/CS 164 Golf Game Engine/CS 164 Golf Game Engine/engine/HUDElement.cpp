#include "HUDElement.h"


HUDElement::HUDElement() :
position(0),
backgroundColor(0)
{
}


HUDElement::HUDElement(const HUDElement& copy) :
position(copy.position),
backgroundColor(copy.backgroundColor)
{
}

HUDElement::~HUDElement()
{
}

void HUDElement::hide()
{

}

void HUDElement::show()
{

}

HUDElement& HUDElement::operator=(const HUDElement& other)
{
	position = other.position;
	backgroundColor = other.backgroundColor;

	return *this;
}