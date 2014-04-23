#pragma once
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include "engine\Actor3D.h"

class Teapot : public Actor3D
{
private:
	virtual void draw();
public:
	Teapot();
	~Teapot();
};

