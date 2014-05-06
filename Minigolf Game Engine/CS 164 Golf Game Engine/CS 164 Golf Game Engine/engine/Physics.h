#pragma once
#include <vector>
#include <cmath>
#include <iostream>

#include "Actor3D.h"

class Physics
{
private:
	std::vector<Actor3D*> colliders;

public:
	Physics();
	~Physics();

	void						update(float delta);
	
	void						add(Actor3D* actor);
};

