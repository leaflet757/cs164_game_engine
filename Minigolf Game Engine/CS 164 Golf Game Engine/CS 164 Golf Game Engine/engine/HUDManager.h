#pragma once

#include <vector>
#include <iostream>

#include "../LevelManager.h"
#include "HUDElement.h"

class HUDManager
{
private:
	std::vector<HUDElement*>			elements;

public:
	HUDManager();
	~HUDManager();

	void								update(LevelManager* levelManager);

	void								addElement(HUDElement* element);
};

