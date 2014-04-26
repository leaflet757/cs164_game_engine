#pragma once

#include "engine\Actor3D.h"

class Cup : public Actor3D
{
public:
	Cup();
	~Cup();

	int cupID;

	float x;
	float y;
	float z;
};

