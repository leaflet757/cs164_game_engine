#pragma once
#include <vector>
#include <iostream>

#include "../LevelManager.h"

class HUDElement
{
public:
	HUDElement();
	~HUDElement();

	void									hide();
	void									show();
	virtual void							update(LevelManager* levelManager) { }
};

