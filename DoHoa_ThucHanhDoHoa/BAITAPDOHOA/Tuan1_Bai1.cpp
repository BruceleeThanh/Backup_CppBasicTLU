/**********************************************************************

Make a point with OpenGL

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
#include <GL/GL.H>

void myDisplay();

void drawPoint(GLint x,GLint y);

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 480);
	glutCreateWindow("Vi du 1.1");
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

void myDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3i(0, 0, 0);
	glPointSize(2.5);
	drawPoint(0, 0);
	glFlush();
}

void drawPoint(GLint x, GLint y)
{
	glPointSize(5.5);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glFlush();
}