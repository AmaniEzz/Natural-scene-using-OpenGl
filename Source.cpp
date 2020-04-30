#include <windows.h>
#include "freeglut_std.h"
#include <Math.h>


//variables for transition method
float x = -0.5;
bool direction = true;


//Function to draw Triangles
void drawTriangle(float x0, float y0, float red0, float green0, float blue0, 
	float x1, float y1, float red1, float green1, float blue1, 
	float x2, float y2, float red2, float green2, float blue2)
{
	glBegin(GL_TRIANGLES);
	glColor3f(red0, green0, blue0);
	glVertex2i(x0, y0);
	glColor3f(red1, green1, blue1);
	glVertex2i(x1, y1);
	glColor3f(red2, green2, blue2);
	glVertex2i(x2, y2);
	glEnd();
}

//Function to draw Polygons
void drawPolygon(float x0, float y0, float red0, float green0, float blue0,
	float x1, float y1, float red1, float green1, float blue1, 
	float x2, float y2, float red2, float green2, float blue2, 
	float x3, float y3, float red3, float green3, float blue3)
{
	glBegin(GL_POLYGON);
	glColor3f(red0, green0, blue0);
	glVertex2i(x0, y0);
	glColor3f(red1, green1, blue1);
	glVertex2i(x1, y1);
	glColor3f(red2, green2, blue2);
	glVertex2i(x2, y2);
	glColor3f(red3, green3, blue3);
	glVertex2i(x3, y3);
	glEnd();
}

