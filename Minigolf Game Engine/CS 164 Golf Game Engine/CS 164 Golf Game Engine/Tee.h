#pragma once

#include "engine\Actor3D.h"

class Tee : public Actor3D
{
public:
	Tee();
	~Tee();

	int tID;

	float x;
	float y;
	float z;
};

