#include "Actor3D.h"

int Actor3D::idnumber = 0;

Actor3D::Actor3D() :
id(++idnumber),
_isDrawable(false),
useCustomDraw(false),
position(0.0),
rotation(0.0),
scale(1.0, 1.0, 1.0),
verts(),
color(),
normals()
{
}

Actor3D::Actor3D(const Actor3D& copy) :
id(copy.id),
_isDrawable(copy._isDrawable),
useCustomDraw(copy.useCustomDraw),
position(copy.position),
rotation(copy.rotation),
verts(copy.verts),
color(copy.color),
normals(copy.normals)
{
}

Actor3D::~Actor3D()
{
	// Unneeded for now
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