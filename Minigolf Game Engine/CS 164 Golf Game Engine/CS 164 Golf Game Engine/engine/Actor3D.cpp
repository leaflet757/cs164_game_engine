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
	isWall = false;
}

Actor3D::Actor3D(const Actor3D& copy) :
id(copy.id),
useCustomDraw(copy.useCustomDraw),
position(copy.position),
rotation(copy.rotation),
scale(copy.scale),
color(copy.color),
normals(copy.normals)
{
	_isDrawable = copy.isDrawable();
	isWall = copy.isWall;
	verts = copy.verts;
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

void Actor3D::addVert(float x, float y, float z)
{
	verts.push_back(glm::vec3(x, y, z));

	if (verts.size() == 3)
	{
		glm::vec3 & v1 = verts[0];
		glm::vec3 & v2 = verts[1];
		glm::vec3 & v3 = verts[2];

		glm::vec3 d2 = v1 - v2;
		glm::vec3 d1 = v1 - v3;

		glm::vec3 n(0);
		n.x = (d1.y * d2.z) - (d1.z * d2.y);
		n.y = -1 * ((d1.x * d2.z) - (d1.z * d2.x));
		n.z = (d1.x * d2.y) - (d1.y * d2.x);

		normals = n;
	}
}