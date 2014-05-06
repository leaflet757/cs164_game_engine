#pragma once

#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <vector>

#include "Actor3D.h"

// TODO:
// need a way to handle lighting and other shaders

typedef struct {
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

class Graphics
{
private:
	std::vector<Actor3D*> drawables;

public:
	Graphics(int argc, char** argv);
	~Graphics();

	glutWindow win;

	void											init();
	void											createWindow();
	void											clear();
	void											update(float delta);

	void											add(Actor3D* actor);
};

