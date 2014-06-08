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
	/*glm::vec3 v = actor->getVelocity();
	v.x = v.x - v.x / 9.0;
	v.y = v.y - v.y / 9.0;
	v.z = v.z - v.z / 9.0;

	if (v.x > -.001 && v.x < 0.001)
	{
		v.x = 0;
	}
	if (v.y > -.001 && v.y < 0.001)
	{
		v.y = 0;
	}
	if (v.z > -.001 && v.z < 0.001)
	{
		v.z = 0;
	}
	actor->setVelocity(v.x, v.y, v.z); */
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