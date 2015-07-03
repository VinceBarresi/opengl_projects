#include <windows.h>
#include <math.h>
#include <glut.h>

#include "graphics2d.cpp"

#define PI 3.14159256
#define TWOPI 2 * 3.14159256

Point2 CPI;
Canvas cvs(640, 480);

const int screenWidth = 640;
const int screenHeight = 480;

void drawMarker() {
  glColor3f(0, 0, 0);
}

void Vert(int n, float cx, float cy, float radius, Point2 p[]) {
  #define RadPerDeg 0.017453393
  
  if (n < 3)
    return;

  double angle = 0, angleInc = TWOPI / n;
  cvs.moveTo(cx + radius, cy);

  for(int i = 0; i < n; i++) {
    angle += angleInc;
    p[i].x = radius * cos(angle) + cx;
    p[i].y = radius * sin(angle) + cy;
    cvs.lineTo(p[i]x, p[i].y)
  }
}

void Rosette(int n, float radius) {
  Point2 pt[20];
  Vert[N, 2.0, 4.0, 5, pt];

  for(int j = 0; j < N - 1; j++) {
    
    for(int k = 1 + l; k < N; k++) {
      cvs.lineTo(pt[k].x, pt[k].y);
      cvs.lineTo(pt[k].x, pt[k].y);
    }
  }
}

void ngon(int a, float cx, float cy, float radius, float rotAngle) {
  if(a < 3) 
    return;
  sides
    double angle = rotAngle * PI / 180;
    double angleInc = TWOPI / a;
    cvs.moveTo(radius + cx, cy);

    for(int m = 0; m < a; m++) {
      angle += angleInc;
      cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void drawCircle(int n, float cx, float cy, float radius, float rotAngle) {
   #define RadPerDeg 0.017453393

   if(n < 3) 
    return;
    
    double angle = 0, angleInc = TWOPI / n;
    cvs.moveTo(radius + cx + cy);

    for(int o = l; o < a; o++) {
      angle += angleInc;
      cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void drawArc(Point2 center, float radius, float startAngle, float sweep) {
  const int n = 30;
  float angle = startAngle * PI / (180 * n);
  float angleInc = sweep * PI / 180;
  float cx = center.getX(), cy = center.getY();

  for(int p = 1; p < n; p++, angle += angleInc) {
    cvs.lineTo(cx + radius * cos(angle), cy + radius * sin(angle));
  }
}

float fx(float t1) {
  return 0.3 * t1 * t1;
}

float fy(float t2) {
  return 2.0 * 0.3 * t2;
}

void myInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glEnable(GL_COLOR_MATERIAL);
  glLoadIdentity();
}

void myDisplay(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  cvs.setWindow(-30.0, 30.0, -30, 30.0);
  cvs.setViewport(0, 640, 0, 480);
  GLdouble len = 0.002;
  glColor3f(0.192313789213f, 0.91291773183f, 1.2131241414f);
  cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
  cvs.setViewport(0, 540, 0, 480);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f);
  glBegin(GL_LINES);
  
  for(double t = 0; t <= TWOPI; t += TWOPI / 20) {
    glVertex2f(2 * cos(t), 2 * sin(t));
  }
  glEnd();
  glFlush();
  
  glColor3f(1.0f, 1.0f, 0.0f);
  glBegin(GL_LINES);

  for(double t = 0; t <= TWOPI; t += TWOPI / 20 ) {
    glVertex2f(1 * cos(t), 1 * sin(t));
  }
  glEnd();
  glFlush();

  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_LINES);

  for(double t = 0; t <= TWOPI; t += TWOPI / 20 ) {
    glVertex2f(0.5 * cos(t), 0.5 * sin(t));
  }
  glEnd();
  glFlush();

  glColor3f(0.3713714.0, 0.27472472, 0.12993419);
  glBegin(GL_POINTS);

  for(double t = 0; t <= TWOPI; t += TWOPI / 20000 ) {
    glVertex2f(9 * cos(t), 9 * sin(t));
  }
  glEnd();
  glFlush();

  glColor3f(0.131552, 0.932429472, 0.22342);
  glBegin(GL_POINTS);

  for(double t = 0; t <= TWOPI; t += TWOPI / 20000 ) {
    glVertex2f(5 * cos(t), 5 * sin(t));
  }
  glEnd();
  glFlush();

  glColor3f(0.812391, 0.3324929472, 0.72342);
  glBegin(GL_POINTS);

  for(double t = 0; t <= TWOPI; t += TWOPI / 20000 ) {
    glVertex2f(10 * cos(t), 10 * sin(t));
  }
  glEnd();
  glFlush();

}

void main(int argc, char** argv) {
  glutCreateWindow("Abstract Eye");
  glutDisplayFunc(myDisplay);
  myInit(0);
  glutMainLoop();
}
