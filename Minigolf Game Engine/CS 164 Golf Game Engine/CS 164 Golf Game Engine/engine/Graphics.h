#pragma once

#include <vector>

#include "Actor3D.h"

// TODO:
// need a way to handle lighting and other shaders

class Graphics
{
private:
	std::vector<Actor3D> drawables;

public:
	Graphics();
	~Graphics();

	void update(float delta);

	void add(Actor3D actor);
	void remove(Actor3D actor);
};

