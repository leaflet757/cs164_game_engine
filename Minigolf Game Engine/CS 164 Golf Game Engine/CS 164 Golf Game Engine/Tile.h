#pragma once

#include "engine\Actor3D.h"

class Tile : public Actor3D
{
public:
	Tile();
	~Tile();

	int tileID;
	int edges;

	std::vector<float> x;
	std::vector<float> y;
	std::vector<float> z;
	std::vector<int> neighbors;
	std::vector<glm::vec3> xyz;
};

