#include "Wall.h"


Wall::Wall()
{
	_isDrawable = true;

	x1 = std::vector<float>();
	y1 = std::vector<float>();
	z1 = std::vector<float>();
	x2 = std::vector<float>();
	y2 = std::vector<float>();
	z2 = std::vector<float>();
}


Wall::~Wall()
{
}
