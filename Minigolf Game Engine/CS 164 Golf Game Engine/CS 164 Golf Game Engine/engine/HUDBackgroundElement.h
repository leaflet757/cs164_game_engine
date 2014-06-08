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

	void								setSize(float width, float height);

	virtual void						update(LevelManager* levelManager);
};

