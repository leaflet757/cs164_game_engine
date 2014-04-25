#include "Graphics.h"


Graphics::Graphics(int argc, char** argv)
{
	glutInit(&argc, argv);                                      // GLUT initialization
}


Graphics::~Graphics()
{
}

void Graphics::init()
{
	// select projection matrix
	glMatrixMode(GL_PROJECTION);

	// set the viewport
	glViewport(0, 0, win.width, win.height);

	// set matrix mode
	glMatrixMode(GL_PROJECTION);

	// reset projection matrix
	glLoadIdentity();
	GLfloat aspect = (GLfloat)win.width / win.height;

	// set up a perspective projection matrix
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);

	// specify which matrix is the current matrix
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_SMOOTH);

	// specify the clear value for the depth buffer
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// specify implementation-specific hints
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	GLfloat amb_light[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1 };
	GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Graphics::createWindow()
{
	// set window values
	win.width = 640;
	win.height = 480;
	win.title = "Golf Game";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // Display Mode
	glutInitWindowSize(win.width, win.height);				// set window size
	glutCreateWindow(win.title);					// create Window
}

void Graphics::clear()
{
	// Clear Screen and Depth Buffer
	glClearColor(0, 0.6, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void Graphics::update(float delta)
{
	for (auto const &actor : drawables)
	{
		if (actor.isDrawable())
		{
			if (actor.hasCustomDraw())
			{
				actor.draw();
			}
			else
			{
				std::vector<glm::vec3> verts = actor.getVertices();
				std::vector<glm::vec3> color = actor.getColor();
				glm::vec3 pos = actor.getPosition();
				glm::vec3 rotation = actor.getRotation();
				glm::vec3 scale = actor.getScale();

				glPushMatrix();
				glTranslated(pos.x, pos.y, pos.z);
				glRotated(rotation.x, 1.0, 0.0, 0.0);
				glRotated(rotation.y, 0.0, 1.0, 0.0);
				glRotated(rotation.z, 0.0, 0.0, 1.0);
				//glScaled(scale.x, scale.y, scale.z);

				glBegin(GL_QUADS);
				int i = 0;
				for (const glm::vec3 &v : verts)
				{
					const glm::vec3 &c = color[i++];
					//glColor3ub(0.0, 255, 0.0);
					//glColor3f(c.r, c.g, c.b);
					glVertex3f(v.x, v.y, v.z);
				}
				glEnd();
				glPopMatrix();
			}
		}
	}

	//glutSolidCube(1);

	glutSwapBuffers();
}

void Graphics::add(Actor3D& actor)
{
	drawables.push_back(actor);
}

void Graphics::remove(Actor3D& actor)
{
	drawables.erase(drawables.begin() + actor.getID());
}