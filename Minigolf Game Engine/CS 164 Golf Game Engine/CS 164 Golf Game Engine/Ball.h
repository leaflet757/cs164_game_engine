#pragma once

#include <GL\glut.h>

#include "engine\Actor3D.h"

class Ball : public Actor3D
{
public:
	Ball();
	~Ball();

	virtual void draw() const;
};

