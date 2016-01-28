/**********************************************************************

The program that makes points by your mouse is made with OpenGL

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
using namespace std;
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/GL.H>
#define WIDTH 500
#define HEIGHT 500
void myDisplay();
void myMount(GLint b, GLint s, GLint x, GLint y);
void myKeyBoard(unsigned char c, GLint x, GLint y);
void drawPoint(GLfloat x, GLfloat y);
void myInit();
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Example 1.2");
	glutMouseFunc(myMount);
	glutKeyboardFunc(myKeyBoard);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
void myDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void drawPoint(GLfloat x, GLfloat y)
{
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
	glFlush();
}
void myMount(GLint b, GLint s, GLint x, GLint y)
{
	if (s == GLUT_DOWN&& b == GLUT_LEFT_BUTTON)
	{
		glColor3f(1, 0, 0);
		glPointSize(5);
		drawPoint(x, HEIGHT- y);
		cout << "x";
	}
	else
	{
		if (s == GLUT_DOWN&& b == GLUT_RIGHT_BUTTON)
		{
			
			glPointSize(2);
			glColor3f(0, 1, 0);
			drawPoint(x, HEIGHT-y);
		}
	}
	glFlush();
}
void myKeyBoard(unsigned char c, GLint x, GLint y)
{
	cout << c ;
}
void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}