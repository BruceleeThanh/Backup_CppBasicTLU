#include <gl/glut.h>
#include <gl/gl.h>
#include <iostream>
#include <string>
using namespace std;

//double x0 = 0, x1 = 0, y0 = 0, y1 = 0;

void myInit(void);
void myDisplay(void);
void myMouse(int b, int s, int x, int y);
void myKeyboard(unsigned char c, int x, int y);
void bitmap_output(int x, int y, int z, char *string, void *font);
void renderScene(void);
void writePixel(int x, int y, int cR, int cG, int cB, float size);
void DDALine(int x0, int x1, int y0, int y1);

void writePixel(int x, int y, int cR, int cG, int cB, float size){
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor3ub(cR, cG, cB);
	glVertex2i(x, y);
	glEnd();
	//glFlush();
}

void myInit(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	//renderScene();
	//DDALine(x0, x1, y0, y1);
	writePixel(0, 0, 225, 0, 0, 3);
	glColor3ub(0, 0, 0); // màu vẽ,  ub - unsigned char (byte)
	//bitmap_output(300, 300, 0, "Hello world", GLUT_BITMAP_HELVETICA_18);
}

void myMouse(int b, int s, int x, int y) {
	switch (b) {                        // b indicates the button 
	case GLUT_LEFT_BUTTON:
		if (s == GLUT_DOWN){ // button pressed
			printf("\nLeft button pressed!");
			writePixel(x, 480 - y, 225, 0, 0, 3);
			//glFlush(); //yêu cầu thực hiện lệnh
		}
		else{
			if (s == GLUT_UP){ // button released
				printf("\nLeft button released!");
			}  
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (s == GLUT_DOWN){ // button pressed
			printf("\nRight button pressed!");
			writePixel(x, 480 - y, 225, 0, 0, 3);
			//glFlush(); //yêu cầu thực hiện lệnh
		}
		else{
			if (s == GLUT_UP){ // button released
				printf("\nRight button released!");
			}
		}
		break;
	default: 
		break;
	}
}  // Tọa độ chuột được tính từ góc trên-trái của cửa sổ.

void myKeyboard(unsigned char c, int x, int y){
	string str;
	if (c != 32){
		str += c;
	}
	switch (c) {           // c is the key that is hit 
	case 27:                // ’q’ means quit
		exit(0);
		break;
	default:
		bitmap_output(x, y, 0, "Hello world", GLUT_BITMAP_TIMES_ROMAN_24);
		printf("\nKey %c is hit", c);
		break;
	}
}
void bitmap_output(int x, int y, int z, char *string, void *font){
	int len, i;
	glRasterPos3f(x, y, 0);           // Locate Raster Position in 3-space
	len = (int)strlen(string);        // Find length of string
	for (i = 0; i < len; i++) {       // Loop through plotting all characters
		glutBitmapCharacter(font, string[i]);
	}
}

// render Scene
void renderScene(void) {
	glPointSize(3.0);
	glBegin(GL_TRIANGLES); //vẽ tam giác
	glColor3ub(225, 0, 0);
	glVertex2i(100, 200);
	glVertex2i(200, 300);
	glVertex2i(100, 400);
	glEnd(); //kết thúc
	glFlush();
}

void myMotion(int x, int y){
	writePixel(x, 480 - y, 225, 0, 0, 6);
}

void DDALine(int x0, int x1, int y0, int y1){
	int x;
	double dx, dy, y, m;
	dx = (double)x1 - x0;
	dy = (double)y1 - y0;
	m = dy / dx;
	y = (double)y0;
	for (x = x0; x <= x1; x++){
		writePixel(x, 480 - (int)y, 225, 0, 0, 3);
		y = y + m;
	}
}

void main(int argc, char **argv){
	
	/*bool check = true;
	cout << "Nhap x0: ";
	cin >> x0;
	cout << "Nhap x1: ";
	cin >> x1;
	cout << "Nhap y0: ";
	cin >> y0;
	cout << "Nhap y1: ";
	cin >> y1;*/


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(150, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Brucelee Thanh");
	glClearColor(255, 255, 255, 0.0f);

	myInit();
	glutDisplayFunc(myDisplay);
	//DDALine(x0, x1, y0, y1);
	//glutDisplayFunc(renderScene);
	
	//glutMouseFunc(myMouse);
	//glutKeyboardFunc(myKeyboard);
	glutMotionFunc(myMotion);
	
	glutMainLoop();
}