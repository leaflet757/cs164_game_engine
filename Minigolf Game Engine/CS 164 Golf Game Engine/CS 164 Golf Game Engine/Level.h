#pragma once

#include <glm\vec3.hpp>
#include <vector>

#include "Tile.h"
#include "Wall.h"
#include "Cup.h"
#include "Tee.h"

class Level
{

public:
	Level(std::vector<Tile> tilesStore, std::vector<Wall> wallsStore,
		Cup cupStore, Tee teeStore);
	Level();
	~Level();

	std::vector<Tile> tilesStore;
	std::vector<Wall> wallsStore;
	Cup cupStore;
	Tee teeStore;

	void setRenderingState(bool isDrawn);

	void addWall(Wall& wall);
	void addTile(Tile& tile);
	void setCup(Cup& cup);
	void setTee(Tee& tee);

	void buildVerts();
};

