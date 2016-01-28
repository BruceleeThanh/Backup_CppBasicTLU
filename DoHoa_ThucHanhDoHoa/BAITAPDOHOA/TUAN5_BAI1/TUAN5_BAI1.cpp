/**********************************************************************

Program make samples and control with your mouse and keyboard is made with OpenGL

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
Press,hold left mouse button and move: to rotary or rom
Keyboard movement:
 p: automatic rotary
 x,y ->increase axis
 z,t ->reduce axis
**********************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;
#include <GL\glut.h>
#include <GL\GL.H>
#define WIDTH 500
#define HEIGHT 500
GLdouble xx = 0, yy = 0;
bool check = false;
void myDisplay();
void myMotion(GLint x, GLint y);
void myReshape(GLint x, GLint y);
void myKeyBoard(unsigned char key, GLint x, GLint y);
void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Example 5.1");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyBoard);
	glutMotionFunc(myMotion);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
GLubyte myPattern[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
void myDisplay()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	gluLookAt(xx, yy, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	int i = 0;
	do{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		//glutWireCone(1, 2, 50, 50);
		//glutWireSphere(1, 50, 50);
		//glutWireDodecahedron();
		//glutWireIcosahedron();
		//glutWireOctahedron();
		//glutWireTetrahedron();
		//glutWireTeapot(1);
		//glutWireTorus(0.5,0.2,50,50);
		if (i<=10)
		glRotatef(10, 0, 0, 1);
		else
			if (i<=20)
				glRotatef(10, 0, 1, 0);
			else if (i<=30)
				glRotatef(10, 1, 0, 0);
			else i = 0;
		glutWireCube(1);
		//glutWireTorus(0.7, 1, 50, 50);
		glFlush();
		_sleep(100);
		i++;
	} while (check);
	glPopMatrix();
	glFlush();
}

void myMotion( GLint x, GLint y)
{
	xx = x%10; yy = y%10;
	myDisplay();
}
void myReshape(GLint x, GLint y)
{
	glViewport(0, 0, (GLsizei)x, (GLsizei)y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xx, yy, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void myKeyBoard(unsigned char key, GLint x, GLint y)
{
	if (key == 'x')
	{
		xx+=0.1;
		myDisplay();
		cout << xx << ";" << yy << endl;
		return;
	}
	if (key == 'y')
	{
		yy+=0.1;
		myDisplay();
		cout << xx << ";" << yy << endl;
		return;
	}
	if (key == 'z')
	{
		xx -= 0.1;
		myDisplay();
		cout << xx << ";" << yy << endl;
		return;
	}
	if (key == 't')
	{
		yy -= 0.1;
		myDisplay();
		cout << xx << ";" << yy << endl;
		return;
	}
	if (key == 'p')
	{
		check = !check;
		myDisplay();
		return;
	}
}