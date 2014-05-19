#include "Physics.h"

Physics::Physics() :
colliders(),
elasticity(0.8),
isTile(false)
{
}


Physics::~Physics()
{
}

float Physics::calcDistance(Actor3D* actor, Actor3D* other)
{
	return 0.0f;
}

void Physics::applyForces(float delta, Actor3D* actor)
{
	// check all the forces acting on the obj and update accel
	// use accel to update vel

	// this will determine if the object is accelerating
}

void Physics::update(float delta)
{
	for (auto const & obj : colliders)
	{
		if (obj->isCollisionObject())
		{
			if (obj->isMover())
			{
				applyForces(delta, obj);
				glm::vec3 &pos = obj->getVelocity() * delta + obj->getPosition();
				obj->setPosition(pos.x, pos.y, pos.z);
			}
		}
	}
}

void Physics::add(Actor3D* actor)
{
	colliders.push_back(actor);
}