void draw(void) {

	glClear(GL_COLOR_BUFFER_BIT);


	//Draw the blue sky
	drawPolygon(-100, 110, 0.0, 0.498039, 1.0,
		-100, 47, 1.0, 1.0, 1.0,
		110, 47, 1.0, 1.0, 1.0,
		110, 110, 0.74902, 0.847059, 0.847059);

	//Draw the sea
	drawPolygon(-100, 47, 0, 0.498039, 1.0,
		-100, -10, 0.0, 0.0, 1.0, 
		110, -10, 0.196078, 0.196078, 0.8, 
		110, 47, 0.184314, 0.184314, 0.309804);

	//draw mountain 1 (left)
	drawTriangle(-10.0, 85.0, 0.35, 0.16, 0.14,
		-40.0, 47.0, 0.36, 0.25, 0.20, 
		20.0, 47.0, 0.36, 0.25, 0.20);
    //draw mountain 3 (Mid)
	drawTriangle(20.0, 75.0, 0.52, 0.37, 0.26, 
		-8.0, 47.0, 0.36, 0.25, 0.20, 
		42.0, 47.0, 0.35, 0.16, 0.14);

	//draw mountain 2 (right)
	drawTriangle(40.0, 65.0, 0.35, 0.16, 0.14, 
		0.0, 47.0, 0.36, 0.25, 0.20, 
		60.0, 47.0, 0.36, 0.25, 0.20);

	

	//draw and Translate for the ship to left and down
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x, -0.2, 0);

	//Ship part 1 of 6 From the bottom up
	drawPolygon(27, 8, 0.658824, 0.658824, 0.658824,
		30.2, 5, 0.658824, 0.658824, 0.658824, 
		60.8, 5, 0, 0, 0, 63, 8, 0, 0, 0);

	//Ship part 2 of 6 From the bottom up
	drawPolygon(20, 18, 0.35, 0.16, 0.14, 
		27, 8, 0.35, 0.16, 0.14, 
		63, 8, 0.647059, 0.164706, 0.164706, 
		70, 18, 0.647059, 0.164706, 0.164706);

	//Ship part 3 of 6 From the bottom up
	drawPolygon(20, 20, 0.59, 0.41, 0.31, 
		20, 18, 0.59, 0.41, 0.31, 
		70, 18, 0.59, 0.41, 0.31, 
		70, 20, 0.59, 0.41, 0.31);

	//Ship part 4 of 6 From the bottom up
	drawPolygon(23, 25, 0.329412, 0.329412, 0.329412, 
		23, 20, 0.329412, 0.329412, 0.329412, 
		67, 20, 0.329412, 0.329412, 0.329412, 
		67, 25, 0.329412, 0.329412, 0.329412);

	//Ship part 5 of 6 From the bottom up
	drawPolygon(27, 33, 0.658824, 0.658824, 0.658824, 
		27, 25, 0.658824, 0.658824, 0.658824, 
		65, 25, 0.658824, 0.658824, 0.658824, 
		60.5, 33, 0.658824, 0.658824, 0.658824);

	//Ship part 6 of 6 From the bottom up
	drawPolygon(32, 35, 0.59, 0.41, 0.31,
		27, 33, 0.59, 0.41, 0.31, 
		60.5, 33, 0.59, 0.41, 0.31, 
		55, 35, 0.59, 0.41, 0.31);

	//Long - ship chimney
	drawPolygon(36, 40, 0, 0, 0,
		36, 35, 0, 0, 0, 
		38, 35, 0, 0, 0, 
		38, 40, 0, 0, 0);

	//Long chimney head
	drawPolygon(36, 40, 0.52, 0.37, 0.26, 
		36, 39.5, 0.52, 0.37, 0.26, 
		38, 39.5, 0.52, 0.37, 0.26,
		38, 40, 0.52, 0.37, 0.26);


	//Short - ship chimney
	drawPolygon(40, 38.5, 0, 0, 0, 
		40, 35, 0, 0, 0, 
		43, 35, 0, 0, 0, 
		43, 38.5, 0, 0, 0);

	//Short chimney head
	drawPolygon(40, 38.5, 0.52, 0.37, 0.26, 
		40, 37, 0.52, 0.37, 0.26, 
		43, 37, 0.52, 0.37, 0.26, 
		43, 38.5, 0.52, 0.37, 0.26);

	// Drawing the ship's window/
		drawPolygon(51, 31.9, 0.80, 0.80, 0.80,
			51, 26.5, 0.80, 0.80, 0.80, 
			64.9, 26.5, 0.80, 0.80, 0.80,
			61.9, 31.9, 0.0, 0.498039, 1.0);

	glPopMatrix();

	//boat1 base (Polygon)
	drawPolygon(75, 29, 0.36, 0.25, 0.20,
		90,	29, 0.36, 0.25, 0.20,
		86, 21, 0.36, 0.25, 0.20, 
		79, 21, 0.36, 0.25, 0.20);

	//boat1 right triangle
	drawTriangle(84, 30, 0.80, 0.80, 0.80,
		84, 44, 0.80, 0.80, 0.80,
		89, 30, 0.80, 0.80, 0.80);

	//boat1 left triangle
	drawTriangle(81, 30, 0.80, 0.80, 0.80, 
		83, 39, 0.80, 0.80, 0.80, 83, 
		30, 0.80, 0.80, 0.80);

	//draw and scale for boat2 make it smaller and down
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);

	//boat2 base (Polygon)
	drawPolygon(75, 29, 0.36, 0.25, 0.20,
		90, 29, 0.36, 0.25, 0.20,
		86, 21, 0.36, 0.25, 0.20, 
		79, 21, 0.36, 0.25, 0.20);

	//boat2 right triangle
	drawTriangle(84, 30, 0.80, 0.80, 0.80, 
		84, 44, 0.80, 0.80, 0.80, 
		89, 30, 0.80, 0.80, 0.80);

	//boat2 left triangle
	drawTriangle(81, 30, 0.80, 0.80, 0.80, 
		83, 39, 0.80, 0.80, 0.80, 
		83, 30, 0.80, 0.80, 0.80);

	glPopMatrix();
	glFlush();
}

//animation for the ship to the right direction
void transition() {

	if (direction) {
		x += 0.00005;
		if (x > 0.1)
			direction = false;

	}
	glutPostRedisplay();
}


//method for when press ESC it end the running of the program
void NormalKey(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void main()
{
	char fakeParam[] = "fake";
	char* fakeargv[] = { fakeParam, NULL };
	int fakeargc = 1;
	glutInit(&fakeargc, fakeargv);

	glutInitWindowSize(1900, 600);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("project");
	glutDisplayFunc(draw);
	glutIdleFunc(transition);
	glOrtho(-20.0, 110.0, -10.0, 110.0, 0.0, 1.0);
	glutKeyboardFunc(NormalKey);
	glutMainLoop();
}