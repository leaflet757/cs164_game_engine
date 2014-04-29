#include "Wall.h"


Wall::Wall()
{
	_isDrawable = true;

	x1 = std::vector<float>();
	x1.push_back(0);
	y1 = std::vector<float>();
	y1.push_back(0);
	z1 = std::vector<float>();
	z1.push_back(0);
	x2 = std::vector<float>();
	x2.push_back(0);
	y2 = std::vector<float>();
	y2.push_back(0);
	z2 = std::vector<float>();
	z2.push_back(0);
}


Wall::~Wall()
{
}
