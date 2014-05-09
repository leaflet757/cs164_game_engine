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

	void						checkCollisions(float delta, Actor3D* actor);
	void						checkForces(float delta, Actor3D* actor);
	void						reflect(Actor3D* actor, glm::vec3 &normal);
	float						calcDistance(Actor3D* actor, Actor3D* other);
	bool						rayIntersectTest(Actor3D* actor, Actor3D* other, float* d);
	bool						inBounds(Actor3D* actor, Actor3D* other, float dist);

public:
	Physics();
	~Physics();

	void						update(float delta);
	
	void						add(Actor3D* actor);
};

