#include "HUDManager.h"


HUDManager::HUDManager() :
elements()
{
}


HUDManager::~HUDManager()
{
}

void HUDManager::update(LevelManager* levelManager)
{
	for (auto & e : elements)
	{
		e->update(levelManager);
	}
}

void HUDManager::addElement(HUDElement* element)
{
	elements.push_back(element);
}