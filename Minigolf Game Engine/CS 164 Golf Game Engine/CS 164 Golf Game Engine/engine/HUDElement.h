#pragma once
#include <vector>
#include <iostream>
#include <glm\vec2.hpp>
#include <glm\vec3.hpp>

#include "../LevelManager.h"

class HUDElement
{
protected:
	glm::vec2 position;
	glm::vec3 backgroundColor;

public:
	HUDElement();
	HUDElement(const HUDElement& copy);
	~HUDElement();

	void									hide();
	void									show();
	virtual void							update(LevelManager* levelManager) { }

	HUDElement&								operator=(const HUDElement& other);
};

