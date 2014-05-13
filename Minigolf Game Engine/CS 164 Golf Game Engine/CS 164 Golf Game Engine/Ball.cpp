#include "Ball.h"


Ball::Ball()
{
	_isDrawable = true;
	_isMover = true;
	_isCollisionObject = true;
	useCustomDraw = true;
	radius = 0.1;
	tileLocation = nullptr;
}

Ball::~Ball()
{
}

void Ball::draw() const
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScaled(scale.x, scale.y, scale.z);
	glTranslated(position.x, position.y, position.z);
	glRotated(rotation.x, 1.0, 0.0, 0.0);
	glRotated(rotation.y, 0.0, 1.0, 0.0);
	glRotated(rotation.z, 0.0, 0.0, 1.0);
	glutSolidSphere(radius, 8, 8);
	glPopMatrix();
}

void Ball::tick(float delta) const
{
	
}

void Ball::setTileLocation(Tile & tile)
{
	tileLocation = &tile;
}