/**********************************************************************

Program make polylines uses midpoint algorithm is made with OpenGL

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
#include <math.h>

#define HEIGHT 500
#define WEIGH 500
GLint xx = -1;
GLint yy = -1;

void myDisplay();
void myInit();
void drawLineTTTD(GLint x1,GLint y1,GLint x2,GLint y2);
void drawPoint(GLint x, GLint y);
void myMouse(GLint b, GLint s, GLint x, GLint y);

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WEIGH, HEIGHT);
	glutCreateWindow("Example 1.3");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
void myDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 1);
	glPointSize(5);
	glutMouseFunc(myMouse);
	glFlush();
}
void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

void drawLineTTTD(GLint x1, GLint y1, GLint x2, GLint y2)
{
	GLint dx = abs(x2 - x1);
	GLint dy = abs(y2 - y1);
	GLint d = (dy<<1) - dx;
	GLint E = (dy<<1);
	GLint NE = ((dy - dx)<<1);
	int x_unit = 1, y_unit = 1;
	if (x2 - x1 < 0)
		x_unit = -1;
	if (y2 - y1 < 0)
		y_unit = -1;
	if (dx == 0 && dy == 0)
	{
		drawPoint(x1, y1);
		glFlush();
		return;
	}
	if (dx == 0)
	{
		for (GLint i = y1; i != y2; i+=y_unit)
		{
			drawPoint(x1, i);
		}
		glFlush();
		return;
	}
	if (dy == 0)
	{
		for (GLint i = x1; i != x2; i+=x_unit)
		{
			drawPoint(i, y1);
		}
		glFlush();
		return;
	}
	if (dx >= dy)
	{
		GLint x=x1, y = y1;
		drawPoint(x, y);
		while (x != x2)
		{
			if (d < 0)
			{
				d += E;
			}
			else
			{
				d += NE;
				y += y_unit;
			}
			x += x_unit;
			drawPoint(x, y);
		}
		glFlush();
		return;
	}
	else
	{
		GLint x = x1, y = y1;
		drawPoint(x, y);
		while (y != y2)
		{
			if (d < 0)
			{
				d += (dx<<1);
			}
			else
			{
				d += ((dx-dy)<<1);
				x += x_unit;
			}
			y += y_unit;
			drawPoint(x, y);
		}
		glFlush();
		return;
	}
	
}

void drawPoint(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void myMouse(GLint b, GLint s, GLint x, GLint y)
{
	if (s == GLUT_DOWN && b == GLUT_LEFT_BUTTON)
	{
		if (xx == -1 && yy == -1)
		{
			xx = x + x * 30 / 100; yy = HEIGHT - y - (HEIGHT - y) * 5 / 100;
		}
		else
		{
			drawLineTTTD(xx, yy, x + x * 30 / 100, HEIGHT - y - (HEIGHT - y) * 5 / 100);
			xx = x + x * 30 / 100; yy = HEIGHT - y - (HEIGHT - y) * 5 / 100;
		}
	}
	else
	{
		if (s == GLUT_DOWN && b == GLUT_RIGHT_BUTTON)
		{
			drawPoint(x + x * 30 / 100, (HEIGHT - y) - (HEIGHT - y)*5/100);
		}
	}
	glFlush();
}