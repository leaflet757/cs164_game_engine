#pragma once
#include "HUDElement.h"

class HUDBackgroundElement : public HUDElement
{
public:
	HUDBackgroundElement();
	~HUDBackgroundElement();

	virtual void						update(LevelManager* levelManager);
};

