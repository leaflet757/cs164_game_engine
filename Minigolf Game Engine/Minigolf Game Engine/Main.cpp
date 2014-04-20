/*
* OpenGLSamples (openglsamples.sf.net) Examples
* VC++ users should create a Win32 Console project and link
* the program with glut32.lib, glu32.lib, opengl32.lib
*
* GLUT can be downloaded from http://www.xmission.com/~nate/glut.html
* OpenGL is by default installed on your system.
* For an installation of glut on windows for MS Visual Studio 2010 see: http://nafsadh.wordpress.com/2010/08/20/glut-in-ms-visual-studio-2010-msvs10/
*
*/

#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header

#define KEY_ESCAPE 27



typedef struct {
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

glutWindow win;

float g_rotation = 0;
float g_rotation_speed = 0.2f;

void display()
{
	// Clear Screen and Depth Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Define a viewing transformation
	gluLookAt(4, 2, 0, 0, 0, 0, 0, 1, 0);


	// Push and pop the current matrix stack. 
	// This causes that translations and rotations on this matrix wont influence others.

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, 0);
	glRotatef(g_rotation, 0, 1, 0);
	glRotatef(90, 0, 1, 0);

	// Draw the teapot
	glutSolidTeapot(1);
	glPopMatrix();


	g_rotation += g_rotation_speed;
	glutSwapBuffers();
}


void initialize()
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


void keyboard(unsigned char key, int mousePositionX, int mousePositionY)
{
	switch (key)
	{
	case KEY_ESCAPE:
		exit(0);
		break;

	default:
		break;
	}
}

int main(int argc, char **argv)
{
	// set window values
	win.width = 640;
	win.height = 480;
	win.title = "OpenGL/GLUT Example. Visit http://openglsamples.sf.net ";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // Display Mode
	glutInitWindowSize(win.width, win.height);				// set window size
	glutCreateWindow(win.title);					// create Window
	glutDisplayFunc(display);						// register Display Function
	glutIdleFunc(display);						// register Idle Function
	glutKeyboardFunc(keyboard);						// register Keyboard Handler
	initialize();
	glutMainLoop();							// run GLUT mainloop
	return 0;
}