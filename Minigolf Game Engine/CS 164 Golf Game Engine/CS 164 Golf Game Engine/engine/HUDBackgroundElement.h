#pragma once
#include "HUDElement.h"

class HUDBackgroundElement : public HUDElement
{
private:
	float width;
	float height;
public:
	HUDBackgroundElement();
	~HUDBackgroundElement();

	virtual void						update(LevelManager* levelManager);
};

