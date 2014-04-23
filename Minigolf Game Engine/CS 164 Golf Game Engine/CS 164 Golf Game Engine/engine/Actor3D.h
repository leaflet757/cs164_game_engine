#pragma once

#include <glm\vec3.hpp>=

class Actor3D
{
private:
	static int idnumber;

protected:
	int id;
	glm::vec3 position;
	glm::vec3 rotation;

	//virtual void draw();

public:
	Actor3D();
	Actor3D(const Actor3D& copy);
	~Actor3D();

	// Get functions
	int getID(){ return id; }
	glm::vec3 getPosition(){ return position; }
	glm::vec3 getRotation(){ return rotation; }

	// Set Functions
	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);

	void drawActor() {  }

	Actor3D& operator=(const Actor3D& other);
};

