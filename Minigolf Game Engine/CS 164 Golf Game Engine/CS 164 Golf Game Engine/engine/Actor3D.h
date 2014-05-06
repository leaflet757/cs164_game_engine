#pragma once

#include <iostream>
#include <glm\vec3.hpp>
#include <vector>
#include <cmath>

class Actor3D
{
private:
	static int										idnumber;

protected:
	int												id;
	bool											_isDrawable;
	bool											useCustomDraw;
	
	glm::vec3										position;
	glm::vec3										rotation;
	glm::vec3										scale;

	std::vector<glm::vec3>							verts;
	std::vector<glm::vec3>							color;
	std::vector<glm::vec3>							normals;

	// TODO: Creat more things related to phys, like bool mover and velocity

public:
	Actor3D();
	Actor3D(const Actor3D& copy);
	~Actor3D();

	// Conditionals
	bool											isDrawable() const { return _isDrawable; }
	bool											hasCustomDraw() const { return useCustomDraw; }

	// Get functions
	int												getID() const { return id; }
	glm::vec3										getPosition() const { return position; }
	glm::vec3										getRotation() const { return rotation; }
	glm::vec3										getScale() const { return scale; }
	std::vector<glm::vec3>							getVertices() const { return verts; }
	std::vector<glm::vec3>							getColor() const { return color; }

	// Set Functions
	void											setPosition(float x, float y, float z);
	void											setRotation(float x, float y, float z);
	// setcolor, setscale

	void											addVert(float x, float y, float z);

	// Overridable Draw
	virtual void									draw() const { }

	// Overridable Update
	virtual void									tick(float delta) const { }

	Actor3D& operator=(const Actor3D& other);
};

