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