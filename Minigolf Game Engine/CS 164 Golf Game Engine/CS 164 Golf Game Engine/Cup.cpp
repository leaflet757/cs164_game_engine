#include "Cup.h"


Cup::Cup()
{
	_isDrawable = true;
	useCustomDraw = true;

	verts.push_back(glm::vec3(-0.2, 0.0, 0.2));
	verts.push_back(glm::vec3(-0.2, 0.0, -0.2));
	verts.push_back(glm::vec3(0.2, 0.0, -0.2));
	verts.push_back(glm::vec3(0.2, 0.0, 0.2));

	color.push_back(glm::vec3(0.0, 0.0, 0.0));
	color.push_back(glm::vec3(0.0, 0.0, 0.0));
	color.push_back(glm::vec3(0.0, 0.0, 0.0));
	color.push_back(glm::vec3(0.0, 0.0, 0.0));

	tileLocation = nullptr;
}


Cup::~Cup()
{
}

void Cup::setTileLocation(Tile & tile)
{
	tileLocation = &tile;
}

void Cup::draw() const {
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
}