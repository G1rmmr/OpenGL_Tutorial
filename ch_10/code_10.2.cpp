/*

// Copyright 2022 Nam Ji-won

#include <GL/glut.h>

static bool g_ortho_camera = true;
static float g_aspect_ratio = 1.0, g_zoom_factor = 1.0;

// It helps control camera
static void SetCamera(void) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (g_ortho_camera) {
    glOrtho(-2.0 * g_aspect_ratio / g_zoom_factor,
            2.0 * g_aspect_ratio / g_zoom_factor, -2.0 / g_zoom_factor,
            2.0 / g_zoom_factor, -200.0, 200.0);
  } else {
    gluPerspective(60 / g_zoom_factor, g_aspect_ratio, 0.1, 100);
  }
}

// Initialization of window
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

static void Keyboard(const unsigned char const key, const int const x,
                     const int const y) {
  switch (key) {
    case 'm':
      g_ortho_camera = g_ortho_camera ? false : true;
      break;

    case '<':
      g_zoom_factor *= 0.95;
      break;

    case '>':
      g_zoom_factor *= 1.05;
      break;

    default:
      break;
  }
  SetCamera();
  glutPostRedisplay();
}

// It updates the aspect of window
static void Reshape(int width, int height) {
  g_aspect_ratio = static_cast<float>(width / height);
  glViewport(0, 0, width, height);
  SetCamera();
}

static void Display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glColor3f(0.0, 0.0, 0.0);
  glutWireTeapot(1.0);
  glutSwapBuffers();
}

int main(int argc, char* argv[]) {
  Init(argc, argv);
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  glutMainLoop();
  return 0;
}

*/