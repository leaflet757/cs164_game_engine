#include "LevelManager.h"


LevelManager::LevelManager() :
levelNumber(0)
{
}


LevelManager::~LevelManager()
{
}

void LevelManager::loadContent(std::vector<Level>* files)
{
	levels = files;
}

void LevelManager::initialize()
{
	Graphics* g = Graphics::getInstance();
	for (int i = 0; i < levels->size(); i ++)
	{
		Level* l = &((*levels)[i]);
		if (currentLevel == nullptr)
		{
			currentLevel = &(*l);
		}
		for (auto & t : l->tilesStore)
		{
			g->add(&t);
		}
		for (auto & w : l->wallsStore)
		{
			g->add(&w);
		}
		tee = &(l->teeStore);
		tee->setPosition(tee->x, tee->y + 0.001, tee->z);
		cup = &(l->cupStore); 
		cup->setPosition(cup->x, cup->y + 0.001, cup->z);
		g->add(tee);
		g->add(cup);
		l->setRenderingState(false);
	}
}

Tee* LevelManager::getTee()
{
	return tee;
}

Cup* LevelManager::getCup()
{
	return cup;
}

Ball* LevelManager::getBall()
{
	return ball;
}

void LevelManager::begin()
{
	if (!ball)
		ball = new Ball();
	
	for (Tile& t : currentLevel->tilesStore)
	{
		Tee& s = currentLevel->teeStore;
		if (t.tileID == s.tID)
		{
			ball->setTileLocation(t);
			ball->setPosition(s.x, s.y + ball->getRadius(), s.z);

			tee->setTileLocation(t);
			tee->setPosition(tee->x, tee->y + 0.001, tee->z);

			cup->setTileLocation(t);
			cup->setPosition(cup->x, cup->y + 0.001, cup->z);
		}
	}

	currentLevel->setRenderingState(true);
	levelNumber = 1;
}

void LevelManager::nextLevel()
{
	if (levelNumber < levels->size())
	{
		// goto next level
		// remove current level from graphics
		currentLevel->setRenderingState(false);
		// remove current level from physics
		// set the new current level
		currentLevel = &((*levels)[levelNumber++]);
		currentLevel->setRenderingState(true);
		// reset the ball
		for (Tile& t : currentLevel->tilesStore)
		{
			Tee& s = currentLevel->teeStore;
			if (t.tileID == s.tID)
			{
				ball->setVelocity(0, 0, 0);
				ball->setTileLocation(t);
				ball->setPosition(s.x, s.y + ball->getRadius(), s.z);

				tee->setTileLocation(t);
				tee->setPosition(tee->x, tee->y + 0.001, tee->z);

				cup->setTileLocation(t);
				cup->setPosition(cup->x, cup->y + 0.001, cup->z);
			}
		}
	}
}

void LevelManager::previousLevel()
{
	if (levelNumber > 1)
	{
		// remove current level from graphics
		currentLevel->setRenderingState(false);
		// remove current level from physics
		// set the new current level
		currentLevel = &((*levels)[--levelNumber-1]);
		currentLevel->setRenderingState(true);
		// reset the ball
		for (Tile& t : currentLevel->tilesStore)
		{
			Tee& s = currentLevel->teeStore;
			if (t.tileID == s.tID)
			{
				ball->setVelocity(0, 0, 0);
				ball->setTileLocation(t);
				ball->setPosition(s.x, s.y + ball->getRadius(), s.z);

				tee->setTileLocation(t);
				tee->setPosition(tee->x, tee->y + 0.001, tee->z);

				cup->setTileLocation(t);
				cup->setPosition(cup->x, cup->y + 0.001, cup->z);
			}
		}
	}
}