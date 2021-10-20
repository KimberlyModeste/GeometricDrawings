//CSC470 HW2
//Kimberly Modeste
#include <GL/glut.h>
#include <math.h>
#include <time.h> 
#include <iostream>
#include "classes.h"

using namespace std;
char title[] = "Geometric Jamboree";
Canvas cvs(640, 640, title);
Point2 outer[7];
Point2 inner[7];
bool isOut;

GLint p = 1;
int clicker = 1;
bool hasClicked = false;
float currentColor[] = { 0.0,0.0,0.0 };

void ngon(int n, float cx, float cy, float radius, float rotAngle) {
	if (n < 3) return;
	double angle = rotAngle * 3.14159265 / 180;
	double angleInc = 2 * 3.14159265 / n;
	cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
	if (!isOut)
		cvs.setColor(1.0, 1.0, 1.0);

	for (int k = 0; k <= n; k++)
	{
		cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
		angle += angleInc;

		if (isOut)
			outer[k].set(radius * cos(angle) + cx, radius * sin(angle) + cy);
		else
			inner[k].set(radius * cos(angle) + cx, radius * sin(angle) + cy);
	}
}




void drawA(int x, int y) {
	GLint o1[] = { outer[1].getX(), outer[1].getY() };
	GLint o2[] = { outer[2].getX(), outer[2].getY() };
	GLint o3[] = { outer[3].getX(), outer[3].getY() };

	GLint i1[] = { inner[1].getX(), inner[1].getY() };
	GLint i2[] = { inner[2].getX(), inner[2].getY() };
	GLint i3[] = { inner[3].getX(), inner[3].getY() };

	isOut = true;
	ngon(3, x, y, 50.0, 90.0);
	isOut = false;
	ngon(3, x, y, 5.0, 30.0);
	cvs.setColorfv(currentColor);
	cvs.moveTo(outer[1]);
	cvs.lineTo(inner[1]);
	cvs.lineTo(outer[3]);
	cvs.lineTo(inner[3]);
	cvs.lineTo(outer[2]);
	cvs.lineTo(inner[2]);
	cvs.lineTo(outer[1]);
}

void drawB(int x, int y) {

	ngon(5, x, y, 50.0, 18.0);
}

void drawC(int x, int y) {

	ngon(7, x, y, 50.0, 38.5);

}

void drawD(int x, int y) {

	ngon(6, x, y, 50.0, 90.0);
}

void myMouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (clicker == 1)
			drawA(x, 640 - y);

		else if (clicker == 2)
			drawB(x, 640 - y);

		else if (clicker == 3)
			drawC(x, 640 - y);

		else if (clicker == 4)
			drawD(x, 640 - y);

		hasClicked = true;
	}

}

void mainMenu(int id) {
	if (id > 0 && id < 5)
		clicker = id;

	else if (id == 5)
		exit(0);

	cout << clicker << endl;
}

void colorsMenu(int id) {

	//Red
	if (id == 1)
	{
		cvs.setColor(1.0, 0.0, 0.0);
		currentColor[0] = 1.0;  currentColor[1] = 0.0; currentColor[2] = 0.0;
	}	

	//Green
	else if (id == 2)
	{
		cvs.setColor(0.0, 1.0, 0.0);
		currentColor[0] = 0.0;  currentColor[1] = 1.0; currentColor[2] = 0.0;
	}

	//Blue
	else if (id == 3)
	{
		cvs.setColor(0.0, 0.0, 1.0);
		currentColor[0] = 0.0;  currentColor[1] = 0.0; currentColor[2] = 1.0;
	}

	//Cyan
	else if (id == 4)
	{
		cvs.setColor(0.0, 1.0, 1.0);
		currentColor[0] = 0.0;  currentColor[1] = 1.0; currentColor[2] = 1.0;
	}

	//Magenta
	else if (id == 5)
	{
		cvs.setColor(1.0, 0.0, 1.0);
		currentColor[0] = 1.0;  currentColor[1] = 0.0; currentColor[2] = 1.0;

	}

	//Yellow
	else if (id == 6)
	{
		cvs.setColor(1.0, 1.0, 0.0);
		currentColor[0] = 1.0;  currentColor[1] = 1.0; currentColor[2] = 0.0;

	}

	//Orange
	else if (id == 7)
	{
		cvs.setColor(0.98, 0.63, 0.12);
		currentColor[0] = 0.98;  currentColor[1] = 0.63; currentColor[2] = 0.12;

	}

	//Black
	else if (id == 8)
	{
		cvs.setColor(0.0, 0.0, 0.0);
		currentColor[0] = 0.0;  currentColor[1] = 0.0; currentColor[2] = 0.0;

	}
}

void pixelMenu(int id) {
	if (id == 1)
		p = p * 2;

	else if (id == 2)
		if (p > 1)
			p = p * 0.5;

	glPointSize(p);
}

void display() {

	if (!hasClicked)
	{
		cvs.clearScreen();
		cvs.setColor(0.0, 0.0, 0.0);
	}		
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	cvs.setWindow(0.0, 640.0, 0.0, 640.0);
	cvs.setViewport(0, 640, 0, 640);

	//Mouse stuff
	glutMouseFunc(myMouse);

}


void main(int argc, char** argv)
{
	//color for lines and line thickness
	int c_menu, p_menu;

	c_menu = glutCreateMenu(colorsMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Cyan", 4);
	glutAddMenuEntry("Magenta", 5);
	glutAddMenuEntry("Yellow", 6);
	glutAddMenuEntry("Orange", 7);
	glutAddMenuEntry("Black", 8);

	p_menu = glutCreateMenu(pixelMenu);
	glutAddMenuEntry("Increase Pixel Size", 1);
	glutAddMenuEntry("Decrease Pixel Size", 2);


	glutCreateMenu(mainMenu);
	glutAddSubMenu("Colors", c_menu);
	glutAddSubMenu("Pixel Size", p_menu);
	glutAddMenuEntry("Shape A", 1);
	glutAddMenuEntry("Shape B", 2);
	glutAddMenuEntry("Shape C", 3);
	glutAddMenuEntry("Shape D", 4);
	glutAddMenuEntry("Quit", 5);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glFlush();
	glutMainLoop();
}