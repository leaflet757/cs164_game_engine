#pragma once
#include "engine\Actor3D.h"
#include "Tile.h"

class Ball : public Actor3D
{
private:
	Tile* tileLocation;
	glm::vec3 prevPos;
	const float elastisity;
	bool findNewTileLocation(float p, float edge, bool set);

public:
	Ball();
	~Ball();

	void draw() const;
	void tick(float delta);

	void setTileLocation(Tile & tile);
	Tile getTileLocation() const { return *tileLocation; }
};

