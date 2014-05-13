#pragma once
#include "engine\Actor3D.h"
#include "Tile.h"

class Ball : public Actor3D
{
private:
	Tile* tileLocation;

public:
	Ball();
	~Ball();

	void draw() const;
	void tick(float delta) const;

	void setTileLocation(Tile & tile);
	Tile getTileLocation() const { return *tileLocation; }
};

