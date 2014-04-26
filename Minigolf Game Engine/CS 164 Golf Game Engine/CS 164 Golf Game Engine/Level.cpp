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
