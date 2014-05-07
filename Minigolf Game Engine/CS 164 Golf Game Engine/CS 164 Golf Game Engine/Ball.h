#pragma once
#include "engine\Actor3D.h"

class Ball : public Actor3D
{
public:
	Ball();
	~Ball();

	void draw() const;
	void tick(float delta) const;
};

