#pragma once

#include <iostream>
#include <vector>

#include "engine\Graphics.h"
#include "engine\Physics.h"

#include "Level.h"
#include "Tee.h"
#include "Cup.h"
#include "Ball.h"

class LevelManager
{
	int									levelNumber;
	std::vector<Level>*					levels;
	Level*								currentLevel;

	Ball*								ball;
	Tee*								tee;
	Cup*								cup;

public:
	LevelManager();
	~LevelManager();

	void								loadContent(std::vector<Level>* files);
	void								initialize();

	void								begin();
	void								nextLevel();
	void								previousLevel();

	Ball*								getBall();
	Tee*								getTee();
	Cup*								getCup();
	int									getLevelNumber() { return levelNumber; }
	std::string							getLevelName() {return currentLevel->nameStore; }
	int									getLevelPar(){ return currentLevel->parNum; }
};

