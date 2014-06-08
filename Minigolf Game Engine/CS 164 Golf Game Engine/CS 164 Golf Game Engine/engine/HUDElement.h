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
	bool									hasDynamicElements;

public:
	HUDElement();
	HUDElement(const HUDElement& copy);
	~HUDElement();

	void									hide();
	void									show();
	void									setBackgroundColor(float r, float g, float b);
	void									setPosition(float x, float y);
	bool									isVisible() { return visible; }
	virtual void							update(LevelManager* levelManager) { }
	void									setDynamicElements(bool state);

	HUDElement&								operator=(const HUDElement& other);
};

