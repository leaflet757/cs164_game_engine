#pragma once

#include <glm\vec3.hpp>
#include <vector>

class Actor3D
{
private:
	static int idnumber;

protected:
	int id;
	bool _isDrawable;
	
	glm::vec3 position;
	glm::vec3 rotation;

	std::vector<glm::vec3> verts;
	//std::vector<glm::vec3> color;
	std::vector<glm::vec3> normals;

	// Set / Remove Vert Positions
	void											addVert(glm::vec3 vert);
	virtual void									addVert(float x, float y, float z);
	// Removes specified Vertex
	void											removeVert(glm::vec3 vert);

public:
	Actor3D();
	Actor3D(const Actor3D& copy);
	~Actor3D();

	// Conditionals
	bool											isDrawable(){ return _isDrawable; }

	// Get functions
	int												getID() const { return id; }
	glm::vec3										getPosition() const { return position; }
	glm::vec3										getRotation() const { return rotation; }
	virtual std::vector<glm::vec3>					getVerticies() const { return verts; }

	// Set Functions
	void											setPosition(float x, float y, float z);
	void											setRotation(float x, float y, float z);

	void											drawActor() {  }

	Actor3D& operator=(const Actor3D& other);
};

