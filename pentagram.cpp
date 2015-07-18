#include "stdafx.h"

#include<glut.h>
#pragma comment (lib, "opengl32.lib") /* link with Microsoft OpenGL lib */
#pragma comment (lib, "glu32.lib") /* link with OpenGL Utility lib */
#pragma comment (lib, "glut32.lib") /* link with Win32 GLUT lib */

int screen_width=640;
int screen_height=480;

void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_COLOR_MATERIAL);
}

void resize (int w, int h) {
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0, w, h, 0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}
struct POINT {
	GLfloat x;
	GLfloat y;
};

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT );
  glLoadIdentity();
  glColor3f(1.0f,1.0f,0.0f);
  POINT p1,p2,p3,p4,p5;
  p1.x=300;p1.y=200;
  p2.x=260;p2.y=300;
  p3.x=350;p3.y=240;
  p4.x=250;p4.y=240;
  p5.x=340;p5.y=300;
  glBegin(GL_LINE_LOOP);
    glVertex2i(p1.x,p1.y);
    glVertex2i(p2.x,p2.y);
    glVertex2i(p3.x,p3.y);
    glVertex2i(p4.x,p4.y);
    glVertex2i(p5.x,p5.y);
  glEnd();
  glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);    
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(	screen_width,screen_height);
  glutInitWindowPosition(0,0);
	glutCreateWindow("Pentagram");
    
  glutDisplayFunc(display);
  glutReshapeFunc (resize);
  init();
  glutMainLoop();
  return 0;    
}