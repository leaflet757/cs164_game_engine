#include "Physics.h"


Physics::Physics() :
colliders()
{
}


Physics::~Physics()
{
}

void Physics::update(float delta)
{

}

void Physics::add(Actor3D* actor)
{
	colliders.push_back(actor);
}