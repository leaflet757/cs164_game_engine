#pragma once

#include "engine\Actor3D.h"

class Wall : public Actor3D
{
public:
	Wall();
	~Wall();

	std::vector<float> x;
	std::vector<float> y;
	std::vector<float> z;
};

