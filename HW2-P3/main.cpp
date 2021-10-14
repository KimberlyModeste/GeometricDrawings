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

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //Set display color to white
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640.0, 0, 480.0);

}

void main(int argc, char** argv)
{
	

}