#include "Ticker.h"


Ticker::Ticker() :
list()
{
}


Ticker::~Ticker()
{
}

void Ticker::add(Actor3D* actor)
{
	list.push_back(actor);
}

void Ticker::update(float delta)
{
	for (auto & i : list)
	{
		i->tick(delta);
	}
}