#include "Level.h"

Level::Level(std::vector<Tile> tilesStore, std::vector<Wall> wallsStore,
	Cup cupStore, Tee teeStore)
{
	this->tilesStore = tilesStore;
	this->wallsStore = wallsStore;
	this->cupStore = cupStore;
	this->teeStore = teeStore;
}

Level::Level()
{
}


Level::~Level()
{
}

void Level::buildVerts()
{
	for (int i = 0; i < tilesStore.size(); i++)
	{
		tilesStore[i].addVert(tilesStore[i].x[i], tilesStore[i].y[i], tilesStore[i].z[i]);
	}

	for (int i = 0; i < wallsStore.size(); i++)
	{
		// something with walls
	}

	//cupStore.setPosition(cupStore.x, cupStore.y, cupStore.z);

	//teeStore.setPosition(teeStore.x, teeStore.y, teeStore.z);
}

void Level::addTile(Tile& tile)
{
	tilesStore.push_back(tile);
}

void Level::addWall(Wall& wall)
{
	wallsStore.push_back(wall);
}

void Level::setCup(Cup& cup)
{
	cupStore = cup;
}

void Level::setTee(Tee& tee)
{
	teeStore = tee;
}

void Level::setRenderingState(bool isDrawn)
{
	if (isDrawn)
	{
		// set all the actors in the level to visible
		// set all the actors to be collidable
	}
	else
	{
		// set all the actors in the level to not visible
		// set all the actors to be collidable
	}
}