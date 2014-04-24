#include "Cube.h"


Cube::Cube()
{
	_isDrawable = true;

	position.x = 5;
	position.y = 5;
	position.z = 7;

	addVert(-1.0, 0.0, -1.0);
	addVert(-1.0, 0.0, 1.0);
	addVert(1.0, 0.0, 1.0);
	addVert(1.0, 0.0, -1.0);
}


Cube::~Cube()
{
}
