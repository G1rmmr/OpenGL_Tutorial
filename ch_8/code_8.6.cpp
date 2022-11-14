/*


#include <cmath>
#include <GL/glut.h>

//Initialization of window
static void Init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);

	glutCreateWindow("A landscape");
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100.0);
}

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

//It draws a landscape scene
static void DrawScene() {
	//Triangles primitive
	glBegin(GL_TRIANGLES);
	//Mountain 1
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
}

static void DrawAxes() {
	//Lines primitive
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();
}

static void MyDisplay() {
	static float t = 0.0;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(2.0 * sin(t), 1, 2.0 * cos(t), 0, 0, 0, 0, 1, 0);
	t += 0.00001;

	glClear(GL_COLOR_BUFFER_BIT);
	DrawScene();

	glLineWidth(5);
	DrawAxes();

	glLineWidth(1);
	glFlush();
}

int main(int argc, char* argv[]) {
	Init(argc, argv);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyDisplay);
	glutMainLoop();
	return 0;
}

*/