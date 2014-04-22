#include "Graphics.h"


Graphics::Graphics()
{
}


Graphics::~Graphics()
{
}

void Graphics::update(float delta)
{
	for (auto actor : drawables)
	{
		actor.draw();
	}
}

void Graphics::add(Actor3D actor)
{
	drawables.push_back(actor);
}

void Graphics::remove(Actor3D actor)
{
	drawables.erase(drawables.begin() + actor.getID());
}