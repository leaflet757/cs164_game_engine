#include "Cube.h"

Cube::Cube()
{
	_isDrawable = true;

	verts.push_back(glm::vec3(-1.0, 0.0, 1.0));
	verts.push_back(glm::vec3(-1.0, 0.0, -1.0));
	verts.push_back(glm::vec3(1.0, 0.0, -1.0));
	verts.push_back(glm::vec3(1.0, 0.0, 1.0));

	color.push_back(glm::vec3(0.0, 1.0, 0.0));
	color.push_back(glm::vec3(0.0, 1.0, 0.0));
	color.push_back(glm::vec3(0.0, 1.0, 0.0));
	color.push_back(glm::vec3(0.0, 1.0, 0.0));
}


Cube::~Cube()
{
}
