#pragma once
#include <vector>
#include <cmath>
#include <iostream>

#include "Actor3D.h"

class Physics
{
private:
	const int					elasticity;

	bool						isTile;

	std::vector<Actor3D*> colliders;

	void						applyForces(float delta, Actor3D* actor);
	float						calcDistance(Actor3D* actor, Actor3D* other);

public:
	Physics();
	~Physics();

	void						update(float delta);
	
	void						add(Actor3D* actor);
};

