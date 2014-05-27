#include "Tile.h"


Tile::Tile()
{
	_isDrawable = true;
	_isCollisionObject = true;
	_isTile = true;

	x = std::vector<float>();
	y = std::vector<float>();
	z = std::vector<float>();
	neighborID = std::vector<int>();
	neighbors = std::vector<Tile*>();
	xyz = std::vector<glm::vec3>(); //will hold xyz vec3 just in case. comment out later.

	color.push_back(glm::vec3(0.0, 3, 0.0));
	color.push_back(glm::vec3(0.0, 3, 0.0));
	color.push_back(glm::vec3(0.0, 3, 0.0));
	color.push_back(glm::vec3(0.0, 3, 0.0));
}


Tile::~Tile()
{
}

float Tile::getInterpolatedHeight(glm::vec3 v)
{
	

	return 0;
}