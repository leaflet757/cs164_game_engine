#include "Tile.h"


Tile::Tile()
{
	_isDrawable = true;

	x = std::vector<float>();
	y = std::vector<float>();
	z = std::vector<float>();
	neighbors = std::vector<int>();
}


Tile::~Tile()
{
}
