#include "Tile.h"


Tile::Tile()
{
	_isDrawable = true;

	x = std::vector<float>();
	y = std::vector<float>();
	z = std::vector<float>();
	neighbors = std::vector<int>();
	xyz = std::vector<glm::vec3>(); //will hold xyz vec3 just in case. comment out later.
}


Tile::~Tile()
{
}
