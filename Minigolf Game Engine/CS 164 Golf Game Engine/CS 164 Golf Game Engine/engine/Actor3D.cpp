#include "Actor3D.h"

int Actor3D::idnumber = 0;

Actor3D::Actor3D() :
id(++idnumber),
_isDrawable(false),
position(0.0),
rotation(0.0)
{
}

Actor3D::Actor3D(const Actor3D& copy) :
id(copy.id),
_isDrawable(copy._isDrawable),
position(copy.position),
rotation(copy.rotation)
{
}

Actor3D::~Actor3D()
{
	// Unneeded for now
}

void Actor3D::addVert(glm::vec3 vert)
{
	verts.push_back(vert);
}

void Actor3D::addVert(float x, float y, float z)
{
	glm::vec3 vert;
	vert.x = x;
	vert.y = y;
	vert.z = z;
	verts.push_back(vert);
}

void Actor3D::removeVert(glm::vec3 vert)
{
	int i = 0;
	for (auto v : verts)
	{
		if (v == vert)
		{
			verts.erase(verts.begin() + i);
		}
		i++;
	}
}

void Actor3D::setPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void Actor3D::setRotation(float x, float y, float z)
{
	rotation.x = x;
	rotation.y = y;
	rotation.z = z;
}

Actor3D& Actor3D::operator=(const Actor3D& other)
{
	id = other.id;
	position = other.position;
	rotation = other.rotation;
	return *this;
}