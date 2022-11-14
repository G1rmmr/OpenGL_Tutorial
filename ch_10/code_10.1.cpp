/*

#include <GL/glut.h>

//Initialization of window
static void Init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);

	glutCreateWindow("A teapot");
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

//It updates the aspect of window
static void Reshape(int width, int height) {
	float aspect = float(width) / float(height);
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0 * aspect, 2.0 * aspect, -2.0, 2.0, -2.0, 2.0);
	glutPostRedisplay();
}

static void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0, 0.0, 0.0);
	glutWireTeapot(1.0);
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	Init(argc, argv);
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}

*/