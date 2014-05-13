#include "Cup.h"


Cup::Cup()
{
	_isDrawable = true;

	verts.push_back(glm::vec3(-0.2, 0.0, 0.2));
	verts.push_back(glm::vec3(-0.2, 0.0, -0.2));
	verts.push_back(glm::vec3(0.2, 0.0, -0.2));
	verts.push_back(glm::vec3(0.2, 0.0, 0.2));

	color.push_back(glm::vec3(0.0, 0.0, 0.0));
	color.push_back(glm::vec3(0.0, 0.0, 0.0));
	color.push_back(glm::vec3(0.0, 0.0, 0.0));
	color.push_back(glm::vec3(0.0, 0.0, 0.0));

	tileLocation = nullptr;
}


Cup::~Cup()
{
}

void Cup::setTileLocation(Tile & tile)
{
	tileLocation = &tile;
}