#pragma once
#include <vector>
#include <iostream>
#include "Actor3D.h"
#include "../Ball.h"
class Ticker
{
private:
	std::vector<Actor3D*> list;

public:
	Ticker();
	~Ticker();
	

	void					update(float delta);
	
	void					add(Actor3D* actor);
};

