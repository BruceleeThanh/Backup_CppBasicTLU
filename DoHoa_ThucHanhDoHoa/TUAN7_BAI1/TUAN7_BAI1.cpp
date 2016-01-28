/**********************************************************************

Program make 3Dsamples and control with your mouse and keyboard is made with OpenGL

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
Press,hold left mouse button and move: to change light point

Keyboard movement:
p: automatic rotary
z ->turn left around x axis
x ->turn left around y axis
c ->turn left around z axis

t ->turn right around x axis
y ->turn right around y axis
u ->turn right around z axis
**********************************************************************/

#include <GL\glut.h>
#include <GL\GL.h>

#define WIDTH 500
#define HEIGHT 500

GLfloat rand2=0;
GLfloat rand1 = 0,rand3=0;
int a[3] = { 1.0, 1.0, 1.0 }, b[3] = { 1.0, -1.0, 1.0 },
c[3] = { -1.0, -1.0, 1.0 }, d[3] = { -1.0, 1.0, 1.0 },
e[3] = { 1.0, 1.0, -1.0 }, f[3] = { 1.0, -1.0, -1.0 },
g[3] = { -1.0, -1.0, -1.0 }, h[3] = { -1.0, 1.0, -1.0 };
GLint px=0, py=0;
void myDisplay();
void myKeyBoard(unsigned char key, GLint x, GLint y);
void myReshape(GLint x, GLint y);
void drawCube();
void drawChop();
void Init();
void myMotion(GLint x, GLint y);
void main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("example 7.1");
	Init();
	glutDisplayFunc(myDisplay);
	glutMotionFunc(myMotion);
	glutKeyboardFunc(myKeyBoard);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
void Init()
{
	//GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat mat_shininess[] = { 50.0 };
	//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	//glClearColor(1.0, 1.0, 1.0, 0.0);  
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	//glShadeModel(GL_SMOOTH); 
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);  
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);  
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);  
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	GLfloat qaAmbientLight[] = { 1.0, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 1.0, 1.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1, 1, 1, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	
}

void myDisplay()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glLoadIdentity();
	gluLookAt(5.0, 0.0,0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	GLfloat qaLightPosition[] = { px, py, 0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	/*glEnable(GL_CULL_FACE);    
	glCullFace(GL_BACK);*/
	glPushMatrix();
	glRotatef(rand1, 1, 0, 0);
	glRotatef(rand2, 0, 1, 0);
	glRotatef(rand3, 0, 0, 1);
	//drawCube();
	glutSolidTeapot(2);
	glPopMatrix();
	glFlush();
}
void myKeyBoard(unsigned char key, GLint x, GLint y)
{
	if (key == 'x')
	{
		rand1 += 10;
		glutPostRedisplay();
		
	}
	if (key == 'y')
	{
		rand1 -= 10;
		glutPostRedisplay();
		
	}
	if (key == 'z')
	{
		rand2 += 10;
		glutPostRedisplay();

	}
	if (key == 't')
	{
		rand2 -= 10;
		glutPostRedisplay();

	}
	if (key == 'c')
	{
		rand3 += 10;
		glutPostRedisplay();

	}
	if (key == 'u')
	{
		rand3 -= 10;
		glutPostRedisplay();

	}
}
void myReshape(GLint x, GLint y)
{
	glViewport(0, 0, (GLsizei)x, (GLsizei)y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
	if (x <= y)      
		glOrtho(-5, 5, -5*(GLfloat)y / (GLfloat)x, 5*(GLfloat)y / (GLfloat)x, -10.0, 10.0); 
	else      
		glOrtho(-5*(GLfloat)x / (GLfloat)y, 5*(GLfloat)x / (GLfloat)y, -5, 5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0, 10, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void drawCube()
{
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3iv(a);
	glVertex3iv(d);
	glVertex3iv(c);
	glVertex3iv(b);
	glEnd();
	//
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3iv(a);
	glVertex3iv(b);
	glVertex3iv(f);
	glVertex3iv(e);
	glEnd();
	//
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3iv(d);
	glVertex3iv(h);
	glVertex3iv(g);
	glVertex3iv(c);
	glEnd();
	//
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3iv(d);
	glVertex3iv(a);
	glVertex3iv(e);
	glVertex3iv(h);
	glEnd();
	//
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3iv(e);
	glVertex3iv(f);
	glVertex3iv(g);
	glVertex3iv(h);
	glEnd();
	//
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3iv(b);
	glVertex3iv(c);
	glVertex3iv(g);
	glVertex3iv(f);
	glEnd();
	glFlush();
}
void drawChop()
{
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3i(0,0,0);
	glVertex3i(2,0,0);
	glVertex3i(2,0,2);
	glVertex3i(0,0,2);
	glEnd();
	//
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3i(0,0,0);
	glVertex3i(2,0,0);
	glVertex3i(2,2,0);
	glVertex3i(0,2,0);
	glEnd();
	//
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3i(0,0,2);
	glVertex3i(0,1,2);
	glVertex3i(2,1,2);
	glVertex3i(2,0,2);
	glEnd();
	//
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3i(0,1,2);
	glVertex3i(0,1,1);
	glVertex3i(2,1,1);
	glVertex3i(2,1,2);
	glEnd();
	//
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3i(0,1,1);
	glVertex3i(0,2,1);
	glVertex3i(2,2,1);
	glVertex3i(2,1,1);
	glEnd();
	//
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3i(0,2,1);
	glVertex3i(0,2,0);
	glVertex3i(2,2,0);
	glVertex3i(2,2,1);
	glEnd();
	//
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3i(2,0,2);
	glVertex3i(2,0,0);
	glVertex3i(2,2,0);
	glVertex3i(2,2,1);
	glVertex3i(2, 1, 1);
	glVertex3i(02, 1, 2);
	glEnd();
	//
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3i(0,0,0);
	glVertex3i(0,2,0);
	glVertex3i(0,2,1);
	glVertex3i(0,1,1);
	glVertex3i(0, 1, 2);
	glVertex3i(0, 0, 2);
	glEnd();
}
void myMotion(GLint x, GLint y)
{
	px = x; py = y;
	glutPostRedisplay();
}