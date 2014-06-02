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
	for (Tile & t : tilesStore)
	{
		t.setDrawableState(isDrawn);
		t.setCollidableState(isDrawn);
	}
	for (Wall & w : wallsStore)
	{
		w.setDrawableState(isDrawn);
		w.setCollidableState(isDrawn);
	}
	cupStore.setDrawableState(isDrawn);
	cupStore.setCollidableState(isDrawn);
	teeStore.setDrawableState(isDrawn);
}