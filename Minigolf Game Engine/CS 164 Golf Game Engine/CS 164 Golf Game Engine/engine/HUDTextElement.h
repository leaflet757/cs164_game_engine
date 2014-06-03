#pragma once
#include "HUDElement.h"

class HUDTextElement : public HUDElement
{
public:
	HUDTextElement();
	~HUDTextElement();

	virtual void							update(LevelManager* levelManager);
};

