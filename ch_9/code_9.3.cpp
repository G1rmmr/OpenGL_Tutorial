/*

#include <cmath>
#include <GL/glut.h>

//Initialization of window
static void Init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);

	glutCreateWindow("A Cube");
	glClearColor(0.7, 0.7, 0.7, 1.0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100.0);
}

//It draws a landscape scene
static void Draw() {
	glutWireTeapot(0.3);
}

static void DrawAxes() {
	//Lines primitive
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();
}

static void MyDisplay() {
	static float t = 0.0;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(2.0 * sin(t) + 1, 3, 2.0 * cos(t) + 1, 0, 0, 0, 0, 1, 0);
	t += 0.01;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawAxes();
	glColor4f(1.0, 1.0, 0.0, 0.25);
	Draw();

	glTranslatef(1.0, 0.0, 0.0);

	DrawAxes();
	glColor4f(0.0, 1.0, 1.0, 0.25);
	Draw();

	glRotatef(180.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -1.0, 0.0);

	DrawAxes();
	glColor4f(1.0, 0.0, 0.0, 0.25);
	Draw();

	glTranslatef(1.0, 0.0, 0.0);

	DrawAxes();
	glColor4f(1.0, 1.0, 1.0, 0.25);
	Draw();
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	Init(argc, argv);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyDisplay);
	glutMainLoop();
	return 0;
}

*/