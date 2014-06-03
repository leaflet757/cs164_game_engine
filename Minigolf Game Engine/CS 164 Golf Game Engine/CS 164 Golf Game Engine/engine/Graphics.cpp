#include "Graphics.h"

Graphics* _instance = new Graphics();

Graphics::Graphics()
{
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
	GLfloat lightPosition[] = {5, 5, 5};
	GLfloat lightDirection[] = {0,0,0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
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

void Graphics::createWindow(int argc, char** argv)
{
	glutInit(&argc, argv);

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
		if (actor->isDrawable())
		{
			if (actor->hasCustomDraw())
			{
				actor->draw();
			}
			else
			{
				std::vector<glm::vec3>& verts = actor->getVertices();
				glm::vec3& normals = actor->getNormals();
				std::vector<glm::vec3>& color = actor->getColor();
				glm::vec3& pos = actor->getPosition();
				glm::vec3& rotation = actor->getRotation();
				glm::vec3& scale = actor->getScale();

				glPushMatrix();
				glScaled(scale.x, scale.y, scale.z);
				glTranslated(pos.x, pos.y, pos.z);
				glRotated(rotation.x, 1.0, 0.0, 0.0);
				glRotated(rotation.y, 0.0, 1.0, 0.0);
				glRotated(rotation.z, 0.0, 0.0, 1.0);

				glBegin(GL_POLYGON);
				int i = 0;
				for (int q = 0; q < verts.size(); q++)
				{
					const glm::vec3& v = verts[q];
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
		}
	}
}

void Graphics::add(Actor3D *actor)
{
	drawables.push_back(actor);
}

Graphics* Graphics::getInstance()
{
	return _instance;
}

void Graphics::enable2D()
{
	// switch to 2d context
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, win.width, win.height, 0.0, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);

	// TODO: remove
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(10.0f, 0.0);
	glVertex2f(10.0f, 10.0f);
	glVertex2f(0.0, 10.0f);
	glEnd();
}

void Graphics::enable3D()
{
	// Making sure we can render 3d again
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glutSwapBuffers();
}