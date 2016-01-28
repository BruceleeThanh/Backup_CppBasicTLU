#include <iostream>
#include <math.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
using namespace std;

// Method: Mouse actions - Tọa độ chuột được tính từ góc trên-trái của cửa sổ.
void myMouse(int b, int s, int x, int y)
{
	switch (b)
	{ // b indicates the button
	case GLUT_LEFT_BUTTON:
		if (s == GLUT_DOWN) // button pressed
			printf("\nLeft button pressed!");
		else if (s == GLUT_UP) // button released
			printf("\nLeft button released!");
		break;
	case GLUT_RIGHT_BUTTON:
		if (s == GLUT_DOWN) // button pressed
			printf("\nRight button pressed!");
		else if (s == GLUT_UP) // button released
			printf("\nRight button released!");
		break;
		// ... // other button events
	default: break;
	}
}

// Method: Keyboard actions
void myKeyboard(unsigned char c, int x, int y)
{
	switch (c)
	{ // c is the key that is hit
	case 27: // 'q' means quit
		exit(0);
		break;
	default:
		printf("\nKey %c is hit", c);
		break;
	}
}

void myDisplay(void) {
	glClearColor(1., 1., 1., 1.);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1., 0., 0.);
	//glPointSize(12.0);
	/*glBegin(GL_POINTS);
	glColor3i(0, 0, 0);
	glVertex2i(0, 300);
	glEnd();*/
	glFlush();
}
void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 150);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Vi du 1.1");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();
}