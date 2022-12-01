
// copyright 2022 Nam Ji-Won

#include <cmath>
#include <GL/glut.h>

static const short tex_size = 16;
static GLubyte tex[tex_size][tex_size][3];

static void CreateTex() {
	for (int i = 0; i < tex_size; ++i) {
		for (int j = 0; j < tex_size; ++j) {
			for (int k = 0; k < 3; ++k) {
				tex[i][j][k] = static_cast<GLubyte>(
					255 * static_cast<float>(rand() % 1000) / 999.0);
			}
		}
	}
}

static void SetupTex() {
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		tex_size, tex_size, 0, GL_RGB,
		GL_UNSIGNED_BYTE, &tex[0][0][0]);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glEnable(GL_TEXTURE_2D);
}

static void Init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Texture");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100.0);
}

static void Display() {
	const float m = -1, n = 1;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, -1, 0, 0, 0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(m, n, 0);

	glTexCoord2f(0, 0);
	glVertex3f(m, m, 0);

	glTexCoord2f(1, 0);
	glVertex3f(n, m, 0);

	glTexCoord2f(1, 1);
	glVertex3f(n, n, 0);

	glEnd();
}

int main(int argc, char* argv[]) {
	Init(argc, argv);
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMainLoop();
	return 0;
}