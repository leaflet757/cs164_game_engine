#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

#include "..\Tile.h"
#include "..\Level.h"
#include "..\Wall.h"
#include "..\Cup.h"
#include "..\Tee.h"
#include "stdafx.h"

class IOManager
{
public:
	IOManager();
	~IOManager();

	std::vector<Level>* loadLevels(int argc, char **argv);
	Level loadLevel(std::ifstream &fileName);
};

