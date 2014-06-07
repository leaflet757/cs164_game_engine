#pragma once
#include "HUDElement.h"

class HUDTextElement : public HUDElement
{
private:
	std::string text;

public:
	HUDTextElement();
	HUDTextElement(float x, float y);
	~HUDTextElement();

	void									setText(std::string str);

	virtual void							update(LevelManager* levelManager);
};

