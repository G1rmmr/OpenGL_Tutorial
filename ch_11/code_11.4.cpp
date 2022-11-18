/*

// copyright 2022 Nam Ji-Won

#include <cmath>
#include <GL/glut.h>

static GLfloat // Values for material specification
g_mat_specular[] = { 1.0, 1.0, 1.0, 1.0 },
g_mat_diffuse[] = { 0.0, 1.0, 1.0, 1.0 },
g_mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 },
g_mat_shininess[] = { 120.0 };

static GLfloat // Values for light specification
g_lit_specular[] = { 1.0, 1.0, 1.0, 1.0 },
g_lit_diffuse[] = { 0.0, 1.0, 1.0, 1.0 },
g_lit_ambient[] = { 0.5, 0.0, 0.0, 1.0 };

// Values for light positioning
static GLfloat g_light_position[] = { 1.0, 1.0, 1.0, 0.0 };

static void SetLight() {
	glMaterialfv(GL_FRONT, GL_SPECULAR, g_mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, g_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, g_mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, g_mat_shininess);

	glLightfv(GL_LIGHT0, GL_SPECULAR, g_lit_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, g_lit_diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, g_lit_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

static void PositioningLight() {
	glLightfv(GL_LIGHT0, GL_POSITION, g_light_position);
}

//Initialization of window
static void Init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Teapots");

	glClearColor(0.0, 0.0, 0.0, 1.0);
	SetLight();
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100.0);
}

static void Display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(2.5, 2.5, 5, 2.5, 2.5, 0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	PositioningLight();

	for (int i = 0; i < 5; ++i) {
		glMaterialf(GL_FRONT, GL_SHININESS, 4.0 + 123.0 * (i / 4.0));

		for (int j = 0; j < 5; ++j) {
			glPushMatrix();
			glTranslated(static_cast<float>(i) + 0.5, static_cast<float>(j) + 0.5, 0.0);
			glRotated(45, 1, 1, 1);
			glutSolidTeapot(0.4);
			glPopMatrix();
		}
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	Init(argc, argv);
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMainLoop();
	return 0;
}

*/

