#include "Tee.h"


Tee::Tee()
{
	_isDrawable = true;

	verts.push_back(glm::vec3(-0.2, 0.0, 0.2));
	verts.push_back(glm::vec3(-0.2, 0.0, -0.2));
	verts.push_back(glm::vec3(0.2, 0.0, -0.2));
	verts.push_back(glm::vec3(0.2, 0.0, 0.2));

	color.push_back(glm::vec3(0.0, 0.0, 1.0));
	color.push_back(glm::vec3(0.0, 0.0, 1.0));
	color.push_back(glm::vec3(0.0, 0.0, 1.0));
	color.push_back(glm::vec3(0.0, 0.0, 1.0));

	tileLocation = nullptr;
}


Tee::~Tee()
{
}

void Tee::setTileLocation(Tile & tile)
{
	tileLocation = &tile;
}