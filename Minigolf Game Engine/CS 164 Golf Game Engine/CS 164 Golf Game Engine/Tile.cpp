#include "Tile.h"


Tile::Tile()
{
	_isDrawable = true;

	x = std::vector<float>();
	y = std::vector<float>();
	z = std::vector<float>();
	neighbors = std::vector<int>();
	xyz = std::vector<glm::vec3>(); //will hold xyz vec3 just in case. comment out later.

	color.push_back(glm::vec3(0.0, 1.0, 0.0));
	color.push_back(glm::vec3(0.0, 1.0, 0.0));
	color.push_back(glm::vec3(0.0, 1.0, 0.0));
	color.push_back(glm::vec3(0.0, 1.0, 0.0));
}


Tile::~Tile()
{
}
