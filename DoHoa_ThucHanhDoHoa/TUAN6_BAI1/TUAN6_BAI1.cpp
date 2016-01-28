/**********************************************************************

Make a curve with OpenGL

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
#include <GL\GLU.h>
#include <GL\GL.h>

#define WIDTH 500
#define HEIGHT 500
GLfloat ctrlpoint[4][3] = { { -4, -4, 0 }, { -2, 4, 0 },
{ 2, -4, 0 }, { 4, 4, 0 } };

void myDisplay();
void myReshape(GLint x, GLint y);
void myInit();

void main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("example 6.1");
	myInit();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)
	{
		glEvalCoord1f((GLfloat)i / 30.0);
	}
	glEnd();
	glPointSize(5);
	glColor3f(1, 1, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; i++)
	{
		glVertex3fv(&ctrlpoint[i][0]);
	}
	glEnd();
	glFlush();
}

void myReshape(GLint x, GLint y)
{
	glViewport(0, 0, (GLsizei)x, (GLsizei)y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1, 1, -1, 1, 1, 20);
	if (x <= y)
	{
		glOrtho(-5, 5, -5 * (GLfloat)x / y, 5 * (GLfloat)y / x, -5, 5);
	}
	else
	{
		glOrtho(-5 * (GLfloat)x / y, 5 * (GLfloat)y / x, -5, 5, -5, 5);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void myInit()
{
	glClearColor(0,0,0,0);
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoint[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
}