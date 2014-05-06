#pragma once

#include <glm\vec3.hpp>
#include <GL\glut.h>

#include "engine\Actor3D.h"

class Camera : public Actor3D
{
private:
	// Glut camera lookat
	glm::vec3 lookAt;
	// Glut camera up
	glm::vec3 up;


	// Forward direction
	glm::vec3 directionF;
	glm::vec3 directionU;
	glm::vec3 directionS;

	// TODO: More physics stuff to be abstracted
	glm::vec3 velocity;

	void setDirectionF(glm::vec3&);
	void setDirectionU(glm::vec3&);
	void setDirectionS(glm::vec3&);

	void rotateAboutCenter(float x, float y, float z,
		float a, float b, float c,
		float u, float v, float w, float theta);

public:
	Camera() { };
	Camera(double eyex,
		double eyey,
		double eyez,
		double centerx,
		double centery,
		double centerz,
		double upx,
		double upy,
		double up);
	~Camera();

	// Camera Controls
	void forward();
	void backward();
	void leftMove();
	void rightMove();
	void upMove();
	void downMove();

	// Should be movable component instead of sepporate Method
	void setLookAt(float x, float y, float z);
	void setUp(float x, float y, float z);
	void tilt(float angle, bool up, bool down, bool left, bool right);

	void setVelocity(float x, float y, float z);

	virtual void update(float delta) const;
};

