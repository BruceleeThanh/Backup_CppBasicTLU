/**********************************************************************

Exercise 4.1 with OpenGL

June, 27th, 2015

This program was written by DucThang
Contact:
thangdn.tlu@outlook.com

Every comment would be appreciated.

If you want to use parts of any code of mine:
let me know and
use it!
**********************************************************************/

#include <GL/glut.h>
#include <GL/GL.h>
#include <math.h>

#define WIDTH 500
#define HEIGH 500

void myDisplay();

void myInit();

void Reshape(int x, int y);

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Intro");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(Reshape);
	myInit();
	glutMainLoop();
}
void myDisplay()
{
	
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRecti(100, 100, 200, 200);
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(150,150, 0.);
	glRotatef(45.0, 0, 0, 1);
	glTranslatef(-150.,-150., 0.);
	glRecti(100, 100, 200, 200);
	glPopMatrix();
	glFlush();
}
void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,WIDTH, 0, HEIGH);
	glMatrixMode(GL_MODELVIEW);
	glFlush();
}
void Reshape(int x, int y)
{
	glViewport(0, 0, (GLsizei)400, (GLsizei)400);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 500.0, -50.0, 500.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}