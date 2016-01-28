/**********************************************************************

Exercise 3.1 with OpenGL

June, 27th, 2015

This program was written by DucThang
Contact:
thangdn.tlu@outlook.com

Every comment would be appreciated.

If you want to use parts of any code of mine:
let me know and
use it!
**********************************************************************/

#include <GL\glut.h>
#include <GL\GL.h>

#define WIDTH 500
#define HEIGH 500
GLubyte myPattern[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

void myInit();

void myDisplay();

void main(int argv, char** argc)
{
	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Example 3.1");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,WIDTH, 0, HEIGH);
	glFlush();
}

void myDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//
	glEnable(GL_POLYGON_MODE);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
		glVertex2i(201, 100);
		glVertex2i(201, 200);
		glVertex2i(100, 200);
		glVertex2i(100, 100);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		glVertex2i(200, 100);
		glVertex2i(200, 200);
		glVertex2i(100, 200);
		glVertex2i(100, 100);
	glEnd();
	glDisable(GL_POLYGON_MODE);
	//
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(myPattern);
	glPointSize(10);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
		glVertex2i(200+200, 100);
		glVertex2i(200+200, 200);
		glVertex2i(100+200, 200);
		glVertex2i(100+200, 100);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
	glFlush();
}