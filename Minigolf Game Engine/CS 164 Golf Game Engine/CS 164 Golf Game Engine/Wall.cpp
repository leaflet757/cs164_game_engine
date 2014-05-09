#include "Wall.h"


Wall::Wall()
{

	isWall = true;

	_isDrawable = true;
	_isCollisionObject = true;

	x1 = std::vector<float>();
	y1 = std::vector<float>();
	z1 = std::vector<float>();
	x2 = std::vector<float>();
	y2 = std::vector<float>();
	z2 = std::vector<float>();
	xyz_1 = std::vector<glm::vec3>(); //will hold xyz vec3s just in case. comment out later.
	xyz_2 = std::vector<glm::vec3>();

	color.push_back(glm::vec3(3, 0, 0));
	color.push_back(glm::vec3(3, 0, 0));
	color.push_back(glm::vec3(3, 0, 0));
	color.push_back(glm::vec3(3, 0, 0));

	// debug
	addVert(1, 0.5, 0);
	addVert(-1, 0.5, 0);
	addVert(-1, 0, 0);
	addVert(1, 0, 0);

}


Wall::~Wall()
{
}