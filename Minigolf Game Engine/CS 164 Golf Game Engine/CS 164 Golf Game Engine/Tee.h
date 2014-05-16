#pragma once

#include "engine\Actor3D.h"
#include "Tile.h"

class Tee : public Actor3D
{
private:
	Tile* tileLocation;

public:
	Tee();
	~Tee();

	// tile id location of tee
	int tID;

	float x;
	float y;
	float z;

	void setTileLocation(Tile & tile);
	Tile getTileLocation() const { return *tileLocation; }
	void draw() const;
};

