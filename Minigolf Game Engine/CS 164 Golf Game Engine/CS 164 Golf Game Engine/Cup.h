#pragma once

#include "engine\Actor3D.h"
#include "Tile.h"

class Cup : public Actor3D
{
private:
	Tile* tileLocation;

public:
	Cup();
	~Cup();

	// the id of the tile the cup is located
	int cupID;

	float x;
	float y;
	float z;

	void setTileLocation(Tile & tile);
	Tile getTileLocation() const { return *tileLocation; }
};

