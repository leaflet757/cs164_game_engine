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
	glPushMatrix();
	glColor3b(1, 0.5, 0);
	glTranslatef(0, 0.1, 0);
	glutSolidSphere(0.1, 8, 8);
	glPopMatrix();
}

void Ball::tick(float delta) const
{
	std::cout << "The ball is ticking" << std::endl;
}