#pragma once

#include "engine\Actor3D.h"

class Wall : public Actor3D
{
public:
	Wall();
	~Wall();

	std::vector<float> x1;
	std::vector<float> y1;
	std::vector<float> z1;
	std::vector<float> x2;
	std::vector<float> y2;
	std::vector<float> z2;
	std::vector<glm::vec3> xyz_1;
	std::vector<glm::vec3> xyz_2;

	void draw() const;
};

