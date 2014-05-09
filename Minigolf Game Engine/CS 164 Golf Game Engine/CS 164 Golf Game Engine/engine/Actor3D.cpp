#include "Actor3D.h"

int Actor3D::idnumber = 0;

Actor3D::Actor3D() :
id(++idnumber),
_isDrawable(false),
_isMover(false),
_isCollisionObject(false),
_isTile(false),
useCustomDraw(false),
position(0.0),
rotation(0.0),
scale(1.0, 1.0, 1.0),
mass(1),
direction(0.0,0.0,-1.0),
velocity(0.0),
acceleration(0.0),
verts(),
color(),
normals(),
radius(0)
{
	isWall = false;
}

Actor3D::Actor3D(const Actor3D& copy) :
id(copy.id),
useCustomDraw(copy.useCustomDraw),
_isTile(copy._isTile),
position(copy.position),
rotation(copy.rotation),
scale(copy.scale),
mass(copy.mass),
direction(copy.direction),
velocity(copy.velocity),
acceleration(copy.acceleration),
color(copy.color),
normals(copy.normals),
radius(copy.radius)
{
	_isDrawable = copy.isDrawable();
	_isMover = copy.isMover();
	_isCollisionObject = copy.isCollisionObject(),
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

void Actor3D::setVelocity(float x, float y, float z)
{
	velocity.x = x;
	velocity.y = y;
	velocity.z = z;

	direction = velocity;
	float length = sqrt(direction.x*direction.x + 
		direction.y*direction.y + direction.z*direction.z);
	direction.x = direction.x / length;
	direction.y = direction.y / length;
	direction.z = direction.z / length;
}

void Actor3D::setAcceleration(float x, float y, float z)
{
	acceleration.x = x;
	acceleration.y = y;
	acceleration.z = z;
}

Actor3D& Actor3D::operator=(const Actor3D& other)
{
	id = other.id;
	_isDrawable = other.isDrawable();
	_isMover = other.isMover();
	_isTile = other.isTile();
	_isCollisionObject = other.isCollisionObject();
	useCustomDraw = other.useCustomDraw;
	position = other.position;
	rotation = other.rotation;
	scale = other.scale;
	direction = other.direction;
	velocity = other.velocity;
	acceleration = other.acceleration;
	verts = other.verts;
	color = other.color;
	mass = other.mass;
	radius = other.radius;
	normals = other.normals;

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

void Actor3D::setMass(float m)
{
	mass = m;
}

glm::vec3 Actor3D::getDirection() const
{
	float length = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2)
		+ pow(velocity.z, 2));
	return velocity / length;
}