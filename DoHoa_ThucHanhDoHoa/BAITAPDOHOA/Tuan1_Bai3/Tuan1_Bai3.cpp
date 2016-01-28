/**********************************************************************

The program that move(motioned) a text on the window by press left mouse buttons is made with OpenGL

June, 27th, 2015

This program was written by DucThang
Contact:
thangdn.tlu@outlook.com

Every comment would be appreciated.

If you want to use parts of any code of mine:
let me know and
use it!

**********************************************************************/

#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/GL.H>

#define HEIGHT 700
#define WEIGH 700

void myDisplay();

void myInit();

void bitmap_output(GLint x, GLint y, GLint z, string a, void *font);

void myMount(GLint b, GLint s, GLint x, GLint y);

void myMoto(GLint x, GLint y);

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WEIGH, HEIGHT);
	glutCreateWindow("Example 1.3");
	glutDisplayFunc(myDisplay);
	//glutMouseFunc(myMount);
	glutMotionFunc(myMoto);
	myInit();
	glutMainLoop();
}

void myDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	bitmap_output(0, 0, 0, "Nguyen Duc Thang", GLUT_BITMAP_TIMES_ROMAN_24);
	glFlush();
}

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 700, 0, 700);
}

void bitmap_output(GLint x, GLint y, GLint z, string a, void *font)
{
	glRasterPos3f(x, y, z);
	for (int i = 0; i < a.length(); i++)
	{
		glutBitmapCharacter(font, a[i]);
	}
}

void myMount(GLint b, GLint s, GLint x, GLint y)
{
	if (s == GLUT_DOWN&& b == GLUT_LEFT_BUTTON)
	{
		glColor3f(1, 0, 0);
		glPointSize(5);
		bitmap_output(x, HEIGHT - y, 0, "Nguyen Duc Thang", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		if (s == GLUT_DOWN&& b == GLUT_RIGHT_BUTTON)
		{

			glPointSize(2);
			glColor3f(0, 1, 0);
			bitmap_output(x, HEIGHT - y, 0, "Nguyen Duc Thang", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
	glFlush();
}

void myMoto(GLint x, GLint y)
{
	bitmap_output(x, HEIGHT - y, 0, "Nguyen Duc Thang", GLUT_BITMAP_TIMES_ROMAN_24);
	glFlush();
}