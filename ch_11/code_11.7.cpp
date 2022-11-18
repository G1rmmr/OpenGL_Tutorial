/*

// copyright 2022 Nam Ji-Won

#include <cmath>
#include <GL/glut.h>

//Initialization of window
static void Init(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(512, 512);
  glutCreateWindow("Normals");

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1.0, 0.1, 100.0);
}

static void Display() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(1, 2, -2, 1, 0, 0, 0, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glNormal3f(0, 1, 0);
    glVertex3f(0, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glNormal3f(2 / sqrt(3), 1 / sqrt(3), 0);
    glVertex3f(2, 0, 0);

    glColor3f(0.0, 0.0, 1.0);
    glNormal3f(-2 / sqrt(3), 1 / sqrt(3), 0);
    glVertex3f(1, 0, -1);
  glEnd();

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