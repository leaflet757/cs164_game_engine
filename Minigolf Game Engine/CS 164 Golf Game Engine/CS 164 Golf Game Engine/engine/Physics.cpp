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


bool Physics::rayIntersectTest(Actor3D* actor, Actor3D* other, float * d)
{
	// assuming vectors are all normalized
	glm::vec3 & n = other->getNormals();
	glm::vec3 & l = actor->getDirection();
	glm::vec3 & l0 = actor->getPosition();
	std::vector<glm::vec3>& verts = other->getVertices();
	glm::vec3 & p0 = verts[0];

	float denom = n.x * l.x + n.y * l.y + n.z * l.z;
	if (denom > 1e-6) {
		glm::vec3 p0l0 = p0 - l0;
		*d = (p0l0.x * n.x + p0l0.y * n.y + p0l0.z * n.z) / denom;
		return (*d > 0);
	}
	return false;
}

// this checks to make sure a part of the object is within the other
// object
bool Physics::inBounds(Actor3D* actor, Actor3D* other, float d)
{
	bool inBounds = false;

	// check to see if the distance to that 
	std::vector<glm::vec3>& verts = other->getVertices();
	return inBounds;
}

void Physics::reflect(Actor3D* actor, glm::vec3 &normal)
{

}

float Physics::calcDistance(Actor3D* actor, Actor3D* other)
{
	return 0.0f;
}

void Physics::checkCollisions(float delta, Actor3D* actor)
{
	// check if the obj is colliding with anything and reflect along the normal\
	// this changes vel
	glm::vec3 & av = actor->getPosition();
	const float & r = actor->getRadius();
	const Actor3D* collider = nullptr;
	isTile = false;
	for (auto const & other : colliders)
	{
		if (other->isCollisionObject())
		{
			if (other->getID() != actor->getID())
			{
				collider = nullptr;
				// check to see if the distance between
				// actor and the four corners and actor 
				// less than the radius of ball
				float dist;
				if (rayIntersectTest(actor, other, &dist))
				{
					if (inBounds(actor, other, dist))
					{
						// check if distance to plane-radius is less than radius
						float d = calcDistance(actor, other);
						if (d <= r)
						{
							collider = other;
							if (other->isTile())
							{
								isTile = true;
							}
							else
							{
								isTile = false;
							}
						}
					}
				}

				// if yes then collision has occured and reflect
				// the velocity vector about the normal of other
				// then apply elasticity to velocity
				if (collider != nullptr)
				{
					reflect(actor, collider->getNormals());
				}

				// if no then there is no collision with that obj
			}
		}
	}
}

void Physics::checkForces(float delta, Actor3D* actor)
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
				checkCollisions(delta, obj);
				checkForces(delta, obj);
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