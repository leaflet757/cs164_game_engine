#include "Ball.h"


Ball::Ball()
{
	_isDrawable = true;
	useCustomDraw = true;
}


Ball::~Ball()
{
}

void Ball::draw() const
{
	glColor3b(1, 0, 0);
	glutSolidSphere(1, 8, 8);
}