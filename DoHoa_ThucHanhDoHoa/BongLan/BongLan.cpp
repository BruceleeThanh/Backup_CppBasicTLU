/**********************************************************************

The program that makes a truck is made with OpenGL

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
#include<GL\glut.h>
#include <GL\GL.h>

#define WIDTH 1000
#define HEIGH 500
GLint x, y;
int ran = 10;
int xx = 0;

void myInit();
void myDisplay();
void my();

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGH);
	glutCreateWindow("Bong lan");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIDTH, 0, HEIGH);
	glFlush();
}

void myDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	while (true)
	{
		my();
		_sleep(0);
	}
	glFlush();
}

void my()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//
	glColor3f(1, 0, 1);
	glPushMatrix();
		glTranslated(xx, 0, 0);
		glRecti(-20, 170, 170, 270);
		glRecti(170, 170, 310, 350);
		glColor3f(1, 1, 1);
		glRecti(200, 260, 300, 330);
	glPopMatrix();
	//
	glColor3f(1, 1, 0);
	glPushMatrix();
		glTranslatef(xx+50, 150, 0);
		glRotatef(ran, 0, 0, 1);
		glTranslatef(-(xx+50), -150, 0);
		glRecti(xx, 100, xx+100, 200);
		glPointSize(10);
		glColor3f(0, 0, 0);
		glBegin(GL_POINTS);
			glVertex2f(xx + 50, 150);
		glEnd();
	glPopMatrix();
	//
	glColor3f(1, 1, 0);
	glPushMatrix();
		glTranslatef(xx + 250, 150, 0);
		glRotatef(ran, 0, 0, 1);
		glTranslatef(-(xx + 250), -150, 0);
		glRecti(xx+200, 100, xx + 300, 200);
		glPointSize(10);
		glColor3f(0, 0, 0);
		glBegin(GL_POINTS);
			glVertex2f(xx + 250, 150);
		glEnd();
	glPopMatrix();
	xx += 1;
	ran += 5;
	if (xx > WIDTH)xx = 0;
	glFlush();
}