/**********************************************************************

Program make circles of different sizes by your mouse uses midpoint algorithm is made with OpenGL

June, 27th, 2015

This program was written by DucThang
Contact:
thangdn.tlu@outlook.com

Every comment would be appreciated.

If you want to use parts of any code of mine:
let me know and
use it!
**********************************************************************
Mouse movement:
Press left mouse button: to increase radius
Press right mouse button: to reduction radius
**********************************************************************/

#include <GL/glut.h>
#include <GL/GL.H>

#define WIDTH 1000
#define HEIGHT 700
GLint r = 50;

void myDisplay();
void myMount(GLint b, GLint s, GLint x, GLint y);
void drawPoint(GLfloat x, GLfloat y);
void drawCirleTD(GLint xt, GLint yt, GLint R);
void drawCirle(GLint xt, GLint yt, GLint x, GLint y);
void myInit();
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Example 1.2");
	glutMouseFunc(myMount);
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
		glColor3f(1, 0, 1);
		glPointSize(5);
		drawCirleTD(x, HEIGHT - y,r);
		r =r+ 10;
	}
	else
	{
		if (s == GLUT_DOWN&& b == GLUT_RIGHT_BUTTON)
		{

			glPointSize(5);
			glColor3f(1, 1, 0);
			drawCirleTD(x, HEIGHT - y,r);
			r = r - 15;
		}
	}
}
void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
}
void drawCirle(GLint xt, GLint yt, GLint x, GLint y)
{
	drawPoint(x + xt, y + yt);
	drawPoint(y + xt, x + yt);
	drawPoint(-x + xt, -y + yt);
	drawPoint(-y + xt, -x + yt);
	drawPoint(-x + xt, y + yt);
	drawPoint(-y + xt, x + yt);
	drawPoint(x + xt, -y + yt);
	drawPoint(y + xt, -x + yt);
}
void drawCirleTD(GLint xt, GLint yt, GLint R)
{
	GLint x=0, y =R;
	GLint d = 1 - R;
	drawPoint(xt, yt);
	drawCirle(xt, yt, x, y);
	while (x <= y)
	{
		if (d < 0)
		{
			d += (x << 1) + 3;
			x++;
		}
		else
		{
			d += ((x - y) << 1) + 5;
			x++; y--;
		}
		drawCirle(xt, yt, x, y);
	}
	glFlush();
}