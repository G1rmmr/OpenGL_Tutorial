#include <cmath>
#include <GL/glut.h>

/*
//It draws a circle at window
static void DrawCircle(float x, float y, float radius,
	float red, float green, float blue) {//RGB colors 

	const int circle_verticies = 20;
	float angle = 0.0, step = (3.141592 * 2.0) / circle_verticies;

	glBegin(GL_POLYGON);
	glColor3f(red, green, blue);

	while (angle < 3.141592 * 2.0) {
		glVertex2f(radius * cos(angle) + x, radius * sin(angle) + y);
		angle += step;
	}
	glEnd();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	//Triangles primitive
	glBegin(GL_TRIANGLES);
	//Mountain 2
	glColor3f(0.0, 1.0, 0.0);

	glVertex2f(-0.75, -0.25);
	glVertex2f(0.0, 0.25);
	glVertex2f(0.25, -0.25);

	//Mountain 2
	glColor3f(0.5, 0.5, 0.1);

	glVertex2f(-0.25, -0.25);
	glVertex2f(0.75, 0.25);
	glVertex2f(1.0, -0.25);

	glEnd();

	//Rectangles primitive
	glBegin(GL_QUADS);
	//Roof
	glColor3f(0.0, 0.0, 1.0);

	glVertex2f(-1.0, 0.25);
	glVertex2f(-0.75, 0.5);
	glVertex2f(-0.25, 0.5);
	glVertex2f(0.0, 0.25);

	//House
	glColor3f(1.0, 1.0, 0.0);

	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.75, -0.25);
	glVertex2f(-0.25, -0.25);
	glVertex2f(-0.25, 0.25);

	//Tree
	glColor3f(0.7, 0.5, 0.0);

	glVertex2f(0.5, 0.25);
	glVertex2f(0.75, 0.25);
	glVertex2f(0.75, -0.25);
	glVertex2f(0.5, -0.25);

	glEnd();

	//Circles primitive
	DrawCircle(0.0, 0.75, 0.1, 1.0, 1.0, 0.0);
	DrawCircle(0.675, 0.25, 0.25, 0.0, 1.0, 0.0);

	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);

	glutCreateWindow("A landscape");
	glutDisplayFunc(MyDisplay);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
*/