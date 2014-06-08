#include "Wall.h"


Wall::Wall()
{
	useCustomDraw = true;
	isWall = true;

	_isDrawable = true;
	_isCollisionObject = true;

	x1 = std::vector<float>();
	y1 = std::vector<float>();
	z1 = std::vector<float>();
	x2 = std::vector<float>();
	y2 = std::vector<float>();
	z2 = std::vector<float>();
	xyz_1 = std::vector<glm::vec3>(); //will hold xyz vec3s just in case. comment out later.
	xyz_2 = std::vector<glm::vec3>();

	color.push_back(glm::vec3(3, 0, 0));
	color.push_back(glm::vec3(3, 0, 0));
	color.push_back(glm::vec3(3, 0, 0));
	color.push_back(glm::vec3(3, 0, 0));
}

//Method to help render walls.
void Wall::draw() const {
 std::vector<glm::vec3>& verts = getVertices();
 glm::vec3& normals = getNormals();
 std::vector<glm::vec3>& color = getColor();
 glm::vec3& pos = getPosition();
 glm::vec3& rotation = getRotation();
 glm::vec3& scale = getScale();

 glPushMatrix();
 glScaled(scale.x, scale.y, scale.z);
 glTranslated(pos.x, pos.y, pos.z);
 glRotated(rotation.x, 1.0, 0.0, 0.0);
 glRotated(rotation.y, 0.0, 1.0, 0.0);
 glRotated(rotation.z, 0.0, 0.0, 1.0);

 glBegin(GL_QUADS);
  int i = 0;
  for (const glm::vec3 &v : verts)
  {
   if (i < color.size())
   {
    const glm::vec3 &c = color[i++];
    glColor3f(c.r, c.g, c.b);
   }
   glNormal3f(normals.x, normals.y, normals.z);
   glVertex3f(v.x, v.y, v.z);
  }
 glEnd();
 glPopMatrix();

 // DEBUG ------------------------------------------
 // draw direction line
 //glPushMatrix();
 //glBegin(GL_LINES);
 //glColor3f(0, 0, 255);
 //glm::vec3& p = getCenter();
 //glVertex3f(p.x, p.y, p.z);
 //glm::vec3 newpoint = normals + p;
 //glVertex3f(newpoint.x, newpoint.y, newpoint.z);
 //glEnd();
 //glPopMatrix();
 // ------------------------------------------------
}


Wall::~Wall()
{
}

