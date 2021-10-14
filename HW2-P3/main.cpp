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

GLint p = 1;
int clicker = 1;

void drawA(int x, int y) {

}

void drawB(int x, int y) {

}

void drawC(int x, int y) {

}

void drawD(int x, int y) {

}

void myMouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (clicker == 1)
			drawA(x, 680-y);

		else if (clicker == 2)
			drawB(x, 680 - y);

		else if (clicker == 3)
			drawC(x, 680 - y);

		else if (clicker == 4)
			drawD(x, 680 - y);

		cout << "In clicker my numeber is " << clicker << endl;
		
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
		cvs.setColor(1.0, 0.0, 0.0);
	
	//Green
	else if (id == 2)
		cvs.setColor(0.0, 1.0, 0.0);
	
	//Blue
	else if (id == 3)
		cvs.setColor(0.0, 0.0, 1.0);

	//Cyan
	else if (id == 4)
		cvs.setColor(0.0, 1.0, 1.0);

	//Magenta
	else if (id == 5)
		cvs.setColor(1.0, 0.0, 1.0);

	//Yellow
	else if (id == 6)
		cvs.setColor(1.0, 1.0, 0.0);

	//Orange
	else if (id == 7)
		cvs.setColor(0.98, 0.63, 0.12);

	//Black
	else if (id == 8)
		cvs.setColor(0.0, 0.0, 0.0);
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

	cvs.clearScreen();
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	cvs.setColor(0.0, 0.0, 0.0);
	cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
	cvs.setViewport(10, 460, 10, 460);


	//Mouse stuff
	glutMouseFunc(myMouse);
	glFlush();
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
	glutMainLoop();
}