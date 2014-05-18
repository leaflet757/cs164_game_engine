#include "Ball.h"


Ball::Ball() :
elastisity(0.95)
{
	_isDrawable = true;
	_isMover = true;
	_isCollisionObject = true;
	useCustomDraw = true;
	radius = 0.1;
	tileLocation = nullptr;
}

Ball::~Ball()
{
}

void Ball::draw() const
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScaled(scale.x, scale.y, scale.z);
	glTranslatef(position.x, position.y, position.z);
	glRotated(rotation.x, 1.0, 0.0, 0.0);
	glRotated(rotation.y, 0.0, 1.0, 0.0);
	glRotated(rotation.z, 0.0, 0.0, 1.0);
	glutSolidSphere(radius, 8, 8);
	glPopMatrix();
}

void Ball::tick(float delta)
{
	Tile * t = tileLocation;
	std::vector<float>& x = t->x;
	std::vector<float>& z = t->z;

	float minx1 = std::min(x[0],x[1]);
	float minx2 = std::min(x[2], x[3]);
	float minx = std::min(minx1, minx2);
	float minz1 = std::min(z[0], z[1]);
	float minz2 = std::min(z[2], z[3]);
	float minz = std::min(minz1, minz2);

	float maxx1 = std::max(x[0], x[1]);
	float maxx2 = std::max(x[2], x[3]);
	float maxx = std::max(maxx1, maxx2);
	float maxz1 = std::max(z[0], z[1]);
	float maxz2 = std::max(z[2], z[3]);
	float maxz = std::max(minz1, minz2);

	glm::vec3 &p = getPosition();

	// if any if statement results in true, then the object is on edge
	// then chck to see if that edge has a wall or tile
	// if wall, update wallLocation
	// if not wall, reflect about normal

	// collision check
	if (p.x - radius <= minx)
	{
		std::cout << "x, " << minx << std::endl;
		if (!findNewTileLocation(p.x - radius, minx, false))
		{
			setPosition(prevPos.x, prevPos.y, prevPos.z);
			setVelocity(-1 * velocity.x*elastisity, velocity.y*elastisity, velocity.z*elastisity);
		}
	}
	if (p.x + radius >= maxx)
	{
		std::cout << "x, " << maxx << std::endl;
		if (!findNewTileLocation(p.x + radius, maxx, false))
		{
			setPosition(prevPos.x, prevPos.y, prevPos.z);
			setVelocity(-1 * velocity.x*elastisity, velocity.y*elastisity, velocity.z*elastisity);
		}
	}
	if (p.z - radius <= minz)
	{
		std::cout << "z, " << minz << std::endl;
		if (!findNewTileLocation(p.z - radius, minz, false))
		{
			setPosition(prevPos.x, prevPos.y, prevPos.z);
			setVelocity(velocity.x*elastisity, velocity.y*elastisity, -1 * velocity.z*elastisity);
		}
	}
	if (p.z + radius >= maxz)
	{
		std::cout << "z, " << maxz << std::endl;
		if (!findNewTileLocation(p.z + radius, maxz, false))
		{
			setPosition(prevPos.x, prevPos.y, prevPos.z);
			setVelocity(velocity.x*elastisity, velocity.y*elastisity, -1 * velocity.z*elastisity);
		}
	}
	// tile check
	if (p.x <= minx)
	{
		std::cout << "x, " << minx << std::endl;
		findNewTileLocation(p.x, minx, true);
	}
	if (p.x >= maxx)
	{
		std::cout << "x, " << maxx << std::endl;
		findNewTileLocation(p.x, maxx, true);
	}
	if (p.z <= minz)
	{
		std::cout << "z, " << minz << std::endl;
		findNewTileLocation(p.z, minz, true);
	}
	if (p.z >= maxz)
	{
		std::cout << "z, " << maxz << std::endl;
		findNewTileLocation(p.z, maxz, true);
	}

	// update the previous position
	prevPos = position;
}

void Ball::setTileLocation(Tile & tile)
{
	if (tileLocation == nullptr)
	{
		this->setPosition(0, radius, 0);
	}
	tileLocation = &tile;
}

bool Ball::findNewTileLocation(float p, float edge, bool set)
{
	// find if there exists 2 p for a tile in neighbors
	// if yes, set that as current tile if set == 1
	// if no, reflect the velocity vector if set == 0
	std::vector<bool> r;
	for (const auto & t : tileLocation->neighbors)
	{
		r.clear();
		for (const auto & v : t->getVertices())
		{
			if (v.x == edge || v.z == edge)
			{
				r.push_back(true);
			}
		}
		if (r.size() == 2)
		{
			if (set) tileLocation = t;
			return true;
		}
	}
	return false;
}