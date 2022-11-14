/*

#include <cmath>
#include <GL/glut.h>

//Initialization of window
static void Init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);

	glutCreateWindow("A Robot arm");
	glClearColor(0.7, 0.7, 0.7, 1.0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100.0);
}

//It draws a robot arm
static void DrawArm() {
	glPushMatrix();
	glScalef(1.0, 4.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
}

//It draws a robot hand
static void DrawHand() {
	glPushMatrix();
	glScalef(1.0, 2.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
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

static void DrawArmWithAxes() {
	DrawAxes();
	DrawArm();
}

static void DrawHandWithAxes() {
	DrawAxes();
	DrawHand();
}

static void MyDisplay() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 15, 0, 0, 0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glTranslatef(0.0, 2.0, 0.0);

	DrawArmWithAxes();

	glTranslated(0.0, 2.0, 0.0);
	glRotatef(-45, 0.0, 0.0, 1.0);
	glTranslated(0.0, 2.0, 0.0);

	DrawArmWithAxes();

	glPushMatrix();
	glTranslated(0.0, 2.0, 0.0);
	glRotatef(-45, 0.0, 0.0, 1.0);
	glTranslated(0.0, 1.0, 0.0);

	DrawHandWithAxes();
	glPopMatrix();

	glTranslated(0.0, 2.0, 0.0);
	glRotatef(45, 0.0, 0.0, 1.0);
	glTranslated(0.0, 1.0, 0.0);

	DrawHandWithAxes();

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