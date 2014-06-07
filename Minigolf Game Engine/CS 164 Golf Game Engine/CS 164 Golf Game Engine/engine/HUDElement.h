#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <glm\vec2.hpp>
#include <glm\vec3.hpp>

#include "../LevelManager.h"

class HUDElement
{
protected:
	glm::vec2								position;
	glm::vec3								backgroundColor;
	bool									visible;

public:
	HUDElement();
	HUDElement(const HUDElement& copy);
	~HUDElement();

	void									hide();
	void									show();
	void									setBackgroundColor(float r, float g, float b);
	bool									isVisible() { return visible; }
	virtual void							update(LevelManager* levelManager) { }

	HUDElement&								operator=(const HUDElement& other);
};

