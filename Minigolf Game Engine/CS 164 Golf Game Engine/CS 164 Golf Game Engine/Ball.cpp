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
	/*glColor3b(1, 0.5, 0);
	glutSolidSphere(0.1, 8, 8);*/

	std::cout << "The ball is drawing" << std::endl;
}