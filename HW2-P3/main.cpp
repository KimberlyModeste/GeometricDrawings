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

int clicker = 1;
bool hasClicked = false;

void ngon(int n, float cx, float cy, float radius, float rotAngle) {
	if (n < 3) return;
	double angle = rotAngle * 3.14159265 / 180;
	double angleInc = 2 * 3.14159265 / n;
	cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle) + cy);

	for (int k = 0; k <= n; k++)
	{
		if (isOut)
		{
			outer[k].set(radius * cos(angle) + cx, radius * sin(angle) + cy);
			cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
		}
			
		else if (!isOut)
			inner[k].set(radius * cos(angle) + cx, radius * sin(angle) + cy);

		angle += angleInc;
	}
}

void drawA(int x, int y) {
	
	isOut = true;
	
	ngon(3, x, y, 50.0, 90.0);

	isOut = false;

	ngon(3, x, y+4, 5.0, 30.0);
	cvs.moveTo(outer[0]);
	cvs.lineTo(inner[0]);
	cvs.lineTo(outer[2]);
	cvs.lineTo(inner[2]);
	cvs.lineTo(outer[1]);
	cvs.lineTo(inner[1]);
	cvs.lineTo(outer[0]);
}

void drawB(int x, int y) {

	isOut = true;
	
	ngon(5, x, y, 50.0, 18.0);

	isOut = false;

	ngon(5, x, y, 5.0, 53.0);

	cvs.moveTo(outer[0]);
	cvs.lineTo(inner[4]);
	cvs.lineTo(outer[4]);
	cvs.lineTo(inner[3]);
	cvs.lineTo(outer[3]);
	cvs.lineTo(inner[2]);
	cvs.lineTo(outer[2]);
	cvs.lineTo(inner[1]);
	cvs.lineTo(outer[1]);
	cvs.lineTo(inner[0]);
	cvs.lineTo(outer[0]);

}

void drawC(int x, int y) {

	
	isOut = true;
	ngon(7, x, y, 50.0, 38.5);
	isOut = false;
	ngon(7, x, y, 10.0, 13.0);


	cvs.moveTo(outer[0]);
	cvs.lineTo(inner[1]);
	cvs.lineTo(outer[1]);
	cvs.lineTo(inner[2]);
	cvs.lineTo(outer[2]);
	cvs.lineTo(inner[3]);
	cvs.lineTo(outer[3]);
	cvs.lineTo(inner[4]);
	cvs.lineTo(outer[4]);
	cvs.lineTo(inner[5]);
	cvs.lineTo(outer[5]);
	cvs.lineTo(inner[6]);
	cvs.lineTo(outer[6]);
	cvs.lineTo(inner[0]);
	cvs.lineTo(outer[0]);


}

void drawD(int x, int y) {
	
	isOut = true;
	ngon(6, x, y, 50.0, 90.0);

	isOut = false;
	ngon(6, x, y, 15.0, 0.0);


	cvs.moveTo(outer[0]);
	cvs.lineTo(inner[1]);
	cvs.lineTo(outer[5]);
	cvs.lineTo(inner[0]);
	cvs.lineTo(outer[4]);
	cvs.lineTo(inner[5]);
	cvs.lineTo(outer[3]);
	cvs.lineTo(inner[4]);
	cvs.lineTo(outer[2]);
	cvs.lineTo(inner[3]);
	cvs.lineTo(outer[1]);
	cvs.lineTo(inner[2]);
	cvs.lineTo(outer[0]);

	isOut = true;
	ngon(60, x, y, 15.0, 0.0);
	
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
	}
	hasClicked = true;
}

void mainMenu(int id) {
		clicker = id;
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

	//White
	else if (id == 9) 
		cvs.setColor(1.0, 1.0, 1.0);



	//Red Background
	if (id == 10)
	{
		cvs.setBackgroundColor(1.0, 0.0, 0.0);
		cvs.clearScreen();
	}

	//Green Background
	else if (id == 11)
	{
		cvs.setBackgroundColor(0.0, 1.0, 0.0);
		cvs.clearScreen();
	}

	//Blue Background
	else if (id == 12)
	{
		cvs.setBackgroundColor(0.0, 0.0, 1.0);
		cvs.clearScreen();
	}

	//Cyan Background
	else if (id == 13)
	{
		cvs.setBackgroundColor(0.0, 1.0, 1.0);
		cvs.clearScreen();
	}
	
	//Magenta Background
	else if (id == 14)
	{
		cvs.setBackgroundColor(1.0, 0.0, 1.0);
		cvs.clearScreen();
	}
	
	//Yellow Background
	else if (id == 15)
	{
		glClearColor(1.0, 1.0, 0.0, 0.0);
		cvs.clearScreen();
	}
	
	//Orange Background
	else if (id == 16)
	{
		cvs.setBackgroundColor(0.98, 0.63, 0.12);
		cvs.clearScreen();
	}
	
	//Black Background
	else if (id == 17)
	{
		cvs.setBackgroundColor(0.0, 0.0, 0.0);
		cvs.clearScreen();
	}
	
	//White Background
	else if (id == 18)
	{
		cvs.setBackgroundColor(1.0, 1.0, 1.0);
		cvs.clearScreen();
	}
}

void backgroundMenu(int id) {
	if (id == 1)
		cvs.clearScreen();

	 else if (id == 2)
		 exit(0);
}

void display() {

	//Do this only once
	if (!hasClicked)
	{
		cvs.clearScreen();
		cvs.setColor(0.0, 0.0, 0.0);
		cvs.setBackgroundColor(1.0, 1.0, 1.0);	
	}

	cvs.setWindow(0.0, 640.0, 0.0, 640.0);
	cvs.setViewport(0, 640, 0, 640);

	//Mouse stuff
	glutMouseFunc(myMouse);

}


void main(int argc, char** argv)
{
	//colors and background
	int c_menu, bc_menu, b_menu;

	//Line colors
	c_menu = glutCreateMenu(colorsMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Cyan", 4);
	glutAddMenuEntry("Magenta", 5);
	glutAddMenuEntry("Yellow", 6);
	glutAddMenuEntry("Orange", 7);
	glutAddMenuEntry("Black", 8);
	glutAddMenuEntry("White", 9);

	//Background colors
	bc_menu = glutCreateMenu(colorsMenu);
	glutAddMenuEntry("Red", 10);
	glutAddMenuEntry("Green", 11);
	glutAddMenuEntry("Blue", 12);
	glutAddMenuEntry("Cyan", 13);
	glutAddMenuEntry("Magenta", 14);
	glutAddMenuEntry("Yellow", 15);
	glutAddMenuEntry("Orange", 16);
	glutAddMenuEntry("Black", 17);
	glutAddMenuEntry("White", 18);


	//Background 
	b_menu = glutCreateMenu(backgroundMenu);
	glutAddSubMenu("Background Colors", bc_menu);
	glutAddMenuEntry("Clear Screen", 1);
	glutAddMenuEntry("Quit", 2);
	
	//MAin menu
	glutCreateMenu(mainMenu);
	glutAddSubMenu("Colors", c_menu);
	glutAddSubMenu("Background Menu", b_menu);
	glutAddMenuEntry("Shape A", 1);
	glutAddMenuEntry("Shape B", 2);
	glutAddMenuEntry("Shape C", 3);
	glutAddMenuEntry("Shape D", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glFlush();
	glutMainLoop();
}