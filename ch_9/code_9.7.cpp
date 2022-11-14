/*

#include <cmath>
#include <GL/glut.h>

//Initialization of window
static void Init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);

	glutCreateWindow("Solar system");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100.0);
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

//It draws a sphere
static void DrawSphere(float radius, float red, float green, float blue) {
	glColor3f(red, green, blue);
	glutSolidSphere(radius, 100, 100);
}

static void DrawCircle(float radius) {
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 50; ++i) {
		float radian = 6.28 * float(i) / 50.0;
		glVertex3f(radius * cos(radian), 0.0, radius * sin(radian));
	}
	glEnd();
}

static void DrawMercuryOrbit() { DrawCircle(3.0); }

static void DrawVenusOrbit() { DrawCircle(5.0); }

static void DrawEarthOrbit() { DrawCircle(7.0); }

static void DrawMoonOrbit() { DrawCircle(0.5); }

static void DrawMarsOrbit() { DrawCircle(10.0); }

static void DrawJupiterOrbit() { DrawCircle(14.0); }

static void DrawSatellite1Orbit() { DrawCircle(0.7); }

static void DrawSatellite2Orbit() { DrawCircle(0.9); }

static void DrawSatellite3Orbit() { DrawCircle(1.1); }

static void DrawSatellitesOrbit() {
	DrawSatellite1Orbit();
	DrawSatellite2Orbit();
	DrawSatellite3Orbit();
}

static void DrawOrbits() {
	DrawMercuryOrbit();
	DrawVenusOrbit();
	DrawEarthOrbit();
	DrawMarsOrbit();
	DrawJupiterOrbit();
}

static void DrawSun() { DrawSphere(1.0, 1.0, 0.5, 0.0); }

static void DrawMercury(float t) {
	glPushMatrix();
	glRotatef(t, 0.0, 1.0, 0.0);
	glTranslatef(3.0, 0.0, 0.0);
	DrawSphere(0.2, 0.5, 0.8, 1.0);
	glPopMatrix();
}

static void DrawVenus(float t) {
	glPushMatrix();
	glRotatef(t * 1.5, 0.0, 1.0, 0.0);
	glTranslatef(5.0, 0.0, 0.0);
	DrawSphere(0.2, 1.0, 1.0, 0.0);
	glPopMatrix();
}

static void DrawMoon(float t) {
	glPushMatrix();
	glRotatef(t * 10.0, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	DrawSphere(0.05, 1.0, 1.0, 1.0);
	glPopMatrix();
}

static void DrawEarth(float t) {
	glPushMatrix();
	glRotatef(t * 0.8, 0.0, 1.0, 0.0);
	glTranslatef(7.0, 0.0, 0.0);
	DrawSphere(0.2, 0.2, 0.2, 1.0);

	DrawMoonOrbit();
	DrawMoon(t);
	glPopMatrix();
}

static void DrawMars(float t) {
	glPushMatrix();
	glRotatef(t * 0.5, 0.0, 1.0, 0.0);
	glTranslatef(10.0, 0.0, 0.0);
	DrawSphere(0.25, 1.0, 0.5, 0.4);
	glPopMatrix();
}

static void DrawSatellite1(float t) {
	glPushMatrix();
	glRotatef(t * 10.0, 0.0, 1.0, 0.0);
	glTranslatef(0.8, 0.0, 0.0);
	DrawSphere(0.05, 1.0, 1.0, 1.0);
	glPopMatrix();
}

static void DrawSatellite2(float t) {
	glPushMatrix();
	glRotatef(t * 12.0, 0.0, 1.0, 0.0);
	glTranslatef(0.9, 0.0, 0.0);
	DrawSphere(0.07, 1.0, 1.0, 1.0);
	glPopMatrix();
}

static void DrawSatellite3(float t) {
	glPushMatrix();
	glRotatef(t * 13.0, 0.0, 1.0, 0.0);
	glTranslatef(0.7, 0.0, 0.0);
	DrawSphere(0.03, 1.0, 1.0, 1.0);
	glPopMatrix();
}

static void DrawSatellitesOfJupiter(float t) {
	DrawSatellite1(t);
	DrawSatellite2(t);
	DrawSatellite3(t);
}

static void DrawJupiter(float t) {
	glPushMatrix();
	glRotatef(t * 0.7, 0.0, 1.0, 0.0);
	glTranslatef(14.0, 0.0, 0.0);
	DrawSphere(0.5, 1.0, 0.5, 0.4);

	DrawSatellitesOrbit();
	DrawSatellitesOfJupiter(t);
	glPopMatrix();
}

static void DrawSolarSystem(float t) {
	DrawSun();
	DrawOrbits();

	DrawMercury(t);
	DrawVenus(t);
	DrawEarth(t);
	DrawMars(t);
	DrawJupiter(t);
}

static void MyDisplay() {
	static float t = 10;
	t += 1.0;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(20.0 * sin(0.02 * t), 10, 20.0 * cos(0.02 * t), 0, 0, 0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawAxes();
	DrawSolarSystem(t);

